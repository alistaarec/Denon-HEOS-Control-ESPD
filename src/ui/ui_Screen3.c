// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 9.1.0
// Project name: DenonESPD

#include "ui.h"

void ui_Screen3_screen_init(void)
{
    ui_Screen3 = lv_obj_create(NULL);
    lv_obj_remove_flag(ui_Screen3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_TabView3 = lv_tabview_create(ui_Screen3);
    lv_tabview_set_tab_bar_size(ui_TabView3, 25);
    lv_obj_set_width(ui_TabView3, 320);
    lv_obj_set_height(ui_TabView3, 240);
    lv_obj_set_align(ui_TabView3, LV_ALIGN_CENTER);
    lv_obj_remove_flag(ui_TabView3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_set_style_bg_color(lv_tabview_get_tab_bar(ui_TabView3), lv_color_hex(0x66676A),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(lv_tabview_get_tab_bar(ui_TabView3), 255,  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(lv_tabview_get_tab_bar(ui_TabView3), lv_color_hex(0x19171A),
                                   LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(lv_tabview_get_tab_bar(ui_TabView3), 0,  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(lv_tabview_get_tab_bar(ui_TabView3), 255,  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(lv_tabview_get_tab_bar(ui_TabView3), LV_GRAD_DIR_VER,  LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel1 = lv_obj_create(ui_Screen3);
    lv_obj_set_width(ui_Panel1, 320);
    lv_obj_set_height(ui_Panel1, 136);
    lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_bootLbl = lv_label_create(ui_Screen3);
    lv_obj_set_width(ui_bootLbl, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_bootLbl, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_bootLbl, 0);
    lv_obj_set_y(ui_bootLbl, 3);
    lv_obj_set_align(ui_bootLbl, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_bootLbl, "Booting...");

    ui_sdLbl = lv_label_create(ui_Screen3);
    lv_obj_set_width(ui_sdLbl, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_sdLbl, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_sdLbl, 20);
    lv_obj_set_y(ui_sdLbl, 59);
    lv_label_set_text(ui_sdLbl, "...");

    ui_wifLoadLbl = lv_label_create(ui_Screen3);
    lv_obj_set_width(ui_wifLoadLbl, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_wifLoadLbl, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_wifLoadLbl, 20);
    lv_obj_set_y(ui_wifLoadLbl, 117);
    lv_label_set_text(ui_wifLoadLbl, "...");

    ui_wifConLbl = lv_label_create(ui_Screen3);
    lv_obj_set_width(ui_wifConLbl, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_wifConLbl, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_wifConLbl, 20);
    lv_obj_set_y(ui_wifConLbl, 136);
    lv_label_set_text(ui_wifConLbl, "...");

    ui_heosLbl = lv_label_create(ui_Screen3);
    lv_obj_set_width(ui_heosLbl, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_heosLbl, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_heosLbl, 20);
    lv_obj_set_y(ui_heosLbl, 155);
    lv_label_set_text(ui_heosLbl, "...");

    ui_calLoadLbl = lv_label_create(ui_Screen3);
    lv_obj_set_width(ui_calLoadLbl, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_calLoadLbl, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_calLoadLbl, 20);
    lv_obj_set_y(ui_calLoadLbl, 79);
    lv_label_set_text(ui_calLoadLbl, "...");

    ui_settingsLoadLbl = lv_label_create(ui_Screen3);
    lv_obj_set_width(ui_settingsLoadLbl, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_settingsLoadLbl, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_settingsLoadLbl, 20);
    lv_obj_set_y(ui_settingsLoadLbl, 98);
    lv_label_set_text(ui_settingsLoadLbl, "...");


}