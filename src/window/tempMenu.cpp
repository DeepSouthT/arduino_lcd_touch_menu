/*******************************
 * tempMenu.cpp
 *
 * Created: 10.06.2020 22:03:00
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

 #include "window/tempMenu.h"
 #include "window/globalConfig.h"

void tempmenu::drawMenuHead(void)
{
  menu::drawMenuHead(tempmenuGLCD);
  tempmenuGLCD.drawBitmap((window_head_sx + 10), (window_head_sy + 44), 29, 68, temp_icon);
} 

void tempmenu::drawMenuData(void)
{
  menu::drawMenuData(tempmenuGLCD);
  tempmenuGLCD.setColor(VGA_WHITE);
  tempmenuGLCD.setBackColor(VGA_BLACK);
  tempmenuGLCD.setFont(SevenSegNumFont);
  tempmenuGLCD.print("22", (window_data_sx + 68), (window_data_sy + 24));
  tempmenuGLCD.drawBitmap((window_data_sx + 138), (window_data_sy + 29), 36, 43, centigrade);
}

void tempmenu::drawMenu(void)
{
  tempmenu::drawMenuHead();
  tempmenu::drawMenuData();
}
