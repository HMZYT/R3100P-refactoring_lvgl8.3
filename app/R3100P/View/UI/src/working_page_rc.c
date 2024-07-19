#include "../inc/working_page_rc.h"
#include "../inc/working_page_home.h"

static working_page_rc_t *p;
int bg_light_level = 100;

static rocker_t *_create_rocker(lv_obj_t *parent);
static rc_lcd_button_t *_create_button(lv_obj_t *parent);
static void _button_set_v(rc_lcd_button_t *btn, uint8_t v);                //二选一或三选一开关设置
static void _button_side_set_clicked(lv_obj_t *btn, bool clicked);         //侧边按键设置
static void _button_lock_arm_set_v(lv_obj_t *btn, lv_obj_t *l, uint8_t v); //锁臂按键设置
static void _set_displacement(lv_obj_t *btn, lv_obj_t *label, uint8_t v);  //排量设置
static void _set_rocker(rocker_t *rocker, uint8_t v);


lv_obj_t* working_page_rc_init(lv_obj_t *page)
{
    p = lv_mem_alloc(sizeof (working_page_rc_t));
    uint16_t parent_width, parent_height;

    parent_width = lv_disp_get_hor_res(NULL);
    parent_height = lv_disp_get_ver_res(NULL);

    lv_obj_t *obj = lv_obj_create(page);
    lv_obj_set_size(obj, parent_width, parent_height - 60 - 60);
    lv_obj_set_pos(obj, 0, 60);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);

    int i = 0;
    for (i = 0; i < 6; ++i)
    {
        p->rockers[i] = _create_rocker(obj);
        lv_obj_set_pos(p->rockers[i]->ibase, 170 + 120 * i, 188 - 60);

        p->up[i] = lv_label_create(obj);
        p->down[i] = lv_label_create(obj);

        lv_obj_set_pos(p->up[i], 250 + 120 * i, 188 - 70);
        lv_obj_add_flag( p->up[i], LV_OBJ_FLAG_HIDDEN );
        lv_label_set_text( p->up[i], "127" );

        lv_obj_set_pos(p->down[i], 250 + 120 * i, 355 - 70);
        lv_obj_add_flag( p->down[i], LV_OBJ_FLAG_HIDDEN );
        lv_label_set_text( p->down[i], "-127" );
    }

    for (i = 0; i < 6; ++i)
    {
        p->btns[i] = _create_button(obj);
        lv_obj_set_pos(p->btns[i]->ibase, 287 + 97 * i, 501 - 60);
        _button_set_v(p->btns[i], 0);
    }

    p->btn_whistle_and_off = lv_img_create(obj);
    lv_img_set_src(p->btn_whistle_and_off, &control_margin_02);
    lv_obj_set_pos(p->btn_whistle_and_off, 0, 173 - 60);

    lv_obj_t * tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &horn_rc);
    lv_obj_set_pos( tmp_label, 46, 226 - 60);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_power_red);
    lv_obj_set_pos( tmp_label, 46, 159 - 60);

    p->btn_stop = lv_img_create(obj);
    lv_img_set_src(p->btn_stop, &control_margin_02);
    lv_obj_set_pos(p->btn_stop, 0, 510 - 60);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_motor_stop );
    lv_obj_set_pos( tmp_label, 46, 520 - 60);

    p->btn_start = lv_img_create(obj);
    lv_img_set_src(p->btn_start, &control_margin_02);
    lv_obj_set_pos(p->btn_start, 0, 420 - 60);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_motor_start );
    lv_obj_set_pos( tmp_label, 46, 430 - 60 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src(tmp_label, &control_cycle_Bbtn2);
    lv_obj_set_pos(tmp_label, 1007, 455 - 60);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &control_cycle_Bbtn1);
    lv_obj_set_pos( tmp_label, 1015, 470 - 60);

    p->btn_replacement = lv_img_create(obj);
    lv_img_set_src( p->btn_replacement, &control_cycle_Bbtn);
    lv_obj_set_pos( p->btn_replacement, 1029, 480 - 60);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &bbbbb_bump );
    lv_obj_set_pos( tmp_label, 1055, 583 - 60);

    p->btn_lock_arms = lv_img_create(obj);
    lv_img_set_src(p->btn_lock_arms, &control_cycle_Sbtn);
    lv_obj_set_pos(p->btn_lock_arms, 120 + 29.5, 480 + 30 - 60);

    //锁臂
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &control_cycle_Sbtn_bg1);
    lv_obj_set_pos( tmp_label, 120, 480 - 60);

    //锁臂
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &control_cycle_Sbtn_bg2);
    lv_obj_set_pos( tmp_label, 112, 460 - 60);

    //锁臂
    tmp_label = lv_img_create(obj);
    lv_img_set_src( tmp_label, &img_arm_lock );
    lv_obj_set_pos( tmp_label, 140, 584 - 60);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_gh0_v6c2);
    lv_obj_set_pos( tmp_label, 1017, 137 - 60);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_gh1_v6c2);
    lv_obj_set_pos( tmp_label, 1017, 340 - 60);

    p->arms06a = lv_img_create( obj );
    lv_img_set_src( p->arms06a, &arm_gX1);
    lv_obj_set_pos( p->arms06a, 1157, 165 - 60);
    lv_img_set_zoom(p->arms06a, 200);

    p->arms06b = lv_img_create( obj );
    lv_img_set_src( p->arms06b, &bbbbb_other);
    lv_obj_set_pos( p->arms06b, 1002, 187 - 60);

    p->arms06c = lv_img_create( obj );
    lv_img_set_src( p->arms06c, &button_cycle_red);
    lv_obj_set_pos( p->arms06c, 1038, 224 - 60);
    lv_img_set_zoom(p->arms06c, 120);

    p->label_rig_0 = lv_label_create( obj );
    lv_label_set_text(p->label_rig_0, "");
    lv_obj_set_pos(p->label_rig_0, 1022 - 100, 109 + 80 -15);

    p->label_rig_1 = lv_label_create( obj );
    lv_label_set_text(p->label_rig_1, "");
    lv_obj_set_pos(p->label_rig_1, 1022 + 125, 109 + 80 -15);

    p->label_dow_0 = lv_label_create(obj );
    lv_label_set_text(p->label_dow_0, "");
    lv_obj_set_pos(p->label_dow_0, 1022 + 120, 109 + 50 +20 + 5 - 100);

    p->label_dow_1 = lv_label_create(obj );
    lv_label_set_text(p->label_dow_1, "");
    lv_obj_set_pos(p->label_dow_1, 1022 + 120, 109 + 50 +20 + 5 + 100);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_a0);
    lv_obj_set_pos( tmp_label, 190, 105 - 60);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_b0_v6c2);
    lv_obj_set_pos( tmp_label, 290 , 125 - 60);
    //lv_img_set_zoom(tmp_label, 220);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_c0);
    lv_obj_set_pos( tmp_label, 430 + 120 * 0 , 115 - 60);
    //lv_img_set_zoom(tmp_label, 200);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_d0);
    lv_obj_set_pos( tmp_label, 430 + 120 * 1, 115 - 60 );
    //lv_img_set_zoom(tmp_label, 200);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_e0);
    lv_obj_set_pos( tmp_label, 430 + 120 * 2, 115 - 60 );
    //lv_img_set_zoom(tmp_label, 200);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_f0);
    lv_obj_set_pos( tmp_label, 430 + 120 * 3, 115 - 60 );
    //lv_img_set_zoom(tmp_label, 200);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_a1);
    lv_obj_set_pos( tmp_label, 190, 366 - 60);
    //lv_img_set_zoom(tmp_label, 200);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_b1_v6c2);
    lv_obj_set_pos( tmp_label, 290 , 316);
    //lv_img_set_zoom(tmp_label, 220);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_c1);
    lv_obj_set_pos( tmp_label, 430 + 120 * 0, 305);
    //lv_img_set_zoom(tmp_label, 200);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_d1);
    lv_obj_set_pos( tmp_label, 430 + 120 * 1, 305);
    //lv_img_set_zoom(tmp_label, 200);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_e1);
    lv_obj_set_pos( tmp_label, 430 + 120 * 2, 305);
    //lv_img_set_zoom(tmp_label, 200);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_f1);
    lv_obj_set_pos( tmp_label, 430 + 120 * 3, 305);
    //v_img_set_zoom(tmp_label, 200);

    p->btn_quick_set = lv_img_create(obj);
    lv_img_set_src(p->btn_quick_set, &control_margin_02);
    lv_obj_set_pos(p->btn_quick_set, parent_width - 34, 80 - 60);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &quick_setting);
    lv_obj_set_pos( tmp_label, 1200, 100 - 60);

    p->btn_swing_left = lv_img_create(obj);
    lv_img_set_src(p->btn_swing_left, &control_margin_02);
    lv_obj_set_pos(p->btn_swing_left, parent_width - 34, 370 - 60);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_swing_left);
    lv_obj_set_pos( tmp_label, 1190, 380 - 60);

    p->btn_swing_right = lv_img_create(obj);
    lv_img_set_src(p->btn_swing_right, &control_margin_02);
    lv_obj_set_pos(p->btn_swing_right, parent_width - 34, 470 - 60);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_swing_right);
    lv_obj_set_pos( tmp_label, 1190, 480 - 60);

    p->btn_emergency = lv_img_create(obj);
    lv_img_set_src(p->btn_emergency, &control_margin_02);
    lv_obj_set_pos(p->btn_emergency, parent_width - 34, 570 - 60);

    tmp_label = lv_label_create(obj);
    lv_obj_set_pos(tmp_label,  parent_width - 104, 600 - 60);
    lv_label_set_text(tmp_label, "急停");
    lv_obj_add_style(tmp_label, theme_style_get_label_normal_32px_red(), 0);

    //位置1
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_bump_down);
    lv_obj_set_pos( tmp_label, 310, 462 - 60 );
    lv_img_set_zoom(tmp_label, 280);

    //位置2
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_motor_up);
    lv_obj_set_pos( tmp_label, 404, 402 );

    //位置3
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &fast_mode);
    lv_obj_set_pos( tmp_label, 501 , 402 );

    //位置4
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &vibrate_on);
    lv_obj_set_pos( tmp_label, 593, 402 );

    //位置5
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_gX1);
    lv_obj_set_pos( tmp_label, 687, 392);
    lv_img_set_zoom(tmp_label, 200);

    //位置6
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_bump);
    lv_obj_set_pos( tmp_label, 786, 402 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_strong);
    lv_obj_set_pos( tmp_label, 786 + 10, 402);

    //位置1
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_bump_up);
    lv_obj_set_pos( tmp_label, 310, 590 - 60);
    lv_img_set_zoom(tmp_label, 280);

    //位置2
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_motor_down);
    lv_obj_set_pos( tmp_label, 404, 530);

    //位置3
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &slow_mode);
    lv_obj_set_pos( tmp_label, 501, 530);

    //位置4
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &vibrate_off);
    lv_obj_set_pos( tmp_label, 593, 530);

    //位置5
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_gX2_v6c2);
    lv_obj_set_pos( tmp_label, 687, 530);

    //位置6
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_bump);
    lv_obj_set_pos( tmp_label, 786, 530);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_eco);
    lv_obj_set_pos( tmp_label, 786 + 10, 530);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &shutong);
    lv_obj_set_pos( tmp_label, 850, 460);
    lv_img_set_zoom(tmp_label, 280);

    return obj;
}

