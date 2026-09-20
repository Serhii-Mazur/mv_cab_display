/*
 * Minimal LVGL v9 port implementation (v9-only).
 * - Initializes LVGL (`lv_init()`)
 * - Registers a simple display driver with a noop flush callback
 * - Creates an esp timer for `lv_tick_inc()` and a FreeRTOS task to run `lv_timer_handler()`
 * - Provides mutex-based lock/unlock for LVGL API calls
 */

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_timer.h"
#include "esp_lib_utils.h"
#include "lvgl_v9_port.h"

using namespace esp_panel::drivers;

static SemaphoreHandle_t lvgl_mux = nullptr;
static TaskHandle_t lvgl_task_handle = nullptr;
static esp_timer_handle_t lvgl_tick_timer = NULL;
static lv_indev_t *lvgl_indev = nullptr;

static void lvgl_timer_task(void *arg)
{
    (void)arg;
    while (1) {
        lv_timer_handler();
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

static void lv_tick_cb(void *arg)
{
    (void)arg;
    lv_tick_inc(LVGL_PORT_TICK_PERIOD_MS);
}

static void lvgl_flush_cb(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map)
{
    esp_panel::drivers::LCD *lcd = (esp_panel::drivers::LCD *)lv_display_get_driver_data(disp);
    if (lcd && area && px_map) {
        int x = area->x1;
        int y = area->y1;
        int w = lv_area_get_width(area);
        int h = lv_area_get_height(area);
        lcd->drawBitmap(x, y, w, h, px_map, -1);
    }
    lv_display_flush_ready(disp);
}

static void lvgl_touch_read_cb(lv_indev_t *indev, lv_indev_data_t *data)
{
    esp_panel::drivers::Touch *touch = (esp_panel::drivers::Touch *)lv_indev_get_driver_data(indev);
    if (!touch) {
        data->state = LV_INDEV_STATE_RELEASED;
        data->continue_reading = false;
        return;
    }

    esp_panel::drivers::TouchPoint points[1];
    int count = touch->readPoints(points, 1);
    if (count > 0) {
        data->state = LV_INDEV_STATE_PRESSED;
        data->point.x = points[0].x;
        data->point.y = points[0].y;
    } else {
        data->state = LV_INDEV_STATE_RELEASED;
    }
    data->continue_reading = false;
}

bool lvgl_v9_port_init(esp_panel::drivers::LCD *lcd, esp_panel::drivers::Touch *tp)
{

    if (lvgl_mux == nullptr) {
        lvgl_mux = xSemaphoreCreateMutex();
        if (!lvgl_mux) return false;
    }

    lv_init();

    /* Create a draw buffer using the panel resolution, taking swapXY into account */
    int hor_res = 240;
    int ver_res = 240;
    if (lcd) {
        if (lcd->getTransformation().swap_xy) {
            hor_res = lcd->getFrameHeight();
            ver_res = lcd->getFrameWidth();
        } else {
            hor_res = lcd->getFrameWidth();
            ver_res = lcd->getFrameHeight();
        }
    }

    /* Allocate a simple partial buffer (RGB565 assumed by LV_CONF) */
    int buf_h = (LVGL_PORT_BUFFER_SIZE_HEIGHT > 0) ? LVGL_PORT_BUFFER_SIZE_HEIGHT : 10;
    uint32_t buf_size = (uint32_t)hor_res * (uint32_t)buf_h * 2; /* 2 bytes per pixel for RGB565 */
    void *buf1 = malloc(buf_size);
    if (!buf1) return false;

    /* Create LVGL display and assign buffers (v9 API) */
    lv_display_t *disp = lv_display_create(hor_res, ver_res);
    if (!disp) {
        free(buf1);
        return false;
    }

    lv_display_set_color_format(disp, LV_COLOR_FORMAT_RGB565);
    lv_display_set_buffers(disp, buf1, NULL, buf_size, LV_DISPLAY_RENDER_MODE_PARTIAL);
    lv_display_set_flush_cb(disp, lvgl_flush_cb);
    lv_display_set_default(disp);
    lv_display_set_driver_data(disp, lcd);

    Serial.printf("Display init: h_res=%d v_res=%d\n", lv_display_get_horizontal_resolution(disp), lv_display_get_vertical_resolution(disp));

    if (tp) {
        lvgl_indev = lv_indev_create();
        if (lvgl_indev) {
            lv_indev_set_type(lvgl_indev, LV_INDEV_TYPE_POINTER);
            lv_indev_set_read_cb(lvgl_indev, lvgl_touch_read_cb);
            lv_indev_set_driver_data(lvgl_indev, tp);
            lv_indev_set_display(lvgl_indev, disp);
        }
    }

    /* Start LVGL tick timer */
    esp_timer_create_args_t args = {};
    args.callback = &lv_tick_cb;
    args.arg = NULL;
    args.name = "lv_tick";
    if (esp_timer_create(&args, &lvgl_tick_timer) == ESP_OK) {
        esp_timer_start_periodic(lvgl_tick_timer, LVGL_PORT_TICK_PERIOD_MS * 1000);
    }

    /* Start LVGL handler task */
    if (lvgl_task_handle == NULL) {
        xTaskCreatePinnedToCore(lvgl_timer_task, "lv_timer", LVGL_PORT_TASK_STACK_SIZE / sizeof(StackType_t), NULL, LVGL_PORT_TASK_PRIORITY, &lvgl_task_handle, LVGL_PORT_TASK_CORE);
    }

    return true;
}

bool lvgl_v9_port_deinit(void)
{
    if (lvgl_task_handle) {
        vTaskDelete(lvgl_task_handle);
        lvgl_task_handle = NULL;
    }
    if (lvgl_tick_timer) {
        esp_timer_stop(lvgl_tick_timer);
        esp_timer_delete(lvgl_tick_timer);
        lvgl_tick_timer = NULL;
    }
    if (lvgl_indev) {
        lv_indev_delete(lvgl_indev);
        lvgl_indev = NULL;
    }
    if (lvgl_mux) {
        vSemaphoreDelete(lvgl_mux);
        lvgl_mux = NULL;
    }
    return true;
}

bool lvgl_v9_port_lock(int timeout_ms)
{
    if (!lvgl_mux) return false;
    TickType_t ticks = (timeout_ms < 0) ? portMAX_DELAY : pdMS_TO_TICKS(timeout_ms);
    return xSemaphoreTake(lvgl_mux, ticks) == pdTRUE;
}

bool lvgl_v9_port_unlock(void)
{
    if (!lvgl_mux) return false;
    return xSemaphoreGive(lvgl_mux) == pdTRUE;
}
