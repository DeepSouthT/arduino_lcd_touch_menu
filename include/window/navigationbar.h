/*******************************
 * navigationbar.cpp
 *
 * Created: 07.06.2020 21:13:00
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

#ifndef __NAVIGATIONBAR_H__
#define __NAVIGATIONBAR_H__

#include <UTFT.h>
#include <URTouch.h>

// Icon
extern unsigned int arrowHeadR[0x6C0];
extern unsigned int arrowHeadL[0x6C0];
extern unsigned int settings[0x6B8];

class navigationbar
{
  public:
  navigationbar(UTFT& navigationbarGLCD_, URTouch& navigationbarTouch_): navigationbarGLCD(navigationbarGLCD_), navigationbarTouch(navigationbarTouch_){};
  //navigationbar(UTFT& navigationbarGLCD_): navigationbarGLCD(navigationbarGLCD_){};
  ~navigationbar(){};

  //ToDo: return a status
  void drawNavigationbar(void);
  //
  void clearNavigationbar(void);
  // Function for drawing right button
  void rightButton(void);
  // Function for drawing left button
  void leftButton(void);
  // Function for drawing red button outline during the butten is pressed
  void rightRedButton(void);
  // Function for drawing red button outline during the butten is pressed
  void leftRedButton(void);
  // Function for drawing settings button
  void settingsButton(void);
  ///
  void settingsRedButton(void);

  private:
  UTFT& navigationbarGLCD;
  URTouch& navigationbarTouch;

  /// Static configuration : window
  const uint16_t window_sx = 0;
  const uint16_t window_sy = 189;
  const uint16_t window_ex = 319;
  const uint16_t window_ey = 239;
  const uint16_t default_colour = VGA_BLACK;
  /// Static configuration : button
  const uint16_t button_w = 82;
  const uint16_t button_h = 50;
  const uint16_t r_button_sx = 228;
  const uint16_t r_button_sy = 0;
  const uint16_t l_button_sx = 10;
  const uint16_t l_button_sy = 0;
  const uint16_t s_button_sx = 120;
  const uint16_t s_button_sy = 0;

};

#endif //__NAVIGATIONBAR_H__
