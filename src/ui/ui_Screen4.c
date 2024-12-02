// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 9.1.0
// Project name: DenonESPD

#include "ui.h"

void ui_Screen4_screen_init(void)
{
    ui_Screen4 = lv_obj_create(NULL);
    lv_obj_remove_flag(ui_Screen4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_TabView4 = lv_tabview_create(ui_Screen4);
    lv_tabview_set_tab_bar_size(ui_TabView4, 25);
    lv_obj_set_width(ui_TabView4, 320);
    lv_obj_set_height(ui_TabView4, 240);
    lv_obj_set_align(ui_TabView4, LV_ALIGN_CENTER);
    lv_obj_remove_flag(ui_TabView4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_set_style_bg_color(lv_tabview_get_tab_bar(ui_TabView4), lv_color_hex(0x66676A),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(lv_tabview_get_tab_bar(ui_TabView4), 255,  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(lv_tabview_get_tab_bar(ui_TabView4), lv_color_hex(0x19171A),
                                   LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(lv_tabview_get_tab_bar(ui_TabView4), 0,  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(lv_tabview_get_tab_bar(ui_TabView4), 255,  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(lv_tabview_get_tab_bar(ui_TabView4), LV_GRAD_DIR_VER,  LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel3 = lv_obj_create(ui_Screen4);
    lv_obj_set_width(ui_Panel3, 320);
    lv_obj_set_height(ui_Panel3, 83);
    lv_obj_set_x(ui_Panel3, 0);
    lv_obj_set_y(ui_Panel3, -50);
    lv_obj_set_align(ui_Panel3, LV_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Panel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_bootLbl1 = lv_label_create(ui_Screen4);
    lv_obj_set_width(ui_bootLbl1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_bootLbl1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_bootLbl1, 0);
    lv_obj_set_y(ui_bootLbl1, 3);
    lv_obj_set_align(ui_bootLbl1, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_bootLbl1, "Connect to WiFi");

    ui_scanWifi = lv_button_create(ui_Screen4);
    lv_obj_set_width(ui_scanWifi, 65);
    lv_obj_set_height(ui_scanWifi, 34);
    lv_obj_set_x(ui_scanWifi, -119);
    lv_obj_set_y(ui_scanWifi, -69);
    lv_obj_set_align(ui_scanWifi, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_scanWifi, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_scanWifi, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_scanWifi, lv_color_hex(0xFFFF00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_scanWifi, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_scanWifi, lv_color_hex(0x595500), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_scanWifi, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_scanLbl = lv_label_create(ui_Screen4);
    lv_obj_set_width(ui_scanLbl, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_scanLbl, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_scanLbl, -118);
    lv_obj_set_y(ui_scanLbl, -69);
    lv_obj_set_align(ui_scanLbl, LV_ALIGN_CENTER);
    lv_label_set_text(ui_scanLbl, "Scan");
    lv_obj_set_style_text_color(ui_scanLbl, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_scanLbl, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_passTxtbox = lv_textarea_create(ui_Screen4);
    lv_obj_set_width(ui_passTxtbox, 199);
    lv_obj_set_height(ui_passTxtbox, 36);
    lv_obj_set_x(ui_passTxtbox, 36);
    lv_obj_set_y(ui_passTxtbox, -29);
    lv_obj_set_align(ui_passTxtbox, LV_ALIGN_CENTER);
    lv_textarea_set_placeholder_text(ui_passTxtbox, "Password");



    ui_ssidDrop = lv_dropdown_create(ui_Screen4);
    lv_dropdown_set_options(ui_ssidDrop, "SSID");
    lv_obj_set_width(ui_ssidDrop, 200);
    lv_obj_set_height(ui_ssidDrop, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ssidDrop, 37);
    lv_obj_set_y(ui_ssidDrop, -68);
    lv_obj_set_align(ui_ssidDrop, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ssidDrop, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags



    ui_Keyboard1 = lv_keyboard_create(ui_Screen4);
    lv_obj_set_width(ui_Keyboard1, 312);
    lv_obj_set_height(ui_Keyboard1, 120);
    lv_obj_set_x(ui_Keyboard1, 0);
    lv_obj_set_y(ui_Keyboard1, 56);
    lv_obj_set_align(ui_Keyboard1, LV_ALIGN_CENTER);

    ui_connectBtn = lv_button_create(ui_Screen4);
    lv_obj_set_width(ui_connectBtn, 65);
    lv_obj_set_height(ui_connectBtn, 34);
    lv_obj_set_x(ui_connectBtn, -119);
    lv_obj_set_y(ui_connectBtn, -28);
    lv_obj_set_align(ui_connectBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_connectBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_connectBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_connectBtn, lv_color_hex(0xFFFF00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_connectBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_connectBtn, lv_color_hex(0x595500), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_connectBtn, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_connectLbl = lv_label_create(ui_Screen4);
    lv_obj_set_width(ui_connectLbl, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_connectLbl, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_connectLbl, -119);
    lv_obj_set_y(ui_connectLbl, -28);
    lv_obj_set_align(ui_connectLbl, LV_ALIGN_CENTER);
    lv_label_set_text(ui_connectLbl, "Connect");
    lv_obj_set_style_text_color(ui_connectLbl, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_connectLbl, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_scanWifi, ui_event_scanWifi, LV_EVENT_ALL, NULL);
    lv_keyboard_set_textarea(ui_Keyboard1, ui_passTxtbox);
    lv_obj_add_event_cb(ui_connectBtn, ui_event_connectBtn, LV_EVENT_ALL, NULL);

}
