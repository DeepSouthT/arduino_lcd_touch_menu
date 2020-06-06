/*******************************
 * statusbar.c
 *
 * Created: 01.06.2020 21:48:00
 * Author : DeepSouthT
 *
 * Used:
 *    ToDo
 * 
 * Description:
 *     Status bar displayed at the top of the display
 *     This includes all its configurations
 *
 * Last modified: 04.06.2020
 *******************************/

 #include "window/statusbar.h"

 void statusbar::drawStatusbar(void)
 {
  statusbarGLCD.setColor(VGA_SILVER);
  statusbarGLCD.fillRect (0, 0, 319, 30);
  statusbarGLCD.setBackColor(VGA_SILVER);
  statusbarGLCD.setColor(VGA_BLACK);
 }
 
