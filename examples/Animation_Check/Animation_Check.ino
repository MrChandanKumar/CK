/**
 *          ANIMATION CHECK OF CK_MAX LIBRARY
 *          EXAMPLE OF VERSION 3.1
 *          DATE     : 27. 05. 2020
            MODIFIED : 30. 05. 2020
			MODIFIED : 13. 07. 2020
 
 *          AUTHOR : CHANDAN KUMAR MONDAL
            
 *          FOR ANMATION PERPOSE, JUST USE ONE FUNCTION, AnimateMe...
         
 *          #TYPE : ONE
           +-----------------------------------------------+
           | object_name.AnimateMe(param1, param2, param3) |
           +-----------------------------------------------+
            param1 --> HERE IS THE DATA, MUST BE IN STRING FORM
            param2 --> ANIMATION NAME
                         - SUPPORTED EFFECTS
                         * SCROLL_LEFT * SCROLL_RIGHT
            param3 --> HERE IS THE SCROLLING SPEED
            
 *          #TYPE : TWO
           +-------------------------------------------------------+
           | object_name.AnimateMe(param1, param2, param3, param4) |
           +-------------------------------------------------------+
            param1 --> SAME AS PREVIOUS
            param2 --> ANIMATION NAME
                         - SUPPORTED EFFECTS (ALL)
            param3 --> RANDERING SPEED, FOR (SCROLL_LEFT and SCROLL_RIGHT, IT CONSIDERED AS SCROLLING SPEED
            param4 --> HOLDING TIME, AFTER CROSSING THIS DURATION DIPLAY WILL BE CLEARED

 *          #TYPE : THREE
           +---------------------------------------------------------------+
           | object_name.AnimateMe(param1, param2, param3, param4, param5) |
           +---------------------------------------------------------------+
            param1 --> SAME AS PREVIOUS
            param2 --> ANIMATION NAME
                         - SUPPORTED EFFECTS
                         * MAKE_BUFFER
		        param3 --> SPIN NUMBER (DEFAULT IT IS 3)
            param4 --> RANDERING SPEED
            param5 --> HOLDING TIME, AFTER CROSSING THIS DURATION DIPLAY WILL BE CLEARED

			
 */
 
/// MAIN HEADER FILE
#include <CK_MAX.h>

/// CREATE AN OBJECT
#define LOAD 10
CK_MAX d(LOAD);



/// STRUCTURE OF PARAMETERS
struct myAnimation{
 String Text;
 All_Animations Effect;
 uint16_t Scroll_Step_duration;
 uint16_t hold_duration;
};

/// PARAMETER'S CONTENTS
myAnimation Contents[]{
  {"HELLO", SCROLL_LEFT, 100, 0},
  {"CHANDAN", SCROLL_RIGHT, 100, 0},
  {"HELLO", SCROLL_UP, 50, 500},
  {"Arduino",MAKE, 100, 500},
  {"uno", MAKE_BUFFER, 100, 500},
  {"27-05-20", SCROLL_DOWN, 50, 500},
  {"10553", SLICE_ALL, 50, 500},
  {"65.342", SLICE_OWN, 50, 500},
  {"error", MAKE_BUFFER, 50, 500},
  {"ABC123", RAND_UP, 50, 500},
  {"ABC123", RAND_DOWN, 50, 500},
  {"SCAN", SCAN_TOP, 50, 500},
  {"SCAN", SCAN_BOTTOM, 50, 500},
  {"Arduino", WAVE, 50, 500},
};

#define Total_Animations 16

void setup(){
/// TAKE A SHORTCUT
  // d.DefaultSettings();
  d.begin();
/// SET THE STARTING POSITION
  d.Set_Position(0);
}

void loop(){
/// DISPLAY ALL OF THE DEFINDED EFFECTS
  for(int index = 0; index < Total_Animations; index++){
    d.AnimateMe(Contents[index].Text, Contents[index].Effect, Contents[index].Scroll_Step_duration, Contents[index].hold_duration);
  }
}

/// END