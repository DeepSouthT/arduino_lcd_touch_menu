/*******************************
 * arduino_lcd_touch_menu.c
 *
 * Created: 22.09.2019 22:45:00
 * Author : DeepSouthT
 *
 * Used:
 *    IC              > ATMega2560
 *    Board           > Arduino Mega 2560
 *    IDE             > Visual Studio Code 1.45.1
 *    PlugIn          > PlatformIo 1.3.0
 *    Programmer      > Arduino
 *    Display         > ITDB02-3.2S V2 (AptoFun TFT 3.2 TFT LCD Touch) / TFT_320QVT_9341
 *    Display adapter > AptoFun TFT 3.2 Shield for 5v to 3.3v level shift
 * 
 * Description:
 *     Sample application for multilevel menu tree
 *     
 *     ITDB02-3.2S V2 module is 3.2" TFT LCD with 65K color 320 x 240 resolutions
 *     The controller of this LCD module is ILI9341
 *     The controller supports 16bit data interface with control interface of four wires
 *     https://www.itead.cc/wiki/ITDB02-3.2S_Arduino_Shield_V2
 *     
 * Additional information:
 *     (240 xRGB)(H) x 320(V) dots
 *     262K color (262144 color) in 18 bit data
 *     In 16 bit, it is RGB565
 *     720 ch source drive (240 xRGB or 240 x 3 = 720 segments/colomns)
 *     320 ch gate drive
 *     172800 bytes GRAM (it is exactly one frane in 18 bit color mode)
 *     Memory band width: 30fps x 240 x 320 x 2.25 = 4,94 MBytes/sec
 *     
 *     The UTFT and URTouch libraries are from http://www.rinkydinkelectronics.com/index.php
 *
 * Version:
 *     0.1 > Basic menu with four screens (no image)
 *     0.2 > Basic menu with four screens with image
 *     0.3 > Migrating to VSCode + PlatformIO
 *     
 * Last modified: 09.07.2020
 *******************************/

#include <Arduino.h>
#include <UTFT.h>
#include <URTouch.h>

#include "window/globalConfig.h"

#include "window/statusbar.h"
#include "window/navigationbar.h"
#include "window/homeMenu.h"
#include "window/tempMenu.h"
#include "window/clockMenu.h"
#include "window/currencyMenu.h"

// Initialize display
// ------------------
//UTFT myGLCD(ILI9341_16, 38, 39, 40, 41);
UTFT myGLCD(ITDB32S_V2, 38, 39, 40, 41);

// Initialize touchscreen
// ----------------------
URTouch  myTouch( 6, 5, 4, 3, 2);

statusbar statusbar_obj(myGLCD);
navigationbar navigationbar_obj(myGLCD, myTouch);
homemenu homemenu_obj(myGLCD);
tempmenu tempmenu_obj(myGLCD);
clockmenu clockmenu_obj(myGLCD);
currencymenu currencymenu_obj(myGLCD);

// Declare which fonts we will be using
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];

// Variables for the touch coordinates
int x_touch, y_touch;

bool update_home_data = false;
bool update_clock_data = false;
bool update_currency_data = false;
bool update_temp_data = false;

struct Local_time_t local_time;
uint8_t temperature = 22;
//struct Currency_rate_t currency_rate;

/*************************
**   Custom functions   **
*************************/

// Function for drawing initial static areas
void initStaticArea(void)
{
  statusbar_obj.clearStatusbar();
  navigationbar_obj.clearNavigationbar();
  
  navigationbar_obj.drawNavigationbar();
}

void homeScreen()
{
  homemenu_obj.drawMenu(local_time);
}

void tempScreen()
{
  tempmenu_obj.drawMenu(temperature);
}

void clockScreen()
{
  clockmenu_obj.drawMenu(local_time);
}

void currencyScreen()
{
  currencymenu_obj.drawMenu(currencymenu_obj.currency_rate);
}

