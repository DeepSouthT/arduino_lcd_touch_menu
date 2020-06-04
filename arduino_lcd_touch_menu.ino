/*******************************
 * arduino_lcd_touch_menu.c
 *
 * Created: 22.09.2019 22:45:00
 * Author : DeepSouthT
 *
 * Used:
 *    IC > ATMega2560
 *    IDE > Arduino 1.8.10
 *    Programmer > Arduino
 *    Arduino Mega 2560
 *    ITDB02-3.2S V2 (AptoFun TFT 3.2 TFT LCD Touch) / TFT_320QVT_9341
 *    AptoFun TFT 3.2 Shield for 5v to 3.3v level shift
 * 
 * Description:
 *     Test application for multilevel menu tree
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
 *     
 * Last modified: 10.11.2019
 *******************************/

#include <UTFT.h>
#include <URTouch.h>

#include "statusbar.h"

// Initialize display
// ------------------
//UTFT myGLCD(ILI9341_16, 38, 39, 40, 41);
UTFT myGLCD(ITDB32S_V2, 38, 39, 40, 41);

// Initialize touchscreen
// ----------------------
URTouch  myTouch( 6, 5, 4, 3, 2);

statusbar statusbar_obj(myGLCD);

// Declare which fonts we will be using
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];

// Variables for the touch coordinates
int x_touch, y_touch;

// Icon
extern unsigned int arrowHeadR[0x23F];
extern unsigned int arrowHeadL[0x23F];
extern unsigned int house[0x866];
extern unsigned int temp_icon[0x1254];
extern unsigned int clockNeedle[0x9C4];
extern unsigned int doller[0x834];
extern unsigned int semicolon[0x172];
extern unsigned int centigrade[0x60C];
extern unsigned int german[0xB6C];
extern unsigned int canada[0xB41];
extern unsigned int settings[0xAF9];

/*************************
**   Custom functions   **
*************************/

// Function for drawing initial static areas
void initStaticArea(void)
{
  statusbar_obj.drawStatusbar();

  myGLCD.setColor(VGA_BLACK);
  myGLCD.fillRect (0, 31, 319, 239);
}

// Function for clearing the complete menu area
void clearMenuArea(void)
{
  myGLCD.setColor(VGA_BLACK);
  myGLCD.fillRect (0, 31, 319, 179);
}

// Function for drawing right button
void rightButton()
{
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (228, 180, 310, 230);
  myGLCD.drawBitmap(265, 194, 25, 23, arrowHeadR);

  myGLCD.setColor(10, 116, 255);
  myGLCD.fillRect (240, 200, 265, 210);
}

// Function for drawing left button
void leftButton()
{
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (10, 180, 92, 230);
  myGLCD.drawBitmap(25, 194, 25, 23, arrowHeadL);

  myGLCD.setColor(10, 116, 255);
  myGLCD.fillRect (50, 200, 75, 210);
}

// Function for drawing red button outline during the butten is pressed
void rightRedButton()
{
  myGLCD.setColor(255, 0, 0);
  myGLCD.drawRoundRect (228, 180, 310, 230);
  delay(150);
  while (myTouch.dataAvailable())
  {
    myTouch.read();
  }
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (228, 180, 310, 230);
}

// Function for drawing red button outline during the butten is pressed
void leftRedButton()
{
  myGLCD.setColor(255, 0, 0);
  myGLCD.drawRoundRect (10, 180, 92, 230);
  delay(150);
  while (myTouch.dataAvailable())
  {
    myTouch.read();
  }
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (10, 180, 92, 230);
}

// Function for drawing settings button
void settingsButton()
{
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (165, 180, 267, 230);
  myGLCD.drawBitmap(195, 190, 53, 53, settings);

  // myGLCD.setColor(10, 116, 255);
  // myGLCD.fillRect (187, 200, 205, 210);
}

void homeScreen()
{
  clearMenuArea();
  
  myGLCD.setColor(VGA_WHITE);
  myGLCD.setBackColor(VGA_BLACK);
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.print("10", 130, 55);
  myGLCD.drawBitmap(200, 60, 10, 37, semicolon);
  myGLCD.print("10", 209, 55);

  myGLCD.setFont(BigFont);
  myGLCD.print("01.10.2019", 130, 120);

  myGLCD.setColor(VGA_BLACK);
  myGLCD.fillRect (10, 70, 79, 138);
  myGLCD.drawBitmap(20, 85, 50, 43, house);
}

void tempScreen()
{
  clearMenuArea();
  
  myGLCD.drawBitmap(10, 70, 69, 68, temp_icon);

  myGLCD.setColor(VGA_BLACK);
  myGLCD.fillRect (85, 31, 319, 179);

  myGLCD.setColor(VGA_WHITE);
  myGLCD.setBackColor(VGA_BLACK);
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.print("22", 130, 55);
  myGLCD.drawBitmap(200, 60, 36, 43, centigrade);
}

void clockScreen()
{
  clearMenuArea();
  
  myGLCD.drawBitmap(20, 80, 50, 50, clockNeedle);

  myGLCD.setColor(VGA_BLACK);
  myGLCD.fillRect (85, 31, 319, 179);

  myGLCD.drawBitmap(130, 55, 68, 43, german);
  myGLCD.setColor(VGA_WHITE);
  myGLCD.setBackColor(VGA_BLACK);
  myGLCD.setFont(BigFont);
  myGLCD.print("XX", 210, 60);

  myGLCD.drawBitmap(130, 120, 67, 43, canada);
  myGLCD.print("XX", 210, 120);
}

void currencyScreen()
{
  clearMenuArea();
  
  myGLCD.drawBitmap(28, 75, 35, 60, doller);
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

/*************************
**  Required functions  **
*************************/

void setup() {

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Started");
  
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
  homeScreen();

  // Static screen areas
  rightButton();
  settingsButton();
  leftButton();
}

void loop() {

  if (myTouch.dataAvailable())
    {
      myTouch.read();
      x_touch = myTouch.getX();
      y_touch = myTouch.getY();

      if((y_touch > 180) && (y_touch < 230)) // Lower buttons
      {
        
        if((x_touch > 10) && (x_touch < 150)) // Left button
        {
          leftRedButton();
          stateChange(0);
          stateActive();
        }
        else if((x_touch > 170) && (x_touch < 310)) // Right button
        {
          rightRedButton();
          stateChange(1);
          stateActive();
        }
        else {
          // Do nothing
        }
       }
     }
}
