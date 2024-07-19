#include "../inc/dialog_switch_mode.h"


static lv_obj_t *label_oil;
static lv_obj_t *label_hour;

static void event_cb(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_current_target(e);
    LV_UNUSED(obj);
}

lv_obj_t *xlv_msgbox_swtich_mode_create(void)
{


    return NULL;
}


void xlv_msgbox_switch_mode_set( uint16_t hour, uint16_t oil )
{    
    if ( label_oil )
    {
        lv_label_set_text_fmt( label_oil, "%d", oil );
    }
    if ( label_hour )
    {
        lv_label_set_text_fmt( label_hour, "%d", hour );
    }

}