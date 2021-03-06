/*******************************
 * homeMenu.h
 *
 * Created: 09.06.2020 21:19:00
 * Author : DeepSouthT
 *
 * Used:
 *    ToDo
 * 
 * Description:
 *     Home menu
 *     This includes all its configurations
 *
 * Last modified: 21.06.2020
 *******************************/

#ifndef __HOMEMENU_H__
#define __HOMEMENU_H__

#include <UTFT.h>
#include "window/menu.h"

// Icon
extern unsigned int house[0x866];
extern unsigned int semicolon[0x172];

extern uint8_t SevenSegNumFont[];
extern uint8_t BigFont[];

class homemenu : menu
{
  public:
  homemenu(UTFT& homemenuGLCD_): homemenuGLCD(homemenuGLCD_){};
  ~homemenu(){};

  void drawMenuHead(void);
  void deawTime(Local_time_t local_time);

  void drawMenuData(Local_time_t local_time);

  //ToDo: return a status
  void drawMenu(Local_time_t local_time);

  private:
  UTFT& homemenuGLCD;
};

#endif //__HOMEMENU_H__