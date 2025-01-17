//
// Created by wpl on 2024/4/24.
//

#include "../inc/PageManage.h"
#include "../../UI/inc/working_page_home.h"
#include "../inc/sysparas_defs.h"
#include "../../User/inc/UiRun.h"
#include "../../theme/inc/theme_R1100P_white.h"

PageManage::PageManage()
= default;

PageManage::~PageManage()
= default;

PageManage *PageManage::GetInstance()
{
    static PageManage* pageManger = nullptr;
    if( !pageManger )
    {
        pageManger =  new PageManage();
    }

    return pageManger;
}

void PageManage::page_manage_add_page(PAGE* page, int id, lv_obj_t* (*init)(lv_obj_t* page), void* (*refresh)(void* data))
{
    page->pageID = id;
    page->init = init;
    page->refresh = refresh;
    pageList.push_back(page);
}

void PageManage::page_manage_init_pages(lv_obj_t *iPage)
{
    for (auto temp : pageList)
    {
        lv_obj_t * tempObj = temp->init(iPage);
        if (temp->pageID != 0)
        {
            lv_obj_add_flag(tempObj, LV_OBJ_FLAG_HIDDEN);
        }
        pageListInit.push_back(tempObj);
    }

    curr_page = pageListInit[working_page_home];
}

void PageManage::page_manage_switch_page(int id, void* data)
{
    lv_obj_add_flag(curr_page, LV_OBJ_FLAG_HIDDEN);
    if (id < page_end_flag)
    {
        lv_obj_t * tempObj = pageListInit[id];
        lv_obj_clear_flag(tempObj, LV_OBJ_FLAG_HIDDEN);
        curr_page = pageListInit[id];
    }

    if (data == NULL)
    {
        return;
    }

    for (auto temp : pageList)
    {
        if (id < page_end_flag)
        {
            temp->refresh(data);
        }
    }
}

