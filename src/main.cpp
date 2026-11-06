/*
 * SPDX-FileCopyrightText: 2024-2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <Arduino.h>
#include <esp_display_panel.hpp>
#include <lvgl.h>
#include "lvgl_v9_port.h"
#include "screens.h"

/**
/* To use the built-in examples and demos of LVGL uncomment the includes below respectively.
 * You also need to copy `lvgl/examples` to `lvgl/src/examples`. Similarly for the demos `lvgl/demos` to `lvgl/src/demos`.
 */
// #include <demos/lv_demos.h>
// #include <examples/lv_examples.h>

using namespace esp_panel::drivers;
using namespace esp_panel::board;

static constexpr uint8_t inputs[] = {10, 11, 12, 13, 17};

static void button_event_cb(lv_event_t *e)
{
    lv_obj_t *label = (lv_obj_t *)lv_event_get_user_data(e);
    static int press_count = 0;
    press_count++;
    lv_label_set_text_fmt(label, "Pressed: %d", press_count);
}
// Non-blocking screen switch state
static unsigned long screen_switch_time = 0;
static bool screen_switched = false;

void setup()
{
    Serial.begin(115200);

    for (uint8_t pin : inputs) {
        pinMode(pin, INPUT_PULLUP);
    }

    Serial.println("Initializing board");
    Board *board = new Board();
    board->init();
#if LVGL_PORT_AVOID_TEARING_MODE
    auto lcd = board->getLCD();
    // When avoid tearing function is enabled, the frame buffer number should be set in the board driver
    lcd->configFrameBufferNumber(LVGL_PORT_DISP_BUFFER_NUM);
#if ESP_PANEL_DRIVERS_BUS_ENABLE_RGB && CONFIG_IDF_TARGET_ESP32S3
    auto lcd_bus = lcd->getBus();
    /**
     * As the anti-tearing feature typically consumes more PSRAM bandwidth, for the ESP32-S3, we need to utilize the
     * "bounce buffer" functionality to enhance the RGB data bandwidth.
     * This feature will consume `bounce_buffer_size * bytes_per_pixel * 2` of SRAM memory.
     */
    if (lcd_bus->getBasicAttributes().type == ESP_PANEL_BUS_TYPE_RGB) {
        static_cast<BusRGB *>(lcd_bus)->configRGB_BounceBufferSize(lcd->getFrameWidth() * 10);
    }
#endif
#endif
    assert(board->begin());

    auto lcd = board->getLCD();
    auto tp = board->getTouch();
    if (lcd) {
        lcd->swapXY(true);
        lcd->mirrorY(true);
        auto t = lcd->getTransformation();
        Serial.printf("LCD transform: swap=%d mirrorX=%d mirrorY=%d\n", t.swap_xy, t.mirror_x, t.mirror_y);
    }
    Serial.printf("Touch object: %p\n", (void *)tp);
    if (tp) {
        tp->swapXY(true);
        tp->mirrorY(true);
        auto tt = tp->getTransformation();
        Serial.printf("Touch transform: swap=%d mirrorX=%d mirrorY=%d\n", tt.swap_xy, tt.mirror_x, tt.mirror_y);
    }

    Serial.println("Initializing LVGL");
    lvgl_v9_port_init(lcd, tp);

    Serial.println("Creating UI");
    /* Lock the mutex due to the LVGL APIs are not thread-safe */
    lvgl_v9_port_lock(-1);
    /* Create screens and show initial load screen, then schedule switch */
    create_screens();
    /* Show loading screen */
    lv_scr_load(objects.scr_load);
    /* Record time to switch screens later from loop() without blocking */
    screen_switch_time = millis();

    /**
     * Try an example. Don't forget to uncomment header.
     * See all the examples online: https://docs.lvgl.io/master/examples.html
     * source codes: https://github.com/lvgl/lvgl/tree/e7f88efa5853128bf871dde335c0ca8da9eb7731/examples
     */
    //  lv_example_btn_1();

    /**
     * Or try out a demo.
     * Don't forget to uncomment header and enable the demos in `lv_conf.h`. E.g. `LV_USE_DEMO_WIDGETS`
     */
    // lv_demo_widgets();
    // lv_demo_benchmark();
    // lv_demo_music();
    // lv_demo_stress();

    /* Release the mutex */
    lvgl_v9_port_unlock();
}

void loop()
{
    if (!screen_switched && millis() - screen_switch_time >= 3000) {
        if (lvgl_v9_port_lock(-1)) {
            lv_scr_load(objects.scr_main_schema);
            lvgl_v9_port_unlock();
            screen_switched = true;
        }
    }

    Serial.println("IDLE loop");
    delay(1000);
}