void * rc_refresh(void *data)
{
    static dt_rc_status_t last;
    char temp[64];
    dt_ui_t *d = (dt_ui_t *)data;

    if ( last.armSupport != d->dt_work.rc.armSupport )
    {
        _set_rocker(p->rockers[0], d->dt_work.rc.armSupport);
        last.armSupport = d->dt_work.rc.armSupport;
        if ( last.armSupport == 0 )
        {
            lv_obj_add_flag( p->up[0], LV_OBJ_FLAG_HIDDEN );
            lv_obj_add_flag( p->down[0], LV_OBJ_FLAG_HIDDEN );
        }
        else if ( last.armSupport <= 0x7F )
        {//下降
            lv_obj_add_flag( p->up[0], LV_OBJ_FLAG_HIDDEN );
            lv_obj_clear_flag( p->down[0], LV_OBJ_FLAG_HIDDEN );
            lv_label_set_text_fmt( p->down[0], "-%d", last.armSupport );
        }
        else
        {//上升
            lv_obj_clear_flag( p->up[0], LV_OBJ_FLAG_HIDDEN );
            lv_obj_add_flag( p->down[0], LV_OBJ_FLAG_HIDDEN );
            lv_label_set_text_fmt( p->up[0], "%d", 0xFF - (uint8_t)last.armSupport +1 );
        }
    }

    if ( last.arm1 != d->dt_work.rc.arm1 )
    {
        _set_rocker(p->rockers[1], d->dt_work.rc.arm1);
        last.arm1 = d->dt_work.rc.arm1;
        if ( last.arm1 == 0 )
        {
            lv_obj_add_flag( p->up[1], LV_OBJ_FLAG_HIDDEN );
            lv_obj_add_flag( p->down[1], LV_OBJ_FLAG_HIDDEN );
        }
        else if ( last.arm1 <= 0x7F )
        {
            lv_obj_add_flag( p->up[1], LV_OBJ_FLAG_HIDDEN );
            lv_obj_clear_flag( p->down[1], LV_OBJ_FLAG_HIDDEN );
            lv_label_set_text_fmt( p->down[1], "-%d", last.arm1 );
        }
        else
        {
            lv_obj_clear_flag( p->up[1], LV_OBJ_FLAG_HIDDEN );
            lv_obj_add_flag( p->down[1], LV_OBJ_FLAG_HIDDEN );
            lv_label_set_text_fmt( p->up[1], "%d", 0xFF - (uint8_t)last.arm1 + 1 );
        }
    }


    if ( last.arm2 != d->dt_work.rc.arm2 )
    {
        _set_rocker(p->rockers[2], d->dt_work.rc.arm2);
        last.arm2 = d->dt_work.rc.arm2;

        if ( last.arm2 == 0 )
        {
            lv_obj_add_flag( p->up[2], LV_OBJ_FLAG_HIDDEN );
            lv_obj_add_flag( p->down[2], LV_OBJ_FLAG_HIDDEN );
        }
        else if ( last.arm2 <= 0x7F )
        {
            lv_obj_add_flag( p->up[2], LV_OBJ_FLAG_HIDDEN );
            lv_obj_clear_flag( p->down[2], LV_OBJ_FLAG_HIDDEN );
            lv_label_set_text_fmt( p->down[2], "-%d", last.arm2 );
        }
        else
        {
            lv_obj_clear_flag( p->up[2], LV_OBJ_FLAG_HIDDEN );
            lv_obj_add_flag( p->down[2], LV_OBJ_FLAG_HIDDEN );
            lv_label_set_text_fmt( p->up[2], "%d", 0xFF - last.arm2 + 1 );
        }
    }

    if ( last.arm3 != d->dt_work.rc.arm3 )
    {
        _set_rocker(p->rockers[3], d->dt_work.rc.arm3);
        last.arm3 = d->dt_work.rc.arm3;

        if ( last.arm3 == 0 )
        {
            lv_obj_add_flag( p->up[3], LV_OBJ_FLAG_HIDDEN );
            lv_obj_add_flag( p->down[3], LV_OBJ_FLAG_HIDDEN );
        }
        else if ( last.arm3 <= 0x7F )
        {
            lv_obj_add_flag( p->up[3], LV_OBJ_FLAG_HIDDEN );
            lv_obj_clear_flag( p->down[3], LV_OBJ_FLAG_HIDDEN );
            lv_label_set_text_fmt( p->down[3], "-%d", last.arm3 );
        }
        else
        {
            lv_obj_clear_flag( p->up[3], LV_OBJ_FLAG_HIDDEN );
            lv_obj_add_flag( p->down[3], LV_OBJ_FLAG_HIDDEN );
            lv_label_set_text_fmt( p->up[3], "%d", 0xFF - last.arm3 + 1 );
        }
    }

    if ( last.arm4 != d->dt_work.rc.arm4 )
    {
        _set_rocker(p->rockers[4], d->dt_work.rc.arm4);
        last.arm4 = d->dt_work.rc.arm4;

        if ( last.arm4 == 0 )
        {
            lv_obj_add_flag( p->up[4], LV_OBJ_FLAG_HIDDEN );
            lv_obj_add_flag( p->down[4], LV_OBJ_FLAG_HIDDEN );
        }
        else if ( last.arm4 <= 0x7F )
        {
            lv_obj_add_flag( p->up[4], LV_OBJ_FLAG_HIDDEN );
            lv_obj_clear_flag( p->down[4], LV_OBJ_FLAG_HIDDEN );
            lv_label_set_text_fmt( p->down[4], "-%d", last.arm4 );
        }
        else
        {
            lv_obj_clear_flag( p->up[4], LV_OBJ_FLAG_HIDDEN );
            lv_obj_add_flag( p->down[4], LV_OBJ_FLAG_HIDDEN );
            lv_label_set_text_fmt( p->up[4], "%d", 0xFF - last.arm4 + 1 );
        }
    }

    if ( last.arm5 != d->dt_work.rc.arm5 )
    {
        _set_rocker(p->rockers[5], d->dt_work.rc.arm5);
        last.arm5 = d->dt_work.rc.arm5;


        if ( last.arm5 == 0 )
        {
            lv_obj_add_flag( p->up[5], LV_OBJ_FLAG_HIDDEN );
            lv_obj_add_flag( p->down[5], LV_OBJ_FLAG_HIDDEN );
        }
        else if ( last.arm5 <= 0x7F )
        {
            lv_obj_add_flag( p->up[5], LV_OBJ_FLAG_HIDDEN );
            lv_obj_clear_flag( p->down[5], LV_OBJ_FLAG_HIDDEN );
            lv_label_set_text_fmt( p->down[5], "-%d", last.arm5 );
        }
        else
        {
            lv_obj_clear_flag( p->up[5], LV_OBJ_FLAG_HIDDEN );
            lv_obj_add_flag( p->down[5], LV_OBJ_FLAG_HIDDEN );
            lv_label_set_text_fmt( p->up[5], "%d", 0xFF - last.arm5 + 1);
        }
    }

    if ( last.arm6 != d->dt_work.rc.arm6 || last.arm7 != d->dt_work.rc.arm7)
    {
        last.arm6 = d->dt_work.rc.arm6;
        last.arm7 = d->dt_work.rc.arm7;

        float vx, vy;

        if ( last.arm6 <= 0x7F &&  last.arm7 <= 0x7F) //象限4
        {
            vy = 0.3543 * last.arm6;
            vx = 0.3543 * last.arm7;
            lv_obj_set_pos( p->arms06c, 1038 + vx , 164 + vy);
            lv_label_set_text_fmt( p->label_dow_1, "-%d", last.arm6 );
            lv_label_set_text_fmt( p->label_rig_1, "-%d", last.arm7 );
        }
        else if ( last.arm6 > 0x7F &&  last.arm7 <= 0x7F )//象限1
        {
            vy = 0.3543 * (0xFF-last.arm6 +1);
            vx = 0.3543 * last.arm7;
            lv_obj_set_pos( p->arms06c, 1038 + vx , 164 - vy);
            lv_label_set_text_fmt( p->label_dow_0, "%d", 0xFF - last.arm6 + 1);
            lv_label_set_text_fmt( p->label_rig_1, "-%d", last.arm7 );
        }
        else if ( last.arm6 > 0x7F &&  last.arm7 > 0x7F )//象限2
        {
            vy = 0.3543 * (0xFF-last.arm6 +1);
            vx = 0.3543 * (0xFF-last.arm7 +1);
            lv_obj_set_pos( p->arms06c, 1038 - vx , 164 - vy);
            lv_label_set_text_fmt( p->label_dow_0, "%d", 0xFF - last.arm6 + 1);
            lv_label_set_text_fmt( p->label_rig_0, "%d", 0xFF - last.arm7 + 1);
        }
        else if ( last.arm6 <= 0x7F &&  last.arm7 > 0x7F )//象限3
        {
            vy = 0.3543 * last.arm6;
            vx = 0.3543 * (0xFF-last.arm7 +1);
            lv_obj_set_pos( p->arms06c, 1038 - vx , 164 + vy);
            lv_label_set_text_fmt( p->label_dow_1, "-%d", last.arm6 );
            lv_label_set_text_fmt( p->label_rig_0, "%d", 0xFF - last.arm7 + 1);
        }

        if ( last.arm6 == 0 )
        {
            lv_obj_add_flag( p->label_dow_0, LV_OBJ_FLAG_HIDDEN );
            lv_obj_add_flag( p->label_dow_1, LV_OBJ_FLAG_HIDDEN );
        }
        else
        {
            lv_obj_clear_flag( p->label_dow_0, LV_OBJ_FLAG_HIDDEN );
            lv_obj_clear_flag( p->label_dow_1, LV_OBJ_FLAG_HIDDEN );
        }

        if ( last.arm7 == 0 )
        {
            lv_obj_add_flag( p->label_rig_0, LV_OBJ_FLAG_HIDDEN );
            lv_obj_add_flag( p->label_rig_1, LV_OBJ_FLAG_HIDDEN );
        }
        else
        {
            lv_obj_clear_flag( p->label_rig_0, LV_OBJ_FLAG_HIDDEN );
            lv_obj_clear_flag( p->label_rig_1, LV_OBJ_FLAG_HIDDEN );
        }
    }


    uint8_t v[ 7 ] = { 0 };
    static uint8_t last_v[ 7 ] = { 0 };

    /***************************
    * BUTTON1: 正反泵
    ***************************/
    if ( d->dt_work.rc.ccw )
    {//下
        v[ 0 ] = 2;
    }
    else if ( d->dt_work.rc.cw )
    {//上
        v[ 0 ] = 1;
    }
    else
    {//中
        v[ 0 ] = 0;
    }

    if ( v[ 0 ] != last_v[ 0 ] )
    {
        _button_set_v(p->btns[0], v[ 0 ]);
        last_v[ 0 ] = v[ 0 ];
    }

    /***************************
    * BUTTON2: PRM
    ***************************/
    if ( d->dt_work.rc.rpm_minus )
    {//下
        v[ 1 ] = 2;
    }
    else if ( d->dt_work.rc.rpm_plus )
    {//上
        v[ 1 ] = 1;
    }
    else
    {//中
        v[ 1 ] = 0;
    }

    if ( v[ 1 ] != last_v[ 1 ] )
    {
        _button_set_v(p->btns[1], v[ 1 ]);
        last_v[ 1 ] = v[ 1 ];
    }

    /***************************
    * BUTTON3: 龟兔
    ***************************/
    if ( d->dt_work.rc.slow )
    {//下
        v[ 2 ] = 2;
    }
    else
    {//上
        v[ 2 ] = 1;
    }

    if ( v[ 2 ] != last_v[ 2 ] )
    {
        _button_set_v(p->btns[2], v[ 2 ]);
        last_v[ 2 ] = v[ 2 ];
    }

    /***************************
    * BUTTON4: 减震
    ***************************/
    if ( d->dt_work.rc.dampcan_enable )
    {//上
        v[ 3 ] = 1;
    }
    else
    {//下
        v[ 3 ] = 2;
    }

    if ( v[ 3 ] != last_v[ 3 ] )
    {
        _button_set_v(p->btns[3], v[ 3 ]);
        last_v[ 3 ] = v[ 3 ];
    }

    /***************************
    * BUTTON5: 一键展收臂
    ***************************/
    if ( d->dt_work.rc.deploy_retract )
    {//下
        v[ 4 ] = 2;
    }
    else if ( d->dt_work.rc.pour )
    {//上
        v[ 4 ] = 1;
    }
    else if (d->dt_work.rc.normal)
    {//中
        v[ 4 ] = 0;
    }

    if ( v[ 4 ] != last_v[ 4 ] )
    {
        _button_set_v(p->btns[4], v[ 4 ]);
        last_v[ 4 ] = v[ 4 ];
    }

    /***************************
   * BUTTON6: 强力、疏通、节能
   ***************************/
    if ( d->dt_work.rc.dredge )
    {//疏通
        v[ 5 ] = 0;
    }
    else if ( d->dt_work.rc.strong_power )
    {//强力
        v[ 5 ] = 1;
    }
    else
    {//节能
        v[ 5 ] = 2;
    }

    if ( v[ 5 ] != last_v[ 5 ] )
    {
        _button_set_v(p->btns[5], v[ 5 ]);
        last_v[ 5 ] = v[ 5 ];
    }

    //排量
    if ( last.displacement != d->dt_work.rc.displacement )
    {
        _set_displacement(p->btn_replacement, p->label_displacement, d->dt_work.rc.displacement);
        last.displacement = d->dt_work.rc.displacement;
    }

    //锁臂
    static uint8_t last_lock = 0;
    uint8_t lock = 0;
    if ( d->dt_work.rc._1 )
    {
        lock = 1;
    }
    else if ( d->dt_work.rc._1_2 )
    {
        lock = 2;
    }
    else if ( d->dt_work.rc._1_2_3 )
    {
        lock = 3;
    }
    else if ( d->dt_work.rc._2 )
    {
        lock = 4;
    }
    else if ( d->dt_work.rc._3 )
    {
        lock = 5;
    }
    else if ( d->dt_work.rc._2_3 )
    {
        lock = 6;
    }
    if ( lock != last_lock )
    {
        lv_img_set_angle(p->btn_lock_arms, lock * 300);
        last_lock = lock;
    }

    //侧面6按键
    if ( last.horn != d->dt_work.rc.horn )
    {
        _button_side_set_clicked(p->btn_whistle_and_off, d->dt_work.rc. horn);
        last.horn = d->dt_work.rc.horn;
    }

    if ( last.start_key != d->dt_work.rc.start_key )
    {
        _button_side_set_clicked(p->btn_start, d->dt_work.rc.start_key);
        last.start_key = d->dt_work.rc.start_key;
    }

    if ( last.engine_stop != d->dt_work.rc.engine_stop )
    {
        _button_side_set_clicked(p->btn_stop, d->dt_work.rc.engine_stop);
        last.engine_stop = d->dt_work.rc.engine_stop;
    }

    if ( last.left_swing_pump != d->dt_work.rc.left_swing_pump )
    {
        _button_side_set_clicked(p->btn_swing_left, d->dt_work.rc.left_swing_pump);
        last.left_swing_pump = d->dt_work.rc.left_swing_pump;
    }

    if ( last.right_swing_pump != d->dt_work.rc.right_swing_pump )
    {
        _button_side_set_clicked(p->btn_swing_right, d->dt_work.rc.right_swing_pump);
        last.right_swing_pump = d->dt_work.rc.right_swing_pump;
    }

    if ( last.halt != d->dt_work.rc.halt )
    {
        _button_side_set_clicked(p->btn_emergency, d->dt_work.rc.halt);
        last.halt = d->dt_work.rc.halt;
    }
}

