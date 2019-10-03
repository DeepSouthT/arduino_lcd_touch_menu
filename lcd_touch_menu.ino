// Test for LCD menu tree
// 20190922 22:45
// 
// ITDB02-3.2S V2 module is 3.2" TFT LCD with 65K color 320 x 240 resolutions
// The controller of this LCD module is ILI9341
// The controller supports 16bit data interface with control interface of four wires
// https://www.itead.cc/wiki/ITDB02-3.2S_Arduino_Shield_V2
//
// The used libraries are from http://www.rinkydinkelectronics.com/index.php
//

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

int x_touch, y_touch;

/*************************
**   Custom functions   **
*************************/

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

void homeWindow()
{
  myGLCD.setColor(VGA_SILVER);
  myGLCD.fillRect (0, 0, 319, 30);
  myGLCD.setBackColor(VGA_SILVER);
  myGLCD.setColor(VGA_BLACK);
  myGLCD.print("HOME", 130, 7);
  
  myGLCD.setColor(0, 0, 255);
  myGLCD.fillRoundRect (10, 180, 150, 230);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (10, 180, 150, 230);
  myGLCD.setBackColor(0, 0, 255);
  myGLCD.print("<", 55, 197);
  myGLCD.drawLine(60, 204, 90, 204);
  myGLCD.drawLine(60, 205, 90, 205);
  
  myGLCD.setColor(0, 0, 255);
  myGLCD.fillRoundRect (170, 180, 310, 230);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (170, 180, 310, 230);
  myGLCD.setBackColor(0, 0, 255);
  myGLCD.print(">", 250, 197);
  myGLCD.drawLine(230, 204, 260, 204);
  myGLCD.drawLine(230, 205, 260, 205);
  
  myGLCD.setBackColor (0, 0, 0);
}

void tempWindow()
{
  myGLCD.setColor(VGA_SILVER);
  myGLCD.fillRect (0, 0, 319, 30);
  myGLCD.setBackColor(VGA_SILVER);
  myGLCD.setColor(VGA_BLACK);
  myGLCD.print("TEMPERATURE", 80, 7);
  
  myGLCD.setColor(0, 0, 255);
  myGLCD.fillRoundRect (10, 180, 150, 230);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (10, 180, 150, 230);
  myGLCD.setBackColor(0, 0, 255);
  myGLCD.print("<", 55, 197);
  myGLCD.drawLine(60, 204, 90, 204);
  myGLCD.drawLine(60, 205, 90, 205);
  
  myGLCD.setColor(0, 0, 255);
  myGLCD.fillRoundRect (170, 180, 310, 230);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (170, 180, 310, 230);
  myGLCD.setBackColor(0, 0, 255);
  myGLCD.print(">", 250, 197);
  myGLCD.drawLine(230, 204, 260, 204);
  myGLCD.drawLine(230, 205, 260, 205);
  
  myGLCD.setBackColor (0, 0, 0);
}

void clockWindow()
{
  myGLCD.setColor(VGA_SILVER);
  myGLCD.fillRect (0, 0, 319, 30);
  myGLCD.setBackColor(VGA_SILVER);
  myGLCD.setColor(VGA_BLACK);
  myGLCD.print("CLOCK", 120, 7);
  
  myGLCD.setColor(0, 0, 255);
  myGLCD.fillRoundRect (10, 180, 150, 230);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (10, 180, 150, 230);
  myGLCD.setBackColor(0, 0, 255);
  myGLCD.print("<", 55, 197);
  myGLCD.drawLine(60, 204, 90, 204);
  myGLCD.drawLine(60, 205, 90, 205);
  
  myGLCD.setColor(0, 0, 255);
  myGLCD.fillRoundRect (170, 180, 310, 230);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (170, 180, 310, 230);
  myGLCD.setBackColor(0, 0, 255);
  myGLCD.print(">", 250, 197);
  myGLCD.drawLine(230, 204, 260, 204);
  myGLCD.drawLine(230, 205, 260, 205);
  
  myGLCD.setBackColor (0, 0, 0);
}

void currencyWindow()
{
  myGLCD.setColor(VGA_SILVER);
  myGLCD.fillRect (0, 0, 319, 30);
  myGLCD.setBackColor(VGA_SILVER);
  myGLCD.setColor(VGA_BLACK);
  myGLCD.print("CURRENCY", 100, 7);
  
  myGLCD.setColor(0, 0, 255);
  myGLCD.fillRoundRect (10, 180, 150, 230);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (10, 180, 150, 230);
  myGLCD.setBackColor(0, 0, 255);
  myGLCD.print("<", 55, 197);
  myGLCD.drawLine(60, 204, 90, 204);
  myGLCD.drawLine(60, 205, 90, 205);
  
  myGLCD.setColor(0, 0, 255);
  myGLCD.fillRoundRect (170, 180, 310, 230);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (170, 180, 310, 230);
  myGLCD.setBackColor(0, 0, 255);
  myGLCD.print(">", 250, 197);
  myGLCD.drawLine(230, 204, 260, 204);
  myGLCD.drawLine(230, 205, 260, 205);
  
  myGLCD.setBackColor (0, 0, 0);
}
void (*stateAll[4])() = {homeWindow, tempWindow, clockWindow, currencyWindow};

void (*stateActive)(void);
int stateActiveIndex = 0;

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
    stateActiveIndex = stateActiveIndex + 4;
    Serial.print("stateActiveIndex-- :");
    Serial.println(stateActiveIndex);
    stateActiveIndex = stateActiveIndex%4;
    Serial.print("stateActiveIndex%4 :");
    Serial.println(stateActiveIndex);
    stateActive = stateAll[stateActiveIndex];
  }
  else
  {
    
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

  myGLCD.setBrightness(15); // default is 16
  
  homeWindow();
  //tempWindow();
  //clockWindow();
  //currencyWindow();
}

void loop() {
  //homeWindow();
  //delay(3000);
  //tempWindow();
  //delay(3000);
  //clockWindow();
  //delay(3000);
  //currencyWindow();
  //delay(3000);

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
        else { }
      }
    }
}
