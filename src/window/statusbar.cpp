/*******************************
 * statusbar.cpp
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
  statusbarGLCD.setColor(default_colour);
  statusbarGLCD.fillRect (0, 0, 319, 30);
 }
 
 void statusbar::clearStatusbar(void)
 {
  statusbarGLCD.setColor(default_colour);
  statusbarGLCD.fillRect(window_sx, window_sy, window_ex, window_ey);
 }
