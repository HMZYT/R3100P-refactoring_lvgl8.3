//
// Created by wpl on 2024/4/25.
//
#include "../inc/UiRun.h"
#include "../inc/ModeManage.h"
#include "../../UI/inc/working_page_antipping.h"
#include "../../UI/inc/working_page_home.h"
#include "../../UI/inc/working_page_faults.h"
#include "../../UI/inc/working_page_rc.h"
#include "../../UI/inc/working_page_note.h"
#include "../../UI/inc/working_page_light.h"
#include "../../UI/inc/working_page_setting.h"
#include "../../UI/inc/working_page_arms.h"
#include "../../UI/inc/idle_page_black.h"
#include "../../UI/inc/fact_page_version.h"
#include "../../UI/inc/fact_page_align.h"
#include "../../UI/inc/fact_page_align_displacement.h"
#include "../../UI/inc/fact_page_full_color.h"
#include "../../UI/inc/fact_page_touch.h"
#include "../../UI/inc/off_charging_page_charging.h"
#include "../../UI/inc/prepared_page_rc.h"
#include "../../../Model/inc/DtR1100PUi.h"
#include "../inc/sysparas_defs.h"
#include "../res/fonts/language_control.h"

void uiRun()
{
    irc_lcd_widget_t idle_widget;
    irc_lcd_widget_t factory_widget;
    irc_lcd_widget_t offChargint_widget;
    irc_lcd_widget_t prepared_widget;
    irc_lcd_widget_t* working_widget = new irc_lcd_widget_t;
    ModeManage* modeManage = ModeManage::GetInstance();
    modeManage->mode_manage_add_widget(working_widget, working_widget_init, working_widget_refresh);
//    modeManage.mode_manage_add_widget(&factory_widget, rc_lcd_factory_widget_init);
//    modeManage.mode_manage_add_widget(&offChargint_widget, rc_lcd_off_charging_widget_init);
//    modeManage.mode_manage_add_widget(&prepared_widget, prepared_widget_init);

    PAGE* working_home_page = new PAGE;
    PAGE* working_antipping_page = new PAGE;
    PAGE* working_faults_page = new PAGE;
    PAGE* working_rc_page = new PAGE;
    PAGE* working_note_page = new PAGE;
    PAGE* working_setting_page = new PAGE;
    //PAGE* working_light_page = new PAGE;
    PAGE* working_arm_page = new PAGE;
    PAGE* idle_black_page = new PAGE;
    PAGE* fact_version_page = new PAGE;
    PAGE* fact_algin_page = new PAGE;
    PAGE* fact_algin_displacement_page = new PAGE;
    PAGE* fact_page_full_color_page = new PAGE;
    PAGE* fact_page_touch_page = new PAGE;
    PAGE* off_charging_page = new PAGE;
    PAGE* prepared_page = new PAGE;
    PageManage* pageManage =  PageManage::GetInstance();
    pageManage->page_manage_add_page(working_home_page, working_page_home, working_page_home_init, home_refresh);
    pageManage->page_manage_add_page(working_rc_page, working_page_rc, working_page_rc_init,rc_refresh);
    pageManage->page_manage_add_page(working_antipping_page, working_page_antipping, working_page_antipping_init,anti_refresh);
    pageManage->page_manage_add_page(working_arm_page, working_page_arm, working_page_arms_init,arms_refresh);
    pageManage->page_manage_add_page(working_note_page, working_page_note, working_page_note_init,note_refresh);
    pageManage->page_manage_add_page(working_setting_page, working_page_setting, working_page_setting_init,settings_refresh);
    pageManage->page_manage_add_page(working_faults_page, working_page_faults, working_page_faults_init,faults_refresh);

//    pageManage.page_manage_add_page(idle_black_page, idle_page_black, idle_page_black_init);
//    pageManage.page_manage_add_page(fact_version_page, fact_page_version, fact_page_version_init);
//    pageManage.page_manage_add_page(fact_algin_page, fact_page_algin, fact_page_algin_init);
//    pageManage.page_manage_add_page(fact_algin_displacement_page, fact_page_algin_displacement, fact_page_algin_displacement_init);
//    pageManage.page_manage_add_page(fact_page_full_color_page, fact_page_full_color, fact_page_full_color_init);
//    pageManage.page_manage_add_page(fact_page_touch_page, fact_page_touch, fact_page_touch_init);
//    pageManage.page_manage_add_page(off_charging_page, off_charging_page_charging, off_charging_page_charging_init);
//    pageManage.page_manage_add_page(prepared_page, prepared_page_rc, prepared_page_rc_create);

    modeManage->mode_manage_init_widgets();
    lv_obj_t* tempWidget = modeManage->mode_manage_switch_widget(e_rc_lcd_working, NULL);
    pageManage->page_manage_init_pages(tempWidget);
    pageManage->page_manage_switch_page(working_page_rc, NULL);
}

void ui_data_update(void)
{
    PageManage* pageManager =  PageManage::GetInstance();
    //pageManager->page_manage_switch_page(dt_ui.paras.page_idx,&dt_ui);
}