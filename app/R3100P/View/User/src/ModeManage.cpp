#include "../inc/ModeManage.h"
#include "../../UI/inc/working_page_home.h"
#include "../../UI/inc/working_page_antipping.h"

ModeManage::ModeManage()
= default;

ModeManage::~ModeManage()
= default;

ModeManage *ModeManage::GetInstance()
{
    static ModeManage* modeManger = nullptr;
    if( !modeManger )
    {
        modeManger =  new ModeManage();
    }

    return modeManger;
}

void ModeManage::mode_manage_add_widget(irc_lcd_widget_t *modeWidget,lv_obj_t* (*init)(), void* (*refresh)(void* data))
{
    modeWidget->init = init;
    modeWidget->refresh = refresh;
    widgetsList.push_back(modeWidget);
}

void ModeManage::mode_manage_init_widgets()
{
    for (auto temp : widgetsList)
    {
        lv_obj_t * tempObj = temp->init();
        lv_obj_add_flag(tempObj, LV_OBJ_FLAG_HIDDEN);
        widgetsListInit.push_back(tempObj);
    }
    lv_obj_clear_flag(widgetsListInit[0], LV_OBJ_FLAG_HIDDEN);
    currentModeWidget = widgetsListInit[0];
}

lv_obj_t* ModeManage::mode_manage_switch_widget(int modeIndex, void* data)
{
    lv_obj_add_flag(currentModeWidget, LV_OBJ_FLAG_HIDDEN);
    if (modeIndex < e_rc_lcd_flag_end)
    {
        lv_obj_t * tempObj = widgetsListInit[modeIndex];
        lv_obj_clear_flag(tempObj, LV_OBJ_FLAG_HIDDEN);
        currentModeWidget = tempObj;
    }

        for (auto temp : widgetsList)
        {
            if (modeIndex < e_rc_lcd_flag_end)
            {
                temp->refresh(data);
            }
        }

    return currentModeWidget;
}