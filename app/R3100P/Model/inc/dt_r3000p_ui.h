#ifndef _DT_R3000P_UI_H_
#define _DT_R3000P_UI_H_

#include "data_info_v4_0.h"


typedef struct 
{
        //system_paras_t paras;
        rc_lcd_input_data_t dt_work;
        rc_lcd_fact_input_data_t dt_factory;
        rc_lcd_off_charging_input_data_t dt_charging;
        rc_lcd_preparation_input_data_t dt_preparation;

}dt_ui_t;


#endif
