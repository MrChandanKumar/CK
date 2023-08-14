/**
 *      BCD TEST USING ....CK_MAX..... EXAMPLE OF VERSION 2.1
 *      NOTE : IF YOU USE BCD MODE, YOU WOULDN'T USE STRING AND FLOAT NUMBER
 *      
 *      AUTHOR : CHANDAN KUMAR MONDAL
 *      DATE   : 04.05.2020
 
        SEE RESULT IN, CK_MAX/media/results/Result_of_BCD_Check.bmp
 */

#include <CK_MAX.h>

#define LOAD 10
#define NUMBER_OF_DEVICE 1

// CREATE AN OBJECT 
CK_MAX my_display(LOAD, NUMBER_OF_DEVICE);

void setup(){
  // my_display.DefaultSettings();
  /**
   *  IN DEFAULT SETTING.. 
   *  
   *   >BCD - DEACTIVE
   *   >BRIGHTNESS - MAXIMUM
   *   >DIGIT USED - ALL
   *   >SHUTDOWN - OFF
   *   >DISPLAY - NORMAL MODE 
   *   
   *    DISPLAY LOOK LIKE THIS
       +-------------------------------+
       |   |   |   |   |   |   |   |   |
       +-------------------------------+
   */
   
   // update version
   my_display.begin();
   
   my_display.BCD_mode(ACTIVE);
   /**
    *   NOW SETTINGS..
    *   
    *   >BCD - ACTIVE
    *   >BRIGHTNESS - MAXIMUM
    *   >DIGIT USED - ALL
    *   >SHUTDOWN - OFF
    *   >DISPLAY - NORMAL MODE     
    *   
    *   DISPLAY LOOK LIKE THIS
       +-------------------------------+
       | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
       +-------------------------------+
    */
    my_display.Set_Position(2);
    my_display.ShowMe(1234);
    /**
     *   DISPLAY LOOK LIKE THIS
       +-------------------------------+
       | 0 | 0 | 1 | 2 | 3 | 4 | 0 | 0 |
       +-------------------------------+ 
     */
}

void loop(){
  // EMPTY
}

