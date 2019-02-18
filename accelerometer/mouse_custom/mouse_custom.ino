#include <Wire.h> // Must include Wire library for I2C
#include <SparkFun_MMA8452Q.h> // Includes the SFE_MMA8452Q library
#include <Mouse.h>

const int sensitivity = 1;  // Higher sensitivity value = slower mouse, should be <= about 500
int mouseClickFlag = 0;

int vx,vy,vxzero,vyzero;
bool zeroRead = false;

MMA8452Q accel;


void setup()
{
  Mouse.begin();
  Wire.begin();
  accel.init();
  Serial.begin(9600);
  Serial.print("ready");
}

void loop()
{
//  if(!zeroRead){
//    while(!accel.available())
//    {
//      Serial.print("not ready yet");
//    }
//    accel.read();
//    Serial.print("read");
//    vxzero = accel.cx;
//    vyzero = accel.cy;
//    printZero();
//    zeroRead = true;
//  }
  if(accel.available())
  {
    accel.read();
//    printCalculatedAccels();
    delay(10);
    Mousemove();
  }
}

void Mousemove()
{
  vx = (accel.cx+15)/sensitivity;
  vy = -(accel.cz-100)/sensitivity;
  
//  vx = (accel.cx-vxzero);
//  vy = -(accel.cy-vyzero);
  vx = (accel.cx)*10;
  vy = -(accel.cy)*10;

//  printZero();

  if(vx != 0)
  {
    Mouse.move(vx, 0, 0);  // move mouse on y axis
  }
  if(vy != 0)
  {
    Mouse.move(0, vy, 0);  // move mouse on y axis
  }
    
  printVals();
//  Mouse.move(accel.cx, -accel.cy, 0);  // move mouse on y axis
}

void printZero()
{
  Serial.print("xzero: ");
  Serial.print(vxzero);
  Serial.print("\t");
  Serial.print("yzero: ");
  Serial.print(vyzero);
  Serial.print("\t");
  Serial.println();
}

void printVals()
{
  Serial.println(); // Print new line every time.
  Serial.print("x: ");
  Serial.print(vx);
//  Serial.print("\t");
//  Serial.print("xzero: ");
//  Serial.print(vxzero);
  Serial.print("\t");
  Serial.print("accel x: ");
  Serial.print(accel.cx);
  Serial.print("\t");
  Serial.print("y: ");
  Serial.print(vy);
//  Serial.print("\t");
//  Serial.print("yzero: ");
//  Serial.print(vyzero);
  Serial.print("\t");
  Serial.print("accel y: ");
  Serial.print(accel.cy);
  Serial.print("\t");
  Serial.println(); // Print new line every time.
}

void printCalculatedAccels()
{ 
  Serial.print("x: ");
  Serial.print(accel.cx, 3);
  Serial.print("\t");
  Serial.print("y: ");
  Serial.print(accel.cy, 3);
  Serial.print("\t");
  Serial.print("z: ");
  Serial.print(accel.cz, 3);
  Serial.print("\t");
  Serial.println(); // Print new line every time.
}
/* HID Joystick Mouse Example
   by: Jim Lindblom
   date: 1/12/2012
   license: MIT License - Feel free to use this code for any purpose.
   No restrictions. Just keep this license if you go on to use this
   code in your future endeavors! Reuse and share.

   This is very simplistic code that allows you to turn the 
   SparkFun Thumb Joystick (http://www.sparkfun.com/products/9032)
   into an HID Mouse. The select button on the joystick is set up
   as the mouse left click. 
 */
