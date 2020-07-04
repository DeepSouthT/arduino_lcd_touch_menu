/*******************************
 * tempMenu.h
 *
 * Created: 10.06.2020 21:59:00
 * Author : DeepSouthT
 *
 * Used:
 *    ToDo
 * 
 * Description:
 *     Temperature menu
 *     This includes all its configurations
 *
 * Last modified: 19.06.2020
 *******************************/

#ifndef __TEMPMENU_H__
#define __TEMPMENU_H__

#include <UTFT.h>
#include "window/menu.h"

// Icon
extern unsigned int temp_icon[0x7B4];
extern unsigned int centigrade[0x60C];

extern uint8_t SevenSegNumFont[];
extern uint8_t BigFont[];

class tempmenu : menu
{
  public:
  tempmenu(UTFT& tempmenuGLCD_): tempmenuGLCD(tempmenuGLCD_){};
  ~tempmenu(){};

  void drawMenuHead(void);

  void drawTemp(uint8_t temp);

  void drawMenuData(uint8_t temp);

  //ToDo: return a status
  void drawMenu(uint8_t temp);

  private:
  UTFT& tempmenuGLCD;
};

#endif //__TEMPMENU_H__