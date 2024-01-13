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

void loop(){

  Serial.print("Reading: ");
  units = scale.get_units(10), 2;
  //units = (units*0.454)-0.02;
  //Serial.print(units);
  if (units < 0)
  {
    units = 0.00;
    //Serial.print(units);
    //Serial.print("please enter the weight more then 1 kg");
    
  }
  else{
    units = ((units*0.454)-0.02)/2;
    
  }
  digitalWrite(8, LOW);        
  delayMicroseconds(2);              
  digitalWrite(8, HIGH);
  delayMicroseconds(10);           
  digitalWrite(8, LOW);
  duration = pulseIn(9, HIGH);
  distance = duration*0.0343/2;
  Length =  ((180 - distance)/100);

  BMI= (units/(Length*Length));

  Serial.print("Length: ");
  Serial.print(Length);
  Serial.print("m");
  Serial.println();
  Serial.print("weight: ");
  Serial.print(units);
  Serial.print(" KG");
  Serial.println();
  Serial.print("BMI: ");
  Serial.print(BMI); 
 // Serial.print(" calibration_factor: ");
 // Serial.print(calibration_factor);
  Serial.println();
  delay(1000);

 if(BMI<=18.4){
    Serial.println("You are in Underweight");
    Serial.println("A healthy diat chart for you");
    Serial.println("1. Eat more often.");
    Serial.println("2. Drink Milk.");
    Serial.println("3. Get Quality Sleep");
    Serial.println("4. Eat Fruits.");   
    }

else if  (BMI>18.4 && BMI<=24.9){
    Serial.println("You are Healthy");
    Serial.println("A healthy diat chart for you");
    Serial.println("1. Eat healthy food");
    Serial.println("2. Drink Water");
    Serial.println("3. Drink Milk");
    Serial.println("4. Eat more Vegetables");
}

else if (BMI>=25.0 && BMI<=29.9){
    Serial.println("You are Overweight");
    Serial.println("A healthy diat chart for you");
    Serial.println("1. Eat high fibre foods");
    Serial.println("2. Do not stock junk food");
    Serial.println("3. Plan your meals");
    Serial.println("4. Cut down on alcohol");
}

else if(BMI>=30){
    Serial.println("You are Obsee");
    Serial.println("A healthy diat chart for you");
    Serial.println("1. Eat more vegetables - add them at every meal.");
    Serial.println("2. Try eating off smaller plates so as to eat smaller portions");
    Serial.println("3. Choose minimally processed, whole foods");
    Serial.println("4. Drink water or other beverages that are naturally calorie-free");
}
//  if(Serial.available())
//  {
//    char temp = Serial.read();
//    Serial.println("temp"+temp);
//    Serial.println(temp);
//    if(temp == '+' || temp == 'a')
//      calibration_factor += 1;
//    else if(temp == '-' || temp == 'z')
//      calibration_factor -= 1;
//  }
//  if(Serial.available())
//  {
//    char temp = Serial.read();
//    if(temp == 't' || temp == 'T')
//      scale.tare();
//  }
}
 
