#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;

//
// Event handlers
//

lv_obj_t *tick_value_change_obj;

//
// Screens
//

void create_screen_scr_load() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.scr_load = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 800);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_spinner_create(parent_obj);
            lv_obj_set_pos(obj, 200, 360);
            lv_obj_set_size(obj, 80, 80);
        }
    }
    
    tick_screen_scr_load();
}

void tick_screen_scr_load() {
}

void create_screen_scr_main_schema() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.scr_main_schema = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 800);
    {
        lv_obj_t *parent_obj = obj;
        {
            // HEADER
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.header = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 70);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // header_text
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.header_text = obj;
                    lv_obj_set_pos(obj, 105, 15);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_38, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "BUS 1 . CELL 4");
                }
            }
        }
        {
            // MAIN
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.main = obj;
            lv_obj_set_pos(obj, 0, 70);
            lv_obj_set_size(obj, 480, 700);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // BUSS
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.buss = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 480, 105);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // bus
                            lv_obj_t *obj = lv_line_create(parent_obj);
                            objects.bus = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 480, 36);
                            static lv_point_precise_t line_points[] = {
                                { 5, 5 },
                                { 475, 5 },
                                { 475, 30 },
                                { 5, 30 },
                                { 5, 5 }
                            };
                            lv_line_set_points(obj, line_points, 5);
                            lv_obj_set_style_line_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_line_rounded(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                    objects.obj0 = obj;
                                    lv_obj_set_pos(obj, 200, 8);
                                    lv_obj_set_size(obj, 20, 20);
                                    lv_arc_set_value(obj, 100);
                                    lv_arc_set_bg_start_angle(obj, 0);
                                    lv_arc_set_bg_end_angle(obj, 360);
                                    lv_obj_set_style_arc_width(obj, 5, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_arc_color(obj, lv_color_hex(0xffffff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                                    lv_obj_set_style_arc_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
                                }
                            }
                        }
                        {
                            // wire_0
                            lv_obj_t *obj = lv_line_create(parent_obj);
                            objects.wire_0 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 480, 100);
                            static lv_point_precise_t line_points[] = {
                                { 210, 25 },
                                { 210, 100 }
                            };
                            lv_line_set_points(obj, line_points, 2);
                            lv_obj_set_style_line_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // f_contact_0
                            lv_obj_t *obj = lv_line_create(parent_obj);
                            objects.f_contact_0 = obj;
                            lv_obj_set_pos(obj, 0, 94);
                            lv_obj_set_size(obj, 480, 8);
                            static lv_point_precise_t line_points[] = {
                                { 205, 5 },
                                { 216, 5 }
                            };
                            lv_line_set_points(obj, line_points, 2);
                            lv_obj_set_style_line_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // BDCS
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.bdcs = obj;
                    lv_obj_set_pos(obj, 0, 94);
                    lv_obj_set_size(obj, 480, 150);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // disconnector_switch_0
                            lv_obj_t *obj = lv_line_create(parent_obj);
                            objects.disconnector_switch_0 = obj;
                            lv_obj_set_pos(obj, 0, 10);
                            lv_obj_set_size(obj, 480, 60);
                            static lv_point_precise_t line_points[] = {
                                { 170, 0 },
                                { 210, 60 }
                            };
                            lv_line_set_points(obj, line_points, 2);
                            lv_obj_set_style_line_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_line_rounded(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // wire_1
                            lv_obj_t *obj = lv_line_create(parent_obj);
                            objects.wire_1 = obj;
                            lv_obj_set_pos(obj, 0, 70);
                            lv_obj_set_size(obj, 480, 80);
                            static lv_point_precise_t line_points[] = {
                                { 210, 0 },
                                { 210, 80 }
                            };
                            lv_line_set_points(obj, line_points, 2);
                            lv_obj_set_style_line_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_line_rounded(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_arc_create(parent_obj);
                            objects.obj1 = obj;
                            lv_obj_set_pos(obj, 202, 60);
                            lv_obj_set_size(obj, 16, 16);
                            lv_arc_set_value(obj, 100);
                            lv_arc_set_bg_start_angle(obj, 0);
                            lv_arc_set_bg_end_angle(obj, 360);
                            lv_obj_set_style_arc_width(obj, 8, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                            lv_obj_set_style_arc_color(obj, lv_color_hex(0xffffff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                            lv_obj_set_style_arc_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // FVCB
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.fvcb = obj;
                    lv_obj_set_pos(obj, 0, 238);
                    lv_obj_set_size(obj, 480, 200);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // VCB
                            lv_obj_t *obj = lv_line_create(parent_obj);
                            objects.vcb = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 480, 110);
                            static lv_point_precise_t line_points[] = {
                                { 160, 5 },
                                { 260, 5 },
                                { 260, 105 },
                                { 160, 105 },
                                { 160, 5 }
                            };
                            lv_line_set_points(obj, line_points, 5);
                            lv_obj_set_style_line_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_line_rounded(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // wire_2
                            lv_obj_t *obj = lv_line_create(parent_obj);
                            objects.wire_2 = obj;
                            lv_obj_set_pos(obj, 0, 105);
                            lv_obj_set_size(obj, 480, 80);
                            static lv_point_precise_t line_points[] = {
                                { 210, 0 },
                                { 210, 80 }
                            };
                            lv_line_set_points(obj, line_points, 2);
                            lv_obj_set_style_line_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // f_contact_1
                            lv_obj_t *obj = lv_line_create(parent_obj);
                            objects.f_contact_1 = obj;
                            lv_obj_set_pos(obj, 0, 178);
                            lv_obj_set_size(obj, 480, 8);
                            static lv_point_precise_t line_points[] = {
                                { 205, 5 },
                                { 216, 5 }
                            };
                            lv_line_set_points(obj, line_points, 2);
                            lv_obj_set_style_line_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // LDSG
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.ldsg = obj;
                    lv_obj_set_pos(obj, 0, 416);
                    lv_obj_set_size(obj, 480, 284);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // disconnector_switch_2
                            lv_obj_t *obj = lv_line_create(parent_obj);
                            objects.disconnector_switch_2 = obj;
                            lv_obj_set_pos(obj, 0, 10);
                            lv_obj_set_size(obj, 480, 60);
                            static lv_point_precise_t line_points[] = {
                                { 170, 0 },
                                { 210, 60 }
                            };
                            lv_line_set_points(obj, line_points, 2);
                            lv_obj_set_style_line_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_line_rounded(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // wire_3
                            lv_obj_t *obj = lv_line_create(parent_obj);
                            objects.wire_3 = obj;
                            lv_obj_set_pos(obj, 0, 70);
                            lv_obj_set_size(obj, 480, 150);
                            static lv_point_precise_t line_points[] = {
                                { 210, 0 },
                                { 210, 150 }
                            };
                            lv_line_set_points(obj, line_points, 2);
                            lv_obj_set_style_line_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_line_rounded(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // wire_4_1
                            lv_obj_t *obj = lv_line_create(parent_obj);
                            objects.wire_4_1 = obj;
                            lv_obj_set_pos(obj, 0, 130);
                            lv_obj_set_size(obj, 480, 10);
                            static lv_point_precise_t line_points[] = {
                                { 210, 5 },
                                { 270, 5 }
                            };
                            lv_line_set_points(obj, line_points, 2);
                            lv_obj_set_style_line_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // f-contact_2
                            lv_obj_t *obj = lv_line_create(parent_obj);
                            objects.f_contact_2 = obj;
                            lv_obj_set_pos(obj, -5, 130);
                            lv_obj_set_size(obj, 480, 12);
                            static lv_point_precise_t line_points[] = {
                                { 275, 0 },
                                { 275, 11 }
                            };
                            lv_line_set_points(obj, line_points, 2);
                            lv_obj_set_style_line_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // grounding_switch_1
                            lv_obj_t *obj = lv_line_create(parent_obj);
                            objects.grounding_switch_1 = obj;
                            lv_obj_set_pos(obj, 0, 135);
                            lv_obj_set_size(obj, 480, 50);
                            static lv_point_precise_t line_points[] = {
                                { 280, 40 },
                                { 340, 0 }
                            };
                            lv_line_set_points(obj, line_points, 2);
                            lv_obj_set_style_line_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_line_rounded(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // wire_4_2
                            lv_obj_t *obj = lv_line_create(parent_obj);
                            objects.wire_4_2 = obj;
                            lv_obj_set_pos(obj, 0, 130);
                            lv_obj_set_size(obj, 480, 10);
                            static lv_point_precise_t line_points[] = {
                                { 340, 5 },
                                { 420, 5 }
                            };
                            lv_line_set_points(obj, line_points, 2);
                            lv_obj_set_style_line_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_line_rounded(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // mech_block
                            lv_obj_t *obj = lv_line_create(parent_obj);
                            objects.mech_block = obj;
                            lv_obj_set_pos(obj, 0, 7);
                            lv_obj_set_size(obj, 480, 153);
                            static lv_point_precise_t line_points[] = {
                                { 185, 25 },
                                { 300, 25 },
                                { 300, 155 }
                            };
                            lv_line_set_points(obj, line_points, 3);
                            lv_obj_set_style_line_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_line_dash_width(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_line_dash_gap(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // symb_load
                            lv_obj_t *obj = lv_line_create(parent_obj);
                            objects.symb_load = obj;
                            lv_obj_set_pos(obj, 0, 220);
                            lv_obj_set_size(obj, 480, 50);
                            static lv_point_precise_t line_points[] = {
                                { 210, 50 },
                                { 235, 0 },
                                { 185, 0 },
                                { 210, 50 }
                            };
                            lv_line_set_points(obj, line_points, 4);
                            lv_obj_set_style_line_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_line_rounded(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // GNDH
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.gndh = obj;
                            lv_obj_set_pos(obj, 416, 85);
                            lv_obj_set_size(obj, 50, 100);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_line_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 20);
                                    lv_obj_set_size(obj, 25, LV_SIZE_CONTENT);
                                    static lv_point_precise_t line_points[] = {
                                        { 5, 0 },
                                        { 5, 60 }
                                    };
                                    lv_line_set_points(obj, line_points, 2);
                                    lv_obj_set_style_line_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                                {
                                    lv_obj_t *obj = lv_line_create(parent_obj);
                                    lv_obj_set_pos(obj, 15, 30);
                                    lv_obj_set_size(obj, 25, LV_SIZE_CONTENT);
                                    static lv_point_precise_t line_points[] = {
                                        { 5, 0 },
                                        { 5, 40 }
                                    };
                                    lv_line_set_points(obj, line_points, 2);
                                    lv_obj_set_style_line_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                                {
                                    lv_obj_t *obj = lv_line_create(parent_obj);
                                    lv_obj_set_pos(obj, 30, 40);
                                    lv_obj_set_size(obj, 11, LV_SIZE_CONTENT);
                                    static lv_point_precise_t line_points[] = {
                                        { 5, 0 },
                                        { 5, 20 }
                                    };
                                    lv_line_set_points(obj, line_points, 2);
                                    lv_obj_set_style_line_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                    }
                }
            }
        }
        {
            // FOOTER
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.footer = obj;
            lv_obj_set_pos(obj, 0, 770);
            lv_obj_set_size(obj, 480, 30);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // btn_settings
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    objects.btn_settings = obj;
                    lv_obj_set_pos(obj, 400, 0);
                    lv_obj_set_size(obj, 75, 30);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x303030), LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // lbl_settings
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.lbl_settings = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(140), LV_PCT(200));
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text_static(obj, "Settings");
                        }
                    }
                }
            }
        }
    }
    
    tick_screen_scr_main_schema();
}

void tick_screen_scr_main_schema() {
}

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_scr_load,
    tick_screen_scr_main_schema,
};
void tick_screen(int screen_index) {
    if (screen_index >= 0 && screen_index < 2) {
        tick_screen_funcs[screen_index]();
    }
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen(screenId - 1);
}

//
// Fonts
//

ext_font_desc_t fonts[] = {
#if LV_FONT_MONTSERRAT_8
    { "MONTSERRAT_8", &lv_font_montserrat_8 },
#endif
#if LV_FONT_MONTSERRAT_10
    { "MONTSERRAT_10", &lv_font_montserrat_10 },
#endif
#if LV_FONT_MONTSERRAT_12
    { "MONTSERRAT_12", &lv_font_montserrat_12 },
#endif
#if LV_FONT_MONTSERRAT_14
    { "MONTSERRAT_14", &lv_font_montserrat_14 },
#endif
#if LV_FONT_MONTSERRAT_16
    { "MONTSERRAT_16", &lv_font_montserrat_16 },
#endif
#if LV_FONT_MONTSERRAT_18
    { "MONTSERRAT_18", &lv_font_montserrat_18 },
#endif
#if LV_FONT_MONTSERRAT_20
    { "MONTSERRAT_20", &lv_font_montserrat_20 },
#endif
#if LV_FONT_MONTSERRAT_22
    { "MONTSERRAT_22", &lv_font_montserrat_22 },
#endif
#if LV_FONT_MONTSERRAT_24
    { "MONTSERRAT_24", &lv_font_montserrat_24 },
#endif
#if LV_FONT_MONTSERRAT_26
    { "MONTSERRAT_26", &lv_font_montserrat_26 },
#endif
#if LV_FONT_MONTSERRAT_28
    { "MONTSERRAT_28", &lv_font_montserrat_28 },
#endif
#if LV_FONT_MONTSERRAT_30
    { "MONTSERRAT_30", &lv_font_montserrat_30 },
#endif
#if LV_FONT_MONTSERRAT_32
    { "MONTSERRAT_32", &lv_font_montserrat_32 },
#endif
#if LV_FONT_MONTSERRAT_34
    { "MONTSERRAT_34", &lv_font_montserrat_34 },
#endif
#if LV_FONT_MONTSERRAT_36
    { "MONTSERRAT_36", &lv_font_montserrat_36 },
#endif
#if LV_FONT_MONTSERRAT_38
    { "MONTSERRAT_38", &lv_font_montserrat_38 },
#endif
#if LV_FONT_MONTSERRAT_40
    { "MONTSERRAT_40", &lv_font_montserrat_40 },
#endif
#if LV_FONT_MONTSERRAT_42
    { "MONTSERRAT_42", &lv_font_montserrat_42 },
#endif
#if LV_FONT_MONTSERRAT_44
    { "MONTSERRAT_44", &lv_font_montserrat_44 },
#endif
#if LV_FONT_MONTSERRAT_46
    { "MONTSERRAT_46", &lv_font_montserrat_46 },
#endif
#if LV_FONT_MONTSERRAT_48
    { "MONTSERRAT_48", &lv_font_montserrat_48 },
#endif
};

//
// Color themes
//

uint32_t active_theme_index = 0;

//
//
//

void create_screens() {

// Set default LVGL theme
    lv_display_t *dispp = lv_display_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_display_set_theme(dispp, theme);
    
    // Initialize screens
    // Create screens
    create_screen_scr_load();
    create_screen_scr_main_schema();
}