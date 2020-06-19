/*******************************
 * navigationbar.cpp
 *
 * Created: 07.06.2020 20:04:00
 * Author : DeepSouthT
 *
 * Used:
 *    ToDo
 * 
 * Description:
 *     Navigation bar displayed at the bottom of the display
 *     This includes all its configurations
 *
 * Last modified: 13.06.2020
 *******************************/

#include "window/navigationbar.h"
#include "window/globalConfig.h"

void navigationbar::rightButton(void)
{
  uint16_t sx_loc = r_button_sx + window_sx;
  uint16_t sy_loc = r_button_sy + window_sy;
  navigationbarGLCD.setColor(VGA_WHITE);
  navigationbarGLCD.drawRoundRect(sx_loc, sy_loc, (sx_loc + button_w), (sy_loc + button_h));
  navigationbarGLCD.drawBitmap((sx_loc + 17), (sy_loc + 7), 48, 36, arrowHeadR);

  //navigationbarGLCD.setColor(10, 116, 255);
  //navigationbarGLCD.fillRect ((sx_loc + 12), (sy_loc + 20), (sx_loc + 37), (sy_loc + 30));
}

void navigationbar::leftButton(void)
{
  uint16_t sx_loc = l_button_sx + window_sx;
  uint16_t sy_loc = l_button_sy + window_sy;
  navigationbarGLCD.setColor(VGA_WHITE);
  navigationbarGLCD.drawRoundRect (sx_loc, sy_loc, (sx_loc + button_w), (sy_loc + button_h));
  navigationbarGLCD.drawBitmap((sx_loc + 18), (sy_loc + 7), 48, 36, arrowHeadL);

  //navigationbarGLCD.setColor(10, 116, 255);
  //navigationbarGLCD.fillRect ((sx_loc + 40), (sy_loc + 20), (sx_loc + 65), (sy_loc + 30));
}

void navigationbar::rightRedButton(void)
{
  uint16_t sx_loc = r_button_sx + window_sx;
  uint16_t sy_loc = r_button_sy + window_sy;
  navigationbarGLCD.setColor(VGA_RED);
  navigationbarGLCD.drawRoundRect(sx_loc, sy_loc, (sx_loc + button_w), (sy_loc + button_h));
  delay(TOUCH_RESPONSE_DELAY);
  while (navigationbarTouch.dataAvailable())
  {
    navigationbarTouch.read();
  }
  navigationbarGLCD.setColor(VGA_WHITE);
  navigationbarGLCD.drawRoundRect(sx_loc, sy_loc, (sx_loc + button_w), (sy_loc + button_h));
}

void navigationbar::leftRedButton(void)
{
  uint16_t sx_loc = l_button_sx + window_sx;
  uint16_t sy_loc = l_button_sy + window_sy;
  navigationbarGLCD.setColor(VGA_RED);
  navigationbarGLCD.drawRoundRect(sx_loc, sy_loc, (sx_loc + button_w), (sy_loc + button_h));
  delay(TOUCH_RESPONSE_DELAY);
  while (navigationbarTouch.dataAvailable())
  {
    navigationbarTouch.read();
  }
  navigationbarGLCD.setColor(VGA_WHITE);
  navigationbarGLCD.drawRoundRect(sx_loc, sy_loc, (sx_loc + button_w), (sy_loc + button_h));
}

void navigationbar::settingsButton(void)
{
  uint16_t sx_loc = s_button_sx + window_sx;
  uint16_t sy_loc = s_button_sy + window_sy;
  navigationbarGLCD.setColor(VGA_WHITE);
  navigationbarGLCD.drawRoundRect(sx_loc, sy_loc, (sx_loc + button_w), (sy_loc + button_h));
  navigationbarGLCD.drawBitmap((sx_loc + 22), (sy_loc + 6), 43, 40, settings);
}

void navigationbar::settingsRedButton(void)
{
  uint16_t sx_loc = s_button_sx + window_sx;
  uint16_t sy_loc = s_button_sy + window_sy;
  navigationbarGLCD.setColor(VGA_RED);
  navigationbarGLCD.drawRoundRect(sx_loc, sy_loc, (sx_loc + button_w), (sy_loc + button_h));
  delay(TOUCH_RESPONSE_DELAY);
  while (navigationbarTouch.dataAvailable())
  {
    navigationbarTouch.read();
  }
  navigationbarGLCD.setColor(VGA_WHITE);
  navigationbarGLCD.drawRoundRect(sx_loc, sy_loc, (sx_loc + button_w), (sy_loc + button_h));
}

void navigationbar::drawNavigationbar(void)
 {
  navigationbar::rightButton();
  navigationbar::settingsButton();
  navigationbar::leftButton();
 }

 void navigationbar::clearNavigationbar(void)
 {
  navigationbarGLCD.setColor(default_colour);
  navigationbarGLCD.fillRect(window_sx, window_sy, window_ex, window_ey);
 }
