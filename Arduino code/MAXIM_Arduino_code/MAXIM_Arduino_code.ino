/*
This program Print temperature on terminal

Hardware Connections (Breakoutboard to Arduino):
Vin  - 5V
GND - GND
SDA - A4 (or SDA)
SCL - A5 (or SCL)
*/

#include <Wire.h>
#include "Protocentral_MAX30205.h"
MAX30205 tempSensor;

void setup() {

  Serial.begin(9600);
  Wire.begin();

  //scan for temperature in every 10 sec untill a sensor is found. Scan for both addresses 0x48 and 0x49
  while(!tempSensor.scanAvailableSensors()){
    Serial.println("Couldn't find the temperature sensor, please connect the sensor." );
    delay(10000);
  }

  tempSensor.begin();   // set continuos mode, active mode
}

void loop() {

	float temp = tempSensor.getTemperature(); // read temperature for every 100ms
	Serial.print(temp ,2);
	Serial.println("'c" );
	delay(100);
}
