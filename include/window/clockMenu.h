/*******************************
 * clockMenu.h
 *
 * Created: 10.06.2020 22:17:00
 * Author : DeepSouthT
 *
 * Used:
 *    ToDo
 * 
 * Description:
 *     Clock menu
 *     This includes all its configurations
 *
 * Last modified: 15.06.2020
 *******************************/

#ifndef __CLOCKMENU_H__
#define __CLOCKMENU_H__

#include <UTFT.h>
#include "window/menu.h"

// Icon
extern unsigned int clockNeedle[0x9C4];
extern unsigned int german[0xB6C];
extern unsigned int canada[0xB41];

extern uint8_t SevenSegNumFont[];
extern uint8_t BigFont[];

class clockmenu : menu
{
  public:
  clockmenu(UTFT& clockmenuGLCD_): clockmenuGLCD(clockmenuGLCD_){};
  ~clockmenu(){};

  void drawMenuHead(void);
  void deawTime(Local_time_t local_time);

  void drawMenuData(Local_time_t local_time);

  void drawMenu(Local_time_t local_time);

  private:
  UTFT& clockmenuGLCD; 
};

#endif //__CLOCKMENU_H__