static rc_lcd_button_t *_create_button(lv_obj_t *parent)
{
    rc_lcd_button_t *btn = (rc_lcd_button_t *)malloc(sizeof(rc_lcd_button_t));
    if (!btn)
    {
        return NULL;
    }

    btn->ibase = lv_label_create(parent);
    lv_label_set_text(btn->ibase, "");
    btn->v = lv_img_create(btn->ibase);
    lv_img_set_src(btn->v, &control_s_btn02);
    lv_obj_set_pos(btn->v, 0, 0);
    lv_obj_clear_flag(btn->ibase, LV_OBJ_FLAG_SCROLLABLE);

    return btn;
}

//二选一或三选一开关设置
static void _button_set_v(rc_lcd_button_t *btn, uint8_t v)
{
    if (v == 0)
    { //中间
        lv_img_set_src(btn->v, &control_s_btn02);
    }
    else if (v == 1)
    { //上
        lv_img_set_src(btn->v, &control_s_btn01);
    }
    else if (v == 2)
    { //下
        lv_img_set_src(btn->v, &control_s_btn03);
    }
    else
    {
        lv_img_set_src(btn->v, &control_s_btn02);
    }
}

//侧边按键设置
static void _button_side_set_clicked(lv_obj_t *btn, bool clicked)
{
    if (clicked)
    {
        lv_img_set_src(btn, &control_margin_01);
    }
    else
    {
        lv_img_set_src(btn, &control_margin_02);
    }
}

