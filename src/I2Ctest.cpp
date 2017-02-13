#include "Arduino.h"
#include "Wire.h"
#define cn75address 0x48 // with pins 5~7 set to GND, the device address is 0x48
#define slaveAddress 0x0B
int output;
byte a,b;
byte buffer[2];

void setup()
{
  Wire.begin(); // wake up I2C bus
  Serial.begin(9600);
}

void loop()
{

  Wire.beginTransmission(slaveAddress);
  // Wire.write(0x00);
  Wire.write(0x09);
  Wire.endTransmission();
  Wire.requestFrom(slaveAddress, 2);
  a = Wire.read(); // first received byte stored here
  b = Wire.read();

  Serial.print("voltage:");
  output = a;
  output |= b<<8;
  Serial.println(output);

  // delay(10);
  //
  // Wire.beginTransmission(slaveAddress);
  // Wire.write(0x08);
  // Wire.endTransmission();
  // Wire.requestFrom(slaveAddress, 2);
  // a = Wire.read(); // first received byte stored here
  // b = Wire.read();
  //
  // Serial.print("current:");
  // output = a;
  // output |= b<<8;
  // Serial.println(output);

}
