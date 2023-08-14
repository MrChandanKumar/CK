/**
 *    20 EFFECTS CHECK OF CK_MAX
 *    VERSION : 4.1
 *    AUTHOR : CHANDAN KUMAR MONDAL
 *    DATA   : 9 JUNE 2020 (4.0)
      DATE   : 20 JUNE 2020 (4.1)
 */

#include<CK_MAX.h>

#define VCC 3
#define GND 4
#define DIN 5
#define CS  6
#define CLK 7

#define NUMBER_OF_DEVICE 1

CK_MAX d(VCC, GND, DIN, CS, CLK, NUMBER_OF_DEVICE);
// CK_MAX d(DIN, CLK, CS, NUMBER_OF_DEVICE);

void setup(){
  d.begin();
  d.Set_Brightness(3);
  d.Set_Position(1);
}

void loop(){
  // EFFECT 1
  d.AnimateMe("EFF.-01", SCROLL_LEFT, 200);
  // EFFECT 2
  d.AnimateMe("EFF.-02", SCROLL_RIGHT, 200);
  // EFFECT 3
  d.AnimateMe("EFF.-03", SCROLL_UP, SCROLL_UP, 100, 100, 1000);
  // EFFECT 4
  d.AnimateMe("EFF.-04", SCROLL_DOWN, SCROLL_DOWN, 200, 100, 1000);
  // EFFECT 5
  d.AnimateMe("EFF.-05", SCROLL_UP_SINGLE, SCROLL_UP_SINGLE, 100, 100, 1000);
  // EFFECT 6
  d.AnimateMe("EFF.-06", SCROLL_DOWN_SINGLE, SCROLL_DOWN_SINGLE, 200, 100, 1000);
  // EFFECT 7
  d.AnimateMe("EFF.-07", SCROLL_UP_RANDOM, SCROLL_UP_RANDOM, 100, 80, 1000);
  // EFFECT 8
  d.AnimateMe("EFF.-08", SCROLL_DOWN_RANDOM, SCROLL_DOWN_RANDOM, 100,  00, 1000);
  // EFFECT 9
  d.AnimateMe("EFF.-09", SCAN_TOP, SCAN_TOP, 100, 100, 1000);
  // EFFECT 10
  d.AnimateMe("EFF.-10", SCAN_BOTTOM, SCAN_BOTTOM, 100, 50, 1000);
  // EFFECT 11
  d.AnimateMe("EFF.-11", RAND_UP, RAND_UP, 100, 100, 1000);
  // EFFECT 12
  d.AnimateMe("EFF.-12", RAND_DOWN, RAND_DOWN, 100, 100, 1000);
  // EFFECT 13
  
  // uncomment this for changing buffer count from 3 to -- 
  // mydisplay.Set_Buffer_Count(4);
  
  d.AnimateMe("EFF.-13", MAKE_BUFFER, MAKE_BUFFER, 100, 50, 3000);
  // EFFECT 14
  d.AnimateMe("EFF.-14", SLICE_OWN, SLICE_OWN, 50, 80, 2000);
  // EFFECT 15
  d.AnimateMe("EFF.-15", SLICE_ALL, SLICE_ALL, 100, 100, 3000);
  // EFFECT 16
  d.AnimateMe("EFF.-16", MAKE, MAKE, 50, 100, 2000);
  // EFFECT 17
  d.AnimateMe("EFF.-17", WAVE, WAVE, 100, 100, 2000);
  // EFFECT 18
  d.AnimateMe("EFF.-18", BREAK, BREAK, 100, 100, 2000);
  // EFFECT 19
  d.AnimateMe("EFF.-19", GROW_UP, GROW_UP, 200,100,2000);
  // EFFECT 20
  d.AnimateMe("EFF.-20", GROW_DOWN, GROW_DOWN, 200,100, 2000);
  // EFFECT 21
  d.AnimateMe("EFF.-21", RANDOMIZED, RANDOMIZED, 100,100, 2000);
}