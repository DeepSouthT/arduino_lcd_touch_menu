/*******************************
 * globalConfig.h
 *
 * Created: 13.06.2020 17:53:00
 * Author : DeepSouthT
 *
 * Used:
 *    ToDo
 * 
 * Description:
 *     Global configurations
 *
 * Last modified: 13.06.2020
 *******************************/

#ifndef __GLOBALCONFIG_H__
#define __GLOBALCONFIG_H__

/**
 * The amount of time which is delayed after each touch event
 * Only after this delay, the program proceed after a touch
**/
#define TOUCH_RESPONSE_DELAY 150

/// Default backgraund of menus
static const uint16_t default_menu_colour = VGA_BLACK;

/// Global window coordinates
static const uint16_t window_sx = 0;
static const uint16_t window_sy = 31;
static const uint16_t window_ex = 319;
static const uint16_t window_ey = 179;

/// Menu header window coordinates
static const uint16_t window_head_sx = 0;
static const uint16_t window_head_sy = 31;
static const uint16_t window_head_ex = 61;
static const uint16_t window_head_ey = 188;

/// Menu content window coordinates
static const uint16_t window_data_sx = 62;
static const uint16_t window_data_sy = 31;
static const uint16_t window_data_ex = 319;
static const uint16_t window_data_ey = 179;

/// Local time
struct Local_time_t {
    uint8_t loc_time_hr;
    uint8_t loc_time_min;
    uint8_t loc_time_sec;
};

#endif //__GLOBALCONFIG_H__
