/*******************************
 * currencyMenu.cpp
 *
 * Created: 10.06.2020 22:38:00
 * Author : DeepSouthT
 *
 * Used:
 *    ToDo
 * 
 * Description:
 *     Currency menu
 *     This includes all its configurations
 *
 * Last modified: 09.07.2020
 *******************************/

 #include "window/currencyMenu.h"

void currencymenu::drawMenuHead(void)
{
  menu::drawMenuHead(currencymenuGLCD);
  currencymenuGLCD.drawBitmap((window_head_sx + 10), (window_head_sy + 49), 35, 60, doller);
} 

void currencymenu::drawCurrency(Currency_rate_t currency_rate)
{
  currencymenuGLCD.setColor(VGA_WHITE);
  currencymenuGLCD.setBackColor(VGA_BLACK);
  currencymenuGLCD.setFont(BigFont);

  char str[2];
  sprintf(str, "%02d", currency_rate.euro_de_rate);
  currencymenuGLCD.print(str, (window_data_sx + 158), (window_data_sy + 29));
  sprintf(str, "%02d", currency_rate.doller_ca_rate);
  currencymenuGLCD.print(str, (window_data_sx + 158), (window_data_sy + 94));
}

void currencymenu::drawMenuData(Currency_rate_t currency_rate)
{
  menu::drawMenuData(currencymenuGLCD);

  currencymenuGLCD.drawBitmap((window_data_sx + 78), (window_data_sy + 24), 68, 43, german);
  currencymenuGLCD.drawBitmap((window_data_sx + 78), (window_data_sy + 89), 67, 43, canada);

  drawCurrency(currency_rate);
}

void currencymenu::drawMenu(Currency_rate_t currency_rate)
{
  currencymenu::drawMenuHead();
  currencymenu::drawMenuData(currency_rate);
}
