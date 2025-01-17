#ifndef __WORKING_WIDGET_H__
#define __WORKING_WIDGET_H__
#include "irc_lcd_header.h"
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

lv_obj_t * working_widget_init();
void * working_widget_refresh(void *data);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
