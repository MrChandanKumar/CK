/**
 *   DOUBLE EFFECT ANIMATION CHECK USING CK_MAX LIBRARY
 *   -------------------------------------------------
 *   EXAMPLE OF VERSION : 4.0
 *   
 *   AUTHOR : CHANDAN KUMAR MONDAL
 *   DATE   : 04/06/2020
 */

// MAIN LIBRARY
#include<CK_MAX.h>

// USER DEFINED SPI (CHOICE OF YOUR OWN)
#define DATA_PIN 11
#define CLOCK_PIN 13
#define CS_PIN 10
// NUMBER OF DISPLAY USED
#define NUMBER_OF_DEVICE 1

// CREATE AN OBJECT
CK_MAX my_display(DATA_PIN, CLOCK_PIN, CS_PIN, NUMBER_OF_DEVICE);

void setup(){
  //TAKE A SHROTCUT
  //my_display.DefaultSettings();
  my_display.begin();
  my_display.Set_Position(0);
}

void loop(){
  //PRINT THE GIVEN CONTENT
  /**
   *     object_name.AnimateMe(param1, param2, param3, param4, param5, param6);
   *     
   *     param1 - Data. That will be displyed in the display. But careful, it must be in 'String' form
   *     param2 - Data entry Effect's Name
   *     param3 - Data exit Effect's Name
   *     param4 - Entry Effect's rendering delay
   *     param5 - Exit Effect's rendering delay
   *     param6 - Pause time, Exit Effect work just after this time.
   *     
   *     EXAMPLE:
   *     my_display.AnimateMe("HELLO", SCROLL_UP, MAKE_BUFFER, 200, 200, 1000);
   */
  my_display.AnimateMe("HELLO", SCROLL_UP, SCROLL_DOWN,30,30,500);
  my_display.AnimateMe("Chandan", SCROLL_DOWN, SCROLL_UP,30,30,500);
  my_display.AnimateMe("HELLO", SCROLL_UP, SCROLL_UP,30,30,500);
  my_display.AnimateMe("PEOPLE", SCROLL_DOWN, SCROLL_DOWN,30,30,500);
  my_display.AnimateMe("PI Equal", RAND_UP, RAND_UP,50,50,500);
  my_display.AnimateMe("3.1416", MAKE_BUFFER, BREAK,40,20,500);
  my_display.AnimateMe("4 JUNE", SLICE_OWN, SLICE_ALL,30,20,500);
  my_display.AnimateMe("2020", BREAK, BREAK,40,20,500);
  my_display.AnimateMe("Error", MAKE_BUFFER, MAKE_BUFFER,40,50,500);
  my_display.AnimateMe("Arduino", BREAK, WAVE, 50, 70, 500),
  my_display.AnimateMe("12345678", RANDOMIZED, RANDOMIZED, 30, 100, 1000),
  my_display.AnimateMe("0123456789ABCDEF", SCROLL_LEFT, SCROLL_RIGHT, 200,100,20);
}