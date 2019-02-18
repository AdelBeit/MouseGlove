#include <Wire.h> // Must include Wire library for I2C
#include <SparkFun_MMA8452Q.h> // Includes the SFE_MMA8452Q library
#include <Mouse.h> // control mouse

MMA8452Q accel; // accelerometer object

int vx,vy; // mouse velocity in x y directions

void setup() {
  Wire.begin();
  Mouse.begin();

  Serial.begin(9600);
  Serial.println("Glove mouse!");

  accell.init(); 
  
}

void loop() {
  if (accel.available())
  {
    accel.read();

    

    delay(100);
  }
}

// move mouse
void Mousemove()
{
  vx = (accel.cx+15)/150;
  vy = -(accel.cz-100)/150;
  
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
}