// Collection of all screens
void (*stateAll[4])() = {homeScreen, tempScreen, clockScreen, currencyScreen};
// Totel number of screens
unsigned int statAll_count = sizeof(stateAll)/sizeof(stateAll[0]);
// Function pointer pointing to the current screen
void (*stateActive)(void);
// Index for scrolling through the available screens
int stateActiveIndex = 0;

// Function to change the active screen on button press
void stateChange(int input)
{
  if(input == 1)
  {
    stateActiveIndex++;
    stateActiveIndex = stateActiveIndex%statAll_count;
    stateActive = stateAll[stateActiveIndex];
    Serial.println("++");
    Serial.println(stateActiveIndex);
  }else if(input == 0)
  {
    stateActiveIndex--;
    if(stateActiveIndex < 0)
    {
      stateActiveIndex = stateActiveIndex + statAll_count;
    }
    stateActiveIndex = stateActiveIndex%statAll_count;
    stateActive = stateAll[stateActiveIndex];
    Serial.println("--");
    Serial.println(stateActiveIndex);
  }
  else
  {
    stateActiveIndex = 0;
    stateActive = stateAll[stateActiveIndex];
    Serial.println("??");
    Serial.println(stateActiveIndex);
  }
}

ISR(TIMER1_COMPA_vect)
{
  /// Time
  if (local_time.loc_time_sec < 59)
  {
    local_time.loc_time_sec++;
  } else {
    local_time.loc_time_sec = 0;
    if(local_time.loc_time_min < 59)
    {
      local_time.loc_time_min++;
    } else {
      local_time.loc_time_min = 0;
      if(local_time.loc_time_hr < 23)
      {
        local_time.loc_time_hr++;
      } else { local_time.loc_time_hr = 0;}
    }
  }

  /// Temperature
  if(local_time.loc_time_sec == 30)
  {
    temperature = 31;
  } else {
    temperature = 28;
  }

  update_home_data = true;
  update_clock_data = true;
  update_temp_data = true;
}

/*************************
**  Required functions  **
*************************/

void setup() {

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Started");

  currencymenu_obj.currency_rate.euro_de_rate = 55;
  currencymenu_obj.currency_rate.doller_ca_rate = 44;

  //stop interrupts
  cli();

  //set timer1 interrupt at 1Hz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12 and CS10 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);

  //allow interrupts
  sei();
  
  // Initial setup
  myGLCD.InitLCD();
  myGLCD.clrScr();

  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);

  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(0, 0, 255);

  myGLCD.setBrightness(16); // default/max is 16

  // Initialize static areas
  initStaticArea();
  
  // Start screen
  homemenu_obj.drawMenu(local_time);
}

void loop() {

  if (myTouch.dataAvailable())
    {
      myTouch.read();
      x_touch = myTouch.getX();
      y_touch = myTouch.getY();

      if((y_touch > 180) && (y_touch < 230)) // Lower buttons
      {
        
        if((x_touch > 10) && (x_touch < 113)) // Left button
        {
          navigationbar_obj.leftRedButton();
          stateChange(0);
          stateActive();
        }
        else if((x_touch > 114) && (x_touch < 226)) // Settings button
        {
          navigationbar_obj.settingsRedButton();
          //stateChange(1);
          //stateActive();
        }
        else if((x_touch > 227) && (x_touch < 339)) // Right button
        {
          navigationbar_obj.rightRedButton();
          stateChange(1);
          stateActive();
        }
        else {
          // Do nothing
        }
       }
     }

  if ((update_home_data)&&(stateActiveIndex == 0))
  {
    homemenu_obj.deawTime(local_time);
    update_home_data = false;
  } else if ((update_temp_data)&&(stateActiveIndex == 1))
  {
    tempmenu_obj.drawTemp(temperature);
    update_temp_data = false;
  } else if ((update_clock_data)&&(stateActiveIndex == 2))
  {
    update_clock_data = false;
    clockmenu_obj.deawTime(local_time);
  } else if ((update_currency_data)&&(stateActiveIndex == 3))
  {
    update_currency_data = false;
    currencymenu_obj.drawCurrency(currencymenu_obj.currency_rate);
  }
}
