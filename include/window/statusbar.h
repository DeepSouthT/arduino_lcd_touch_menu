/*******************************
 * statusbar.h
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
 * Last modified: 01.06.2020
 *******************************/

#ifndef __STATUSBAR_H__
#define __STATUSBAR_H__

#include <UTFT.h>

class statusbar
{
  public:
  statusbar(UTFT& statusbarGLCD_): statusbarGLCD(statusbarGLCD_){};
  ~statusbar(){};

  //ToDo: return a status
  void drawStatusbar(void);

  void clearStatusbar(void);

  private:
  UTFT& statusbarGLCD;

  /// Static configuration
  const uint16_t window_sx = 0;
  const uint16_t window_sy = 0;
  const uint16_t window_ex = 319;
  const uint16_t window_ey = 30;
  const uint16_t default_colour = VGA_SILVER;
  
};

#endif //__STATUSBAR_H__
