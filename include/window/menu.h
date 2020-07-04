/*******************************
 * menu.h
 *
 * Created: 19.06.2020 22:01:00
 * Author : DeepSouthT
 *
 * Used:
 *    ToDo
 * 
 * Description:
 *     Base class for any menu
 *
 * Last modified: 19.06.2020
 *******************************/

#ifndef __MENU_H__
#define __MENU_H__

#include <UTFT.h>
#include "window/globalConfig.h"

class menu
{
  public:
  menu(){};
  ~menu(){};

  void drawMenuHead(UTFT& menuGLCD);
  void drawMenuData(UTFT& menuGLCD);
  void drawMenu(UTFT& menuGLCD);
  void clearMenuHead(UTFT& menuGLCD);
  void clearMenuData(UTFT& menuGLCD);
  void clearMenu(UTFT& menuGLCD);

  private:
  
};

#endif //__MENU_H__