static void _set_displacement(lv_obj_t *btn, lv_obj_t *label, uint8_t v) //排量设置
{
    if (v > 127)
    {
        v = 127;
    }
    float tv = v / 12.7;
    //图片旋转
    lv_img_set_angle(btn, tv * 285);
}

static void _set_rocker(rocker_t *rocker, uint8_t v)
{
    if (v == 0x00)
    { //在中间
        lv_img_set_src(rocker->v, &control_btn02);
        lv_obj_set_pos(rocker->v, 0, 34);
    }
    else if (v <= 0x7F)
    { //下降
        lv_img_set_src(rocker->v, &control_btn04);
        lv_obj_set_pos(rocker->v, 0, 34 + 25);
    }
    else
    { //上升
        lv_img_set_src(rocker->v, &control_btn03);
        lv_obj_set_pos(rocker->v, 0, 34 - 25);
    }
}

rocker_t *_create_rocker(lv_obj_t *parent)
{
    rocker_t *r = (rocker_t *)malloc(sizeof(rocker_t));
    if (!r)
    {
        return NULL;
    }

    r->ibase = lv_label_create(parent);
    lv_label_set_text(r->ibase, "");
    lv_obj_t *bg_img = lv_img_create(r->ibase);
    lv_img_set_src(bg_img, &control_btn01);
    lv_obj_set_pos(bg_img, 0, 0);
    lv_obj_clear_flag(r->ibase, LV_OBJ_FLAG_SCROLLABLE);

    r->v = lv_img_create(bg_img);
    lv_img_set_src(r->v, &control_btn02);
    lv_obj_set_pos(r->v, 0, 50);

    return r;
}
