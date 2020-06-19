/*******************************
 * currencyMenu.h
 *
 * Created: 10.06.2020 22:35:00
 * Author : DeepSouthT
 *
 * Used:
 *    ToDo
 * 
 * Description:
 *     Currency menu
 *     This includes all its configurations
 *
 * Last modified: 19.06.2020
 *******************************/

#ifndef __CURRENCYMENU_H__
#define __CURRENCYMENU_H__

#include <UTFT.h>
#include "window/menu.h"

// Icon
extern unsigned int doller[0x834];
extern unsigned int german[0xB6C];
extern unsigned int canada[0xB41];

extern uint8_t SevenSegNumFont[];
extern uint8_t BigFont[];

class currencymenu : menu
{
  public:
  currencymenu(UTFT& currencymenuGLCD_): currencymenuGLCD(currencymenuGLCD_){};
  ~currencymenu(){};

  void drawMenuHead(void);

  void drawMenuData(void);

  //ToDo: return a status
  void drawMenu(void);

  private:
  UTFT& currencymenuGLCD;
};

#endif //__CURRENCYMENU_H__