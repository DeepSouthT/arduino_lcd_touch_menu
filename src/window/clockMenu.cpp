/*******************************
 * clockMenu.cpp
 *
 * Created: 10.06.2020 22:20:00
 * Author : DeepSouthT
 *
 * Used:
 *    ToDo
 * 
 * Description:
 *     Clock menu
 *     This includes all its configurations
 *
 * Last modified: 19.06.2020
 *******************************/

 #include "window/clockMenu.h"
 #include "window/globalConfig.h"

void clockmenu::drawMenuHead(void)
{
  menu::drawMenuHead(clockmenuGLCD);
  clockmenuGLCD.drawBitmap((window_head_sx + 10), (window_head_sy + 49), 50, 50, clockNeedle);
} 

void clockmenu::drawMenuData(void)
{
  menu::drawMenuData(clockmenuGLCD);
  clockmenuGLCD.setColor(VGA_WHITE);
  clockmenuGLCD.setBackColor(VGA_BLACK);
  clockmenuGLCD.setFont(BigFont);

  clockmenuGLCD.drawBitmap((window_data_sx + 78), (window_data_sy + 24), 68, 43, german);
  clockmenuGLCD.print("XX", (window_data_sx + 158), (window_data_sy + 29));

  clockmenuGLCD.drawBitmap((window_data_sx + 78), (window_data_sy + 89), 67, 43, canada);
  clockmenuGLCD.print("XX", (window_data_sx + 158), (window_data_sy + 89));
}

void clockmenu::drawMenu(void)
{
  clockmenu::drawMenuHead();
  clockmenu::drawMenuData();
}
