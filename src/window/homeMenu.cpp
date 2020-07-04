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
 * Last modified: 02.07.2020
 *******************************/

 #include "window/homeMenu.h"


void homemenu::drawMenuHead(void)
{
  menu::drawMenuHead(homemenuGLCD);
  homemenuGLCD.drawBitmap((window_head_sx + 10), (window_head_sy + 54), 50, 43, house);
} 

void homemenu::deawTime(Local_time_t local_time)
{
  homemenuGLCD.setColor(VGA_WHITE);
  homemenuGLCD.setBackColor(VGA_BLACK);
  homemenuGLCD.setFont(SevenSegNumFont);

  char str[2];
  sprintf(str, "%02d", local_time.loc_time_hr);
  homemenuGLCD.print(str, (window_data_sx + 15), (window_data_sy + 24));
  homemenuGLCD.drawBitmap((window_data_sx + 85), (window_data_sy + 32), 10, 37, semicolon);
  sprintf(str, "%02d", local_time.loc_time_min);
  homemenuGLCD.print(str, (window_data_sx + 98), (window_data_sy + 24));
  homemenuGLCD.drawBitmap((window_data_sx + 168), (window_data_sy + 32), 10, 37, semicolon);
  sprintf(str, "%02d", local_time.loc_time_sec);
  homemenuGLCD.print(str, (window_data_sx + 182), (window_data_sy + 24));
}

void homemenu::drawMenuData(Local_time_t local_time)
{ 
  menu::drawMenuData(homemenuGLCD);

  homemenuGLCD.setColor(VGA_WHITE);
  homemenuGLCD.setBackColor(VGA_BLACK);
  homemenuGLCD.setFont(BigFont);
  homemenuGLCD.print("01.10.2019", (window_data_sx + 68), (window_data_sy + 89));

  homemenu::deawTime(local_time);
}

void homemenu::drawMenu(Local_time_t local_time)
{
  homemenu::drawMenuHead();
  homemenu::drawMenuData(local_time);
}
