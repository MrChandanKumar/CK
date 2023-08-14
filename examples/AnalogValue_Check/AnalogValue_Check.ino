/******
 * .......POTENTIOMETER VALUE............
 *  Example of "CK_MAX" Version : 1.0
 *  Author : Chandan Kumar Mondal
 *  Date : 28/04/2020
 */

 /// Include the Library....
 #include <CK_MAX.h>

 /**
            +-----------+--------+--------+--------+
			|  ARDUINO  |  MISO  |  MOSI  | CLOCK  |
			+-----------+--------+--------+--------+
			|    UNO    |   12   |   11   |   13   |
			|--------------------------------------|
			|    MEGA   |   50   |   51   |   52   |
			+--------------------------------------+
 */
 /// Create an Object name "my_display" and connect the "CS" or "LOAD" pin to 10
 #define LOAD 10
 CK_MAX my_display(LOAD);
 
 #define DIN 11
 #define CLK 13
 #define Number_of_Device 1
 // CK_MAX my_display(DIN, CLK, LOAD, Number_of_Device);

 /// Potentiometer Pin
 int Pot_pin = A5;
 
 void setup(){
  /// Take a shortcut
  //  my_display.DefaultSettings();
  /**
   * DefaultSettings() is equal to .... BCD -> DEACTIVE
   *                             Brightness -> HIGH
   *                             Shutdown   -> OFF (DEVICE IS ACTIVE)
   *                             Digit      -> ALL
   *        N.B : You Can Change this Settings Maually..
   *                             
   */
   
   /// update version
   my_display.begin();
   
   pinMode(Pot_pin, INPUT);
 }

 void loop(){
  int Pot_value = analogRead(Pot_pin);
  /// Set Position.... (Print from first digit)
  my_display.Set_Position(0);
  my_display.ShowMe(Pot_value);
 }

