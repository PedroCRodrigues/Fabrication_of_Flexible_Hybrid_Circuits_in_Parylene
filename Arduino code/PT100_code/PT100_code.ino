/*************************************************** 
  This is a library for the Adafruit PT100/P1000 RTD Sensor w/MAX31865
  Designed specifically to work with the Adafruit RTD Sensor
  ----> https://www.adafruit.com/products/3328
  This sensor uses SPI to communicate, 4 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!
  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/
#include <Adafruit_MAX31865.h>
// Use software SPI: CS, DI, DO, CLK
Adafruit_MAX31865 thermo = Adafruit_MAX31865(10, 11, 12, 13);
// use hardware SPI, just pass in the CS pin
//Adafruit_MAX31865 thermo = Adafruit_MAX31865(10);
#define RREF      430.0 // Rref resistor = 430.0 for PT100
// The 'nominal' 0-degree-C resistance of the sensor 100.0 for PT100
#define RNOMINAL  100.0

void setup() {
  Serial.begin(9600); // Comunication with "serial monitor" at a 9600 bits/s rate 
  Serial.println("Teste do módulo MAX31865 com PT100");
  thermo.begin(MAX31865_2WIRE);  // Because the measurment is performed with 2 wires in the PT100
}
void loop() {
  uint16_t rtd = thermo.readRTD();    //reads from the previous function
  
  Serial.print("RTD value: "); Serial.println(rtd); 
  float ratio = rtd;     
  ratio /= 32768;         // 2^15, 15 bits resolution
  Serial.print("Ratio = "); Serial.println(ratio,8);   
  Serial.print("Resistance = "); Serial.println(RREF*ratio,8);  // analogic resistance value
  Serial.print("Temperature = "); Serial.println(thermo.temperature(RNOMINAL, RREF)); // resistance value
 
 Serial.println();
 delay(1000);
}
