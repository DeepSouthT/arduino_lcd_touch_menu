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
 *    ITDB02-3.2S V2 (AptoFun TFT 3.2 TFT LCD Touch)
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
 *
 * Last modified: 04.10.2019
 *******************************/

#include <UTFT.h>
#include <URTouch.h>

// Initialize display
// ------------------
UTFT myGLCD(ILI9341_16, 38, 39, 40, 41);

// Initialize touchscreen
// ----------------------
URTouch  myTouch( 6, 5, 4, 3, 2);

// Declare which fonts we will be using
extern uint8_t BigFont[];

// Variables for the touch coordinates
int x_touch, y_touch;

// Icon
extern unsigned int arrow_left[0x834];
extern unsigned int arrow_right[0x866];

/*************************
**   Custom functions   **
*************************/

// Function for drawing right button
void rightButton()
{
  myGLCD.setColor(0, 0, 255);
  myGLCD.fillRoundRect (170, 180, 310, 230);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (170, 180, 310, 230);
  myGLCD.setBackColor(0, 0, 255);
  myGLCD.print(">", 250, 197);
  myGLCD.drawLine(230, 204, 260, 204);
  myGLCD.drawLine(230, 205, 260, 205);
}

// Function for drawing left button
void leftButton()
{
  myGLCD.setColor(0, 0, 255);
  myGLCD.fillRoundRect (10, 180, 150, 230);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (10, 180, 150, 230);
  myGLCD.setBackColor(0, 0, 255);
  myGLCD.print("<", 55, 197);
  myGLCD.drawLine(60, 204, 90, 204);
  myGLCD.drawLine(60, 205, 90, 205);
}

// Function for drawing red button outline during the butten is pressed
void rightRedButton()
{
  myGLCD.setColor(255, 0, 0);
  myGLCD.drawRoundRect (170, 180, 310, 230);
  while (myTouch.dataAvailable())
  {
    myTouch.read();
  }
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (170, 180, 310, 230);
}

// Function for drawing red button outline during the butten is pressed
void leftRedButton()
{
  myGLCD.setColor(255, 0, 0);
  myGLCD.drawRoundRect (10, 180, 150, 230);
  while (myTouch.dataAvailable())
  {
    myTouch.read();
  }
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (10, 180, 150, 230);
}

void homeScreen()
{
  myGLCD.setColor(VGA_SILVER);
  myGLCD.fillRect (0, 0, 319, 30);
  myGLCD.setBackColor(VGA_SILVER);
  myGLCD.setColor(VGA_BLACK);
  myGLCD.print("HOME", 130, 7);
}

void tempScreen()
{
  myGLCD.setColor(VGA_SILVER);
  myGLCD.fillRect (0, 0, 319, 30);
  myGLCD.setBackColor(VGA_SILVER);
  myGLCD.setColor(VGA_BLACK);
  myGLCD.print("TEMPERATURE", 80, 7);
}

void clockScreen()
{
  myGLCD.setColor(VGA_SILVER);
  myGLCD.fillRect (0, 0, 319, 30);
  myGLCD.setBackColor(VGA_SILVER);
  myGLCD.setColor(VGA_BLACK);
  myGLCD.print("CLOCK", 120, 7);
}

void currencyScreen()
{
  myGLCD.setColor(VGA_SILVER);
  myGLCD.fillRect (0, 0, 319, 30);
  myGLCD.setBackColor(VGA_SILVER);
  myGLCD.setColor(VGA_BLACK);
  myGLCD.print("CURRENCY", 100, 7);
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
    stateActiveIndex = stateActiveIndex%4;
    stateActive = stateAll[stateActiveIndex];
  }else if(input == 0)
  {
    stateActiveIndex--;
    if(stateActiveIndex < 0)
    {
      stateActiveIndex = stateActiveIndex + statAll_count;
    }
    stateActiveIndex = stateActiveIndex%4;
    stateActive = stateAll[stateActiveIndex];
  }
  else
  {
    stateActiveIndex = 0;
    stateActive = stateAll[stateActiveIndex];
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

  // Start screen
  homeScreen();

  // Static screen areas
  rightButton();
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
