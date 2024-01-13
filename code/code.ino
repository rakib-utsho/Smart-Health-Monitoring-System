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
