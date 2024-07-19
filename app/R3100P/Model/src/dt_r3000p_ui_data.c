#include <stdio.h>
#include <stdbool.h>
#include <libgen.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <getopt.h>
#include <sys/select.h>
#include <linux/input.h>
#include "board_r3000p.h"
#include "app_r3000p.h"
#include "data_info_v4_0.h"

dt_ui_t dt_ui;

dt_ui_t  *dt_r3000p_ui_create(void)
{
        dt_ui.paras.language = 0;
        dt_ui.paras.mode = 0;
        dt_ui.paras.page_idx =0;
        dt_ui.dt_work.machine.motor_speed  =1200;
        dt_ui.dt_work.machine.cw  =1;
        dt_ui.dt_work.machine.water_temp  =70;
         dt_ui.dt_work.rc.cw  =1;
         dt_ui.dt_work.rc.halt  =1;
          dt_ui.dt_work.machine.support_mode  =10;
          		 dt_ui.dt_work.machine.collapse_flag = true;
		dt_ui.dt_work.machine.leg_left_up_level = -3;
		dt_ui.dt_work.machine.leg_right_up_level = -3;
		dt_ui.dt_work.machine.leg_left_down_level = -2;
		dt_ui.dt_work.machine.leg_right_down_level = -3;
		dt_ui.dt_work.machine.alarm_flag = 1;
		dt_ui.dt_work.machine.limit_flag = 0;
		dt_ui.dt_work.machine.arm0_status = 100;
		dt_ui.dt_work.machine.leg_left_down_collapse = 1;
		dt_ui.dt_work.machine.leg_left_up_collapse = 1;
		dt_ui.dt_work.machine.leg_right_down_collapse = 1;
		dt_ui.dt_work.machine.leg_right_up_collapse = 1;
		// dt_ui.dt_work.machine.danger_edge = 1;
		// dt_ui.dt_work.machine.leg_left_down = 10;
		// dt_ui.dt_work.machine.leg_left_up = 100;
		// dt_ui.dt_work.machine.leg_right_down = 10;
		// dt_ui.dt_work.machine.leg_right_up = 10;
		// dt_ui.dt_work.machine.up_dis = 654;
        return &dt_ui;

}


