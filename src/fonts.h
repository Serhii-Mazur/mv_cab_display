// Minimal stub for fonts.h
#ifndef FONTS_H
#define FONTS_H

#include <lvgl.h>

typedef struct {
    const char *name;
    const lv_font_t *font;
} ext_font_desc_t;

// Forward declarations for montserrat fonts used by generated screens
extern const lv_font_t lv_font_montserrat_8;
extern const lv_font_t lv_font_montserrat_10;
extern const lv_font_t lv_font_montserrat_12;
extern const lv_font_t lv_font_montserrat_14;
extern const lv_font_t lv_font_montserrat_16;
extern const lv_font_t lv_font_montserrat_18;
extern const lv_font_t lv_font_montserrat_20;
extern const lv_font_t lv_font_montserrat_22;
extern const lv_font_t lv_font_montserrat_24;
extern const lv_font_t lv_font_montserrat_26;
extern const lv_font_t lv_font_montserrat_28;
extern const lv_font_t lv_font_montserrat_30;
extern const lv_font_t lv_font_montserrat_32;
extern const lv_font_t lv_font_montserrat_34;
extern const lv_font_t lv_font_montserrat_36;
extern const lv_font_t lv_font_montserrat_38;
extern const lv_font_t lv_font_montserrat_40;
extern const lv_font_t lv_font_montserrat_42;
extern const lv_font_t lv_font_montserrat_44;
extern const lv_font_t lv_font_montserrat_46;
extern const lv_font_t lv_font_montserrat_48;

#endif // FONTS_H
