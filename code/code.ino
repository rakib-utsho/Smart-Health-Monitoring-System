/*
 Setup your scale and start the sketch WITHOUT a weight on the scale
 Once readings are displayed place the weight on the scale
 Press +/- or a/z to adjust the calibration_factor until the output readings match the known weight
 Arduino pin 4 -> HX711 CLK
 Arduino pin 3 -> HX711 DOUT
 Arduino pin 5V -> HX711 VCC
 Arduino pin GND -> HX711 GND 
*/

#include "HX711.h"
#include <HCSR04.h>

HX711 scale(4, 3);
float calibration_factor = 2350; // this calibration factor is adjusted according to my load cell
float units;
float finalweight;
float duration;
float distance;
float Length;
float BMI;

void setup() {
  Serial.begin(9600);
  Serial.println("ready to read and please ensure the weight more than 1 Kg");
  pinMode(8, OUTPUT);
  pinMode(9, INPUT);

//  Serial.println("Remove all weight from scale");
//  Serial.println("After readings begin, place known weight on scale");
//  Serial.println("Press + or a to increase calibration factor");
//  Serial.println("Press - or z to decrease calibration factor");

  scale.set_scale(calibration_factor);
  scale.tare();  //Reset the scale to 0

 // long zero_factor = scale.read_average(); //Get a baseline reading
  //Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  //Serial.println(zero_factor);
}
