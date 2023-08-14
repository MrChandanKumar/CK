/**
 *      A SIMPLE THERMOMETER PROJECT USING "DHT" AND "CK_MAX" LIBRARY
 *      -------------------------------------------------------------
 *      
 *      AUTHOR : CHANDAN KUMAR MONDAL
 *      DATE   : 05 JUNE, 2020
 */

#include<CK_MAX.h>
#include<DHT.h>

// display's stuff
#define data_pin 3
#define clock_pin 4
#define cs_pin 5
#define number_of_div 1

// sensor's stuff
#define sensor_pin 7
#define sensor_type DHT22

// display object and sensor object
CK_MAX Thermometer(data_pin, clock_pin, cs_pin, number_of_div);
DHT sensor(sensor_pin,sensor_type);

// initilized the variables
float temperature = 0.0;
float humidity = 0.0;
String S_temp = "";
String S_humd = "";
uint32_t Current = 0;
void setup(){
  //Thermometer.DefaultSettings();
  Thermometer.begin();
  Thermometer.AutoRefresh(false);
  sensor.begin();
  Current = millis();
  Thermometer.Set_Position(0);
  randomSeed(analogRead(A5));
}

void loop(){
  temperature = random(0,50);
  humidity = random(0,100);

  S_temp = String (temperature)+"C";
  S_humd = String (humidity)+"%";

  Thermometer.AnimateMe(S_temp, MAKE, 20, 1000);

  if(Current+4000<millis()){
    Current = millis();
    Thermometer.AnimateMe(S_humd, BREAK, 20, 1000);
  } 
}

