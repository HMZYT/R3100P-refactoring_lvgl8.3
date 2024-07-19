#include "../inc/dialog_keys_wrong.h"


static void event_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_current_target(e);
    LV_UNUSED(obj);

}

lv_obj_t *xlv_msgbox_keys_wrong_create( void )
{
    // static lv_style_t style;
    // lv_style_init(&style);
    // lv_style_set_border_width(&style, 4);
    // lv_style_set_border_color( &style, lv_color_make(238, 0, 2) );
    // lv_style_set_border_opa( &style, LV_OPA_COVER );
    // lv_style_set_border_side( &style, LV_BORDER_SIDE_FULL );
    // lv_style_set_bg_color( &style, lv_color_make(72,0,0));
    // lv_style_set_bg_opa(&style, LV_OPA_COVER);
    // lv_style_set_text_font(&style, &working_mode_24px);
    // lv_style_set_text_color(&style, lv_color_make(255,0,0));

    // static const char * btns[] = {"确定"};
    // //lv_obj_t *mbox = lv_msgbox_create( NULL, NULL, /*"按键未归零！"*/"KEYS_WRONG", btns, false );
    // lv_obj_t *mbox = lv_msgbox_create( NULL);
    // lv_obj_add_event_cb(mbox, event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    // lv_obj_center(mbox);
    // lv_obj_set_size(mbox, 637, 322);
    // lv_obj_add_style(mbox, &style, 0);
    // lv_obj_t *content = lv_msgbox_get_content(mbox);
    // lv_obj_center( content );

    // return mbox;
}