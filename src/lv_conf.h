/*
 * Minimal LVGL v9 configuration for this project.
 * Adapted to match previous settings: 16-bit color, custom malloc, selected Montserrat fonts.
 */

#ifndef LV_CONF_H
#define LV_CONF_H

#include <stdint.h>

/* ---------- Color and memory ---------- */
#define LV_COLOR_DEPTH 16
/* #define LV_COLOR_16_SWAP 0 */
#define LV_COLOR_SCREEN_TRANSP 1
#define LV_COLOR_CHROMA_KEY lv_color_hex(0x00ff00)

/* Use custom malloc/free to integrate with the system allocator */
#define LV_MEM_CUSTOM 1
#if LV_MEM_CUSTOM
    #define LV_MEM_CUSTOM_INCLUDE <stdlib.h>
    #define LV_MEM_CUSTOM_ALLOC   malloc
    #define LV_MEM_CUSTOM_FREE    free
    #define LV_MEM_CUSTOM_REALLOC realloc
#else
    #define LV_MEM_SIZE (48U * 1024U)
#endif

/* ---------- Timing ---------- */
#define LV_TICK_CUSTOM 0
#if LV_TICK_CUSTOM
    #define LV_TICK_CUSTOM_INCLUDE "Arduino.h"
    #define LV_TICK_CUSTOM_SYS_TIME_EXPR (millis())
#endif

#define LV_DPI_DEF 130
#define LV_DISP_DEF_REFR_PERIOD 30
#define LV_INDEV_DEF_READ_PERIOD 30

/* ---------- Logging ---------- */
#define LV_USE_LOG 1
#if LV_USE_LOG
    #define LV_LOG_LEVEL LV_LOG_LEVEL_WARN
    #define LV_LOG_PRINTF 1
#endif

/* Disable perf monitor to avoid redefinition with internal headers */
#define LV_USE_PERF_MONITOR 0

/* Memory monitor */
#define LV_USE_MEM_MONITOR 0

/* ---------- Core features ---------- */
#define LV_USE_USER_DATA 1
#define LV_USE_OBJ_FREE_PTR 1
#define LV_ENABLE_GC 0

/* ---------- Graphics ---------- */
#define LV_DRAW_COMPLEX 1
#if LV_DRAW_COMPLEX
    #define LV_SHADOW_CACHE_SIZE 0
#endif

#define LV_LAYER_SIMPLE_BUF_SIZE (24 * 1024)
#define LV_LAYER_SIMPLE_FALLBACK_BUF_SIZE (3 * 1024)
#define LV_IMG_CACHE_DEF_SIZE 0
#define LV_GRADIENT_MAX_STOPS 2
#define LV_GRAD_CACHE_DEF_SIZE 0

/* ---------- Fonts (keep Montserrat set used by app) ---------- */
#define LV_FONT_MONTSERRAT_8  1
#define LV_FONT_MONTSERRAT_10 1
#define LV_FONT_MONTSERRAT_12 1
#define LV_FONT_MONTSERRAT_14 1
#define LV_FONT_MONTSERRAT_16 1
#define LV_FONT_MONTSERRAT_18 1
#define LV_FONT_MONTSERRAT_20 1
#define LV_FONT_MONTSERRAT_22 1
#define LV_FONT_MONTSERRAT_24 1
#define LV_FONT_MONTSERRAT_26 1
#define LV_FONT_MONTSERRAT_28 1
#define LV_FONT_MONTSERRAT_30 1
#define LV_FONT_MONTSERRAT_32 1
#define LV_FONT_MONTSERRAT_34 1
#define LV_FONT_MONTSERRAT_36 1
#define LV_FONT_MONTSERRAT_38 1
#define LV_FONT_MONTSERRAT_40 1
#define LV_FONT_MONTSERRAT_42 1
#define LV_FONT_MONTSERRAT_44 1
#define LV_FONT_MONTSERRAT_46 1
#define LV_FONT_MONTSERRAT_48 1

#define LV_FONT_DEFAULT &lv_font_montserrat_14

/* ---------- Text ---------- */
#define LV_TXT_ENC LV_TXT_ENC_UTF8
#define LV_TXT_BREAK_CHARS " ,.;:-_"

/* ---------- Misc ---------- */
/* Disable native Helium/ASM draw implementations for this target */
#ifndef LV_USE_DRAW_SW_ASM
#define LV_USE_DRAW_SW_ASM LV_DRAW_SW_ASM_NONE
#endif

#ifndef LV_USE_NATIVE_HELIUM_ASM
#define LV_USE_NATIVE_HELIUM_ASM 0
#endif

#define LV_USE_PERF_MONITOR 0

#endif /* LV_CONF_H */
