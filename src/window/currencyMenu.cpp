/*******************************
 * currencyMenu.cpp
 *
 * Created: 10.06.2020 22:38:00
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

 #include "window/currencyMenu.h"
 #include "window/globalConfig.h"

void currencymenu::drawMenuHead(void)
{
  menu::drawMenuHead(currencymenuGLCD);
  currencymenuGLCD.drawBitmap((window_head_sx + 10), (window_head_sy + 49), 35, 60, doller);
} 

void currencymenu::drawMenuData(void)
{
  menu::drawMenuData(currencymenuGLCD);
}

void currencymenu::drawMenu(void)
{
  currencymenu::drawMenuHead();
  currencymenu::drawMenuData();
}
