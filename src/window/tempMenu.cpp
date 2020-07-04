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

void tempmenu::drawMenuHead(void)
{
  menu::drawMenuHead(tempmenuGLCD);
  tempmenuGLCD.drawBitmap((window_head_sx + 10), (window_head_sy + 44), 29, 68, temp_icon);
}

void tempmenu::drawTemp(uint8_t temp)
{
  tempmenuGLCD.setColor(VGA_WHITE);
  tempmenuGLCD.setBackColor(VGA_BLACK);
  tempmenuGLCD.setFont(SevenSegNumFont);

  char str[2];
  sprintf(str, "%02d", temp);
  tempmenuGLCD.print(str, (window_data_sx + 98), (window_data_sy + 24));
}

void tempmenu::drawMenuData(uint8_t temp)
{
  menu::drawMenuData(tempmenuGLCD);

  tempmenuGLCD.drawBitmap((window_data_sx + 168), (window_data_sy + 29), 36, 43, centigrade);
  tempmenu::drawTemp(temp);
}

void tempmenu::drawMenu(uint8_t temp)
{
  tempmenu::drawMenuHead();
  tempmenu::drawMenuData(temp);
}
