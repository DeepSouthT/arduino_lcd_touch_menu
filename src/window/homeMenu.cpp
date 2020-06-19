/*******************************
 * homeMenu.cpp
 *
 * Created: 09.06.2020 21:24:00
 * Author : DeepSouthT
 *
 * Used:
 *    ToDo
 * 
 * Description:
 *     Home menu
 *     This includes all its configurations
 *
 * Last modified: 19.06.2020
 *******************************/

 #include "window/homeMenu.h"
 #include "window/globalConfig.h"

void homemenu::drawMenuHead(void)
{
  menu::drawMenuHead(homemenuGLCD);
  homemenuGLCD.drawBitmap((window_head_sx + 10), (window_head_sy + 54), 50, 43, house);
} 

void homemenu::drawMenuData(void)
{
  menu::drawMenuData(homemenuGLCD);
  homemenuGLCD.setColor(VGA_WHITE);
  homemenuGLCD.setBackColor(VGA_BLACK);
  homemenuGLCD.setFont(SevenSegNumFont);
  homemenuGLCD.print("10", (window_data_sx + 68), (window_data_sy + 24));
  homemenuGLCD.drawBitmap((window_data_sx + 138), (window_data_sy + 29), 10, 37, semicolon);
  homemenuGLCD.print("10", (window_data_sx + 147), (window_data_sy + 24));

  homemenuGLCD.setFont(BigFont);
  homemenuGLCD.print("01.10.2019", (window_data_sx + 68), (window_data_sy + 89));
}

void homemenu::drawMenu(void)
{
  homemenu::drawMenuHead();
  homemenu::drawMenuData();
}
