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
 * Last modified: 09.07.2020
 *******************************/

 #include "window/clockMenu.h"

void clockmenu::drawMenuHead(void)
{
  menu::drawMenuHead(clockmenuGLCD);
  clockmenuGLCD.drawBitmap((window_head_sx + 10), (window_head_sy + 49), 50, 50, clockNeedle);
} 

void clockmenu::deawTime(Local_time_t local_time)
{
  clockmenuGLCD.setColor(VGA_WHITE);
  clockmenuGLCD.setBackColor(VGA_BLACK);
  clockmenuGLCD.setFont(BigFont);

  char str[5];
  sprintf(str, "%02d", local_time.loc_time_hr);
  sprintf(str + strlen(str), ":");
  sprintf(str + strlen(str), "%02d", local_time.loc_time_min);
  clockmenuGLCD.print(str, (window_data_sx + 158), (window_data_sy + 29));
  sprintf(str, "%02d", local_time.loc_time_hr);
  sprintf(str + strlen(str), ":");
  sprintf(str + strlen(str), "%02d", (local_time.loc_time_min + 4));
  clockmenuGLCD.print(str, (window_data_sx + 158), (window_data_sy + 94));
}

void clockmenu::drawMenuData(Local_time_t local_time)
{
  menu::drawMenuData(clockmenuGLCD);

  clockmenuGLCD.drawBitmap((window_data_sx + 78), (window_data_sy + 24), 68, 43, german);
  clockmenuGLCD.drawBitmap((window_data_sx + 78), (window_data_sy + 89), 67, 43, canada);
  
  clockmenu::deawTime(local_time);
}

void clockmenu::drawMenu(Local_time_t local_time)
{
  clockmenu::drawMenuHead();
  clockmenu::drawMenuData(local_time);
}
