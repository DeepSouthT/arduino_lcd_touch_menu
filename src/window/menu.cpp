/*******************************
 * clockMenu.cpp
 *
 * Created: 19.06.2020 22:09:00
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

 #include "window/menu.h"
 #include "window/globalConfig.h"

void menu::drawMenuHead(UTFT& menuGLCD)
{
  menu::clearMenuHead(menuGLCD);
} 

void menu::drawMenuData(UTFT& menuGLCD)
{
  menu::clearMenuData(menuGLCD);
}

void menu::drawMenu(UTFT& menuGLCD)
{
  menu::drawMenuHead(menuGLCD);
  menu::drawMenuData(menuGLCD);
}

void menu::clearMenuHead(UTFT& menuGLCD)
{
  menuGLCD.setColor(default_menu_colour);
  menuGLCD.fillRect (window_head_sx, window_head_sy, window_head_ex, window_head_ey);
} 

void menu::clearMenuData(UTFT& menuGLCD)
{
  menuGLCD.setColor(default_menu_colour);
  menuGLCD.fillRect (window_data_sx, window_data_sy, window_data_ex, window_data_ey);
}
 
void menu::clearMenu(UTFT& menuGLCD)
{
  menuGLCD.setColor(default_menu_colour);
  menuGLCD.fillRect(window_sx, window_sy, window_ex, window_ey);
}