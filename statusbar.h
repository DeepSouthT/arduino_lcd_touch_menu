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

  private:
  UTFT& statusbarGLCD;
  
};

#endif //__STATUSBAR_H__
