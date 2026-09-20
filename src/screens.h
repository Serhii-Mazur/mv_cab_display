#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Screens

enum ScreensEnum {
    _SCREEN_ID_FIRST = 1,
    SCREEN_ID_SCR_LOAD = 1,
    SCREEN_ID_SCR_MAIN_SCHEMA = 2,
    _SCREEN_ID_LAST = 2
};

typedef struct _objects_t {
    lv_obj_t *scr_load;
    lv_obj_t *scr_main_schema;
    lv_obj_t *header;
    lv_obj_t *header_text;
    lv_obj_t *main;
    lv_obj_t *buss;
    lv_obj_t *bus;
    lv_obj_t *obj0;
    lv_obj_t *wire_0;
    lv_obj_t *f_contact_0;
    lv_obj_t *bdcs;
    lv_obj_t *disconnector_switch_0;
    lv_obj_t *wire_1;
    lv_obj_t *obj1;
    lv_obj_t *fvcb;
    lv_obj_t *vcb;
    lv_obj_t *wire_2;
    lv_obj_t *f_contact_1;
    lv_obj_t *ldsg;
    lv_obj_t *disconnector_switch_2;
    lv_obj_t *wire_3;
    lv_obj_t *wire_4_1;
    lv_obj_t *f_contact_2;
    lv_obj_t *grounding_switch_1;
    lv_obj_t *wire_4_2;
    lv_obj_t *mech_block;
    lv_obj_t *symb_load;
    lv_obj_t *gndh;
    lv_obj_t *footer;
    lv_obj_t *btn_settings;
    lv_obj_t *lbl_settings;
} objects_t;

extern objects_t objects;

void create_screen_scr_load();
void tick_screen_scr_load();

void create_screen_scr_main_schema();
void tick_screen_scr_main_schema();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/