/**
 NAME   : CK_MAX
 AUTHOR : CHANDAN KUMAR MONDAL

 NOTICE : THIS FILE, DIRECTION RIGHT TO LEFT(R2L) IS DEFAULT DIRECTION, IF YOUR MODULE HAS LEFT TO RIGHT(L2R), SET IT BY COMMAND, SetDirection(L2R);

COPYRIGHT (C) APRIL 2020 CHANDAN KUMAR MONDAL
*/

#ifndef CK_MAX_H
#define CK_MAX_H

#include "SPI.h"
#if ARDUINO >=100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


/**
 +-------------------------------+
 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
 +-------------------------------+
 DIRECTION : RIGHT TO LEFT(R2L)                         Correct_Align = 0                           
 
 +-------------------------------+
 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
 +-------------------------------+
 DIRECTION : LEFT TO RIGHT(L2R)                          Correct_Align = 1  
    
+-----------------------+		                                                          */
 #define Correct_Align 0                                                                   /**
+-----------------------+                                                                 */


#define ALL 0x07

/**
    OPCODES
*/
#define BCD 0x09
#define Bright 0x0A
#define Scan 0x0B
#define ShutDown 0x0C
#define DisplayT 0x0F
/**
   DIGITS IN ONE MODULE
*/
#define DIGIT_NUMBER 8

/**
   BCD MODE STATUS
*/
enum BCD_MODE{
  ACTIVE = 0xFF,
  DEACTIVE = 0x00
};

/**
   BRIGHTNESS LEVEL STATUS
*/
enum Brightness_level{
  MAXIMUM = 0x0F,
  MINIMUM = 0X01,
  MEDIUM = 0x07
};

/**
   SUTDOWN LEVEL STATUS
*/
enum Shutdown_level{
  OFF = 0x01,
  ON = 0x00
};

/**
   WHEN THE DIG0 PIN OF THE MAX7219 IS CONNECTED TO RIGHTMOST DIGIT OF THE SEVEN SEGMENTS MODULE, THEN IT IS RIGHT TO LEFT ALIGN DISPLAY MODULE
*/
enum displayAlignment{
  L2R = 1,
  R2L
};

/**
  ALL EFFECT'S NAME
*/
enum All_Animations{
/**EFFECT INDEX - 01 **/    SCROLL_LEFT, 			// ( TEXT SCROLL RIGHT TO LEFT )
/**EFFECT INDEX - 02 **/ 	SCROLL_RIGHT,			// ( TEXT SCROLL LEFT TO RIGHT )
/**EFFECT INDEX - 03 **/ 	SCROLL_UP,   			// ( TEXT SCROLL DOWN TO UP )
/**EFFECT INDEX - 04 **/ 	SCROLL_DOWN, 			// ( TEXT SCROLL UP TO DOWN )
/**EFFECT INDEX - 05 **/ 	MAKE_BUFFER, 			// ( FIRST DISPLAY SHOW SPIN EFFECT THEN PRINT THE TEXT )
/**EFFECT INDEX - 06 **/ 	SLICE_OWN,   			// ( SINGLE CHARACTER COMES FROM THE LAST CHARACTER POSITION OF THE TEXT )
/**EFFECT INDEX - 07 **/ 	SLICE_ALL,   			// ( SINGLE CHARACTER COMES FROM THE RIGHTMOST POSITION OF THE DISPLAY )
/**EFFECT INDEX - 08 **/ 	SCAN_TOP,    			// ( SYSTEM READ THE CHARACTER FROM A TO DP )
/**EFFECT INDEX - 09 **/ 	SCAN_BOTTOM, 			// ( SYSTEM READ THE CHARACTER FORM DP TO A )
/**EFFECT INDEX - 10 **/	RAND_UP,     			// ( SYSTEM READ THE SEQUENCE OF THE CHARACTER BIT FORM A TO DP )
/**EFFECT INDEX - 11 **/	RAND_DOWN,   			// ( SYSTEM READ THE SEQUENCE OF THE CHARACTER BIT FORM DP TO A )
/**EFFECT INDEX - 12 **/	WAVE,        			// ( FILP THE SINGLE CHARACTER FROM 0th POSITION TO LAST POSITION )
/**EFFECT INDEX - 13 **/	MAKE,        			// ( LIT THE LED OF THE CORRESPONDING CHARACTER BIT)
/**EFFECT INDEX - 14 **/	BREAK,       			// ( TURN ON ALL OF THE LED AND AND TURN OFF ACCORDING TO THE MISSING BIT OF THE CHARACTER)
/**EFFECT INDEX - 15 **/	SCROLL_UP_SINGLE,       // ( SCROLL UP IN SEQUENCING )
/**EFFECT INDEX - 16 **/	SCROLL_DOWN_SINGLE,     // ( SCROLL DOWN IN SEQUENCING )
/**EFFECT INDEX - 17 **/	SCROLL_UP_RANDOM,       // ( SCROLL UP RANDOMLY )
/**EFFECT INDEX - 18 **/	SCROLL_DOWN_RANDOM,     // ( SCROLL DOWN RANDOMLY )
/**EFFECT INDEX - 19 **/	GROW_UP,               /// ( READ THE BIT FROM DOWN TO UP )
/**EFFECT INDEX - 20 **/	GROW_DOWN,             /// ( READ THE BIT FORM UP TO DOWN )
/**EFFECT INDEX - 21 **/	RANDOMIZED,            /// ( FIRST SHOW RANDOMLY AND ARRANGING STEP BY STEP )
/**EFFECT INDEX - 22 **/  //  SCAN_X,                /// **************************************************
                          //  SCAN_XX
};

typedef All_Animations MyEffect_t;

/**
    CONNECTED EFFECT
	All_Animations::SCROLL_LEFT  -> Scroll_Effect::RIGHT_TO_LEFT
	All_Animations::SCROLL_RIGHT -> Scroll_Effect::LEFT_TO_RIGHT
*/
enum Scroll_Type{
	LEFT_TO_RIGHT,
	RIGHT_TO_LEFT
};

/**
    CONNECTED EFFECT
	All_Animations::RAND_UP     ->   Growing_Type::UP
	All_Animations::RAND_DOWN   ->   Growing_Type::DOWN
	All_Animations::MAKE_BUFFER ->   Growing_Type::BUFFERING
*/
enum Growing_Type{
	UP,
	DOWN,
	BUFFERING
};

/**
     CONNECTED EFFECT
	 All_Animations::SLICE_OWN  ->  Slicing_Type::OWN_SLICE
	 All_Animations::SLICE_ALL  ->  Slicing_Type::ALL_SLICE
*/
enum Slicing_Type{
	OWN_SLICE,
	ALL_SLICE
};

/**
    CONNECTED EFFECT
	All_Animations::SCROLL_UP   ->  Flow_Type::GO_UP
	All_Animations::SCROLL_DOWN ->  Flow_Type::GO_DOWN
*/
enum Flow_Type{
	GO_UP,
	GO_DOWN
};

/**
    CONNECTED EFFECT
	All_Animations::SCAN_BOTTOM -> Scan_Type::BOTTOM
	All_Animations::SCAN_TOP    -> Scan_Type::TOP
*/
enum Scan_Type{
	TOP,
	BOTTOM
};

/**
    CONNECTED EFFECT
	All_Animations::MAKE       -> Build_Type::MAKING
	All_Animations::BREAK      -> Build_Type::BREAKING
*/
enum Build_Type{
	MAKING,
	BREAKING
};

/**
    CONNECTED EFFECT
	All_Animations::SCROLL_DOWN_SINGLE      -> Build_Type::S_D_S
	All_Animations::SCROLL_UP_SINGLE        -> Build_Type::S_U_S
*/
enum Scroll_New_Type{
	S_D_S,
	S_U_S
};

/**
    CONNECTED EFFECT
	All_Animations::SCROLL_DOWN_RANDOM      -> Build_Type::S_D_R
	All_Animations::SCROLL_UP_RANDOM        -> Build_Type::S_U_R
*/
enum Random_Scroll_Type{
	S_U_R,
	S_D_R
};
/**
    EFFECT MODE STATUS,
    ---------->ENTRY (HOLD or PAUSE) EXIT------------>
*/
enum Animation_Mode{
  ENTRY,
  EXIT
};
/**
       Class : CK_MAX
*/
class CK_MAX{
/** Private Functions and Variables......*/
 private:
 
 // HOLD THE BCD MODE STATUS
    boolean BCD_Active = false;
	  
 // DEFAULT CURSOR POSITION (PRINT FROM LEFTMOST DIGIT)
    byte digit_pos=1;
	  
 // HOLD THE REFRESH STATUS. IF TRUE, THEN DISPLAY WILL AUTOMATICALLY REFRESH BUFORE ANOTHER MESSAGE COME
    boolean Internal_Refresh = true;
	 
 // HOLD THE DISPLAY NUMBER (DEPENDS ON Number_of_Device)
    uint8_t ACTUAL_DEVICES = 1;
	 
 // CHIP SELECT PIN OF THE GIVEN DEVICE'S
    uint16_t _CS_pin;
	 
 // A STUFF OF (All_Animations::MAKE_BUFFER), HOW MANY SPIN OCCURE BEFORE THE MESSAGE APPEAR OR DISAPPEAR
    uint8_t SPIN_COUNTER = 3;
	 
 // DEFAULT DISPLAY NUMBER (1)
    int Number_of_Device = 1;
	
 // MAIN DATA ARRAY, THAT WILL BE DEFINED LATTER
	byte * MY_MESSAGE_BUFFER;
	
 // LENGTH OF THE GIVEN MESSAGE
	int LENGTH_OF_MESSAGE;
	
 // HOLD THE USER DEFINDED SPI STATUS
    boolean User_s_SPI = false;
	
 // IF PROVIDE INTERNAL POWER SUPPLY
    bool Power_Supply = false;
	
 // USER DEFINDED SPI'S CLOCK AND DATA PIN
    uint16_t _CLOCK_PIN, _DATA_PIN, _VCC, _GND;

 
 /// PRIVATE FUNCTION
 
 /**
      \brief WHEN WE DISPLAY SAME DATA FOR EVERY MODULE, THEN THIS FUNCTION WILL BE CALLED
	  @return - Nothing
	  @param address - Address of the Register 
	  @param value - Data, that will be displayed
 */
 void Execute(byte address, byte value);
 
 /**
      \brief WHEN WE NEED TO DISPLAYED INDIVIDUAL DATA FOR INDIVIDUAL MODULE, THIS FUNCTION MAY BE CALLED
	  @return - Nothing
	  @param value - The given data for displaying
	  @param loopNumber - Introduce the Module sequence
	  @param regNumber - Introduce the Register Number
 */
 void ForceExecute(byte value, int loopNumber, byte regNumber);
 
 /**
      \brief THIS MAINLY PRINT THE INTEGER TYPE OF DATA (WITHOUT DECIMAL POINT)
	  @return - Nothing
	  @param snumber - String(int) or String(long)
 */
 void ShowIt(String snumber);
 
 /**
      \brief THIS FUNCTION PRINT THE FLOTING TYPE OF DATA (WITH DECIMAL POINT)
	  @return - Nothing
	  @param fnumber - String(float) or String(double)
 */
 void ShowItF(String fnumber);
 
 /**
      \brief GIVES THE CORRESPONDING BYTE OF SINGLE CHARACTER, IT IS COMING FROM "CK_MAX_DIGHT.h" FILE
	  @return - Byte according to char and it is printable for seven segments
	  @param index - ASCII code 
 */
 byte give_me_byte(int index);
 
 /**
      \brief GIVES THE SEQUENCE OF THE MODULE
	  @return - The module sequence (loopNumber)
	  @param c - cursor (digit_pos)
 */
 int givethecursor(int c);
 
 /**
      \brief ANIMATION STUFF (SCROLLING EFFECT)
	  @return - Nothing
	  @param message - Printable Data
	  @param S_T - Scrolling effect's type (LEFT_TO_RIGHT or RIGHT_TO_LEFT)
	  @param duration - Time delay for every step. 
 */
 void ScrollMe(String message,Scroll_Type S_T, uint16_t duration);
 
 /**
      \brief ANIMATION STUFF (GROWING EFFECT)
	  @return - Nothing
	  @param message - Printable Data
	  @param G_T - Growing Effect's Type (RAND_UP or RAND_DOWN or MAKE_BUFFER)
	  @param duration - Effect Rendering delay
	  @param wait - Hold or Pause time. After this time another Data will be appeared.
 */
 void GrowMe(String message, Growing_Type G_T,Animation_Mode A_M, uint16_t duration,uint16_t wait);
 
 /**
      \brief ANIMATION STUFF (SLICING EFFECT)
	  @return - Nothing
	  @param message - Printable Data
	  @param S_T - Slicing Effect's Type (SLICE_OWN, SLICE_ALL)
	  @param duration - Effect Rendering delay
	  @param wait - Hold or Pause time.
 */
 void SliceMe(String message, Slicing_Type S_T,Animation_Mode A_M, uint16_t duration, uint16_t wait);
 
 /**
      \brief ANIMATION STUFF (FLOWING EFFECT)
	  @return - Nothing
	  @param message - Printable Data
	  @param F_T - Flowing Effect Type (SCROLL_UP or SCROLL_DOWN)
	  @param duration - Effect Rendering delay
	  @param wait - Hold or Pause time.
 */
 void FlowMe(String message,Flow_Type F_T,Animation_Mode A_M ,uint16_t duration, uint16_t wait);
 
 /**
      \brief ANIMATION STUFF (SCANING EFFECT)
	  @return - Nothing
	  @param message - Printable Data
	  @param S_T - Scan Effect's Type (SCAN_TOP or SCAN_BOTTOM)
	  @param duration - Effect Rendering delay
	  @param wait - Hold or Pause time.
 */
 void ScanMe(String message, Scan_Type S_T,Animation_Mode A_M,  uint16_t duration, uint16_t wait);
 
 /**
	  \brief ANIMATION STUFF (ONLY ONE TYPE OF EFFECT)
	  @return - Nothing
	  @param message - Printable Data
	  @param duration - Effect Rendering delay
	  @param wait - Hold or Pause time.
 */
 void WaveMe(String message, uint16_t duration, uint16_t wait);
 
 /**
      \brief ANIMATION STUFF (BUILDING EFFECT)
	  @return - Nothing
	  @param message - Printable Data
	  @param B_T - Building Effect's Type (MAKE or BRAKE)
	  @param duration - Effect Rendering delay
	  @param wait - Hold or Pause time.
 */
 void BuildMe(String message, Build_Type B_T,Animation_Mode A_M, uint16_t duration, uint16_t wait);
 
 /**
      \brief ANIMATION EFFECT (SCROLLING EFFECT) SEQUENCE
	  @return - Nothing
	  @param message - Printable Data
	  @param S_T - Scrolling Effect's Type (SCROLL_DOWN_SINGLE or SCROLL_UP_SINGLE)
	  @param duration - Effect Rendering delay
	  @param wait - Hold or Pause time.
 */
 void ScrollMeNew(String message, Scroll_New_Type S_T, Animation_Mode A_M, uint16_t duration, uint16_t wait);
 
 /**
      \brief ANIMATION EFFECT (SCROLLING EFFECT) RANDOM
	  @return - Nothing
	  @param message - Printable Data
	  @param S_T - Scrolling Effect's Type (SCROLL_DOWN_RANDOM or SCROLL_UP_RANDOM)
	  @param duration - Effect Rendering delay
	  @param wait - Hold or Pause time.
 */
 void ScrollMeRand(String message, Random_Scroll_Type R_T, Animation_Mode A_M, uint16_t duration, uint16_t wait);
 
 /**
      \brief ANIMATION EFFECT (GROW EFFECT)
	  @return - Nothing
	  @param message - Printable Data
	  @param S_T - Scrolling Effect's Type (GROW_UP or GROW_DOWN)
	  @param duration - Effect Rendering delay
	  @param wait - Hold or Pause time.
 */
	
 void GROWME(String message, All_Animations G_T, Animation_Mode A_T, uint16_t duration, uint16_t wait);
 
 /**
      \brief ANIMATION EFFECT (RANDOM EFFECT)
	  @return - Nothing
	  @param message - Printable Data
	  @param duration - Effect Rendering delay
	  @param wait - Hold or Pause time.
 */
 void RandomizeMe(String message,  uint16_t duration, uint16_t wait);
 
  /*
 void SortMe(String message, Animation_Mode A_M, uint16_t duration, uint16_t wait);
 
 void GiveMe(String message, Animation_Mode A_M, uint16_t duration, uint16_t wait);
  */
 /**
      \brief PROCESS THE UPCOMING STRING AND SAVE THE CORRESPONDING BYTE
	  @return - Nothing
	  @param message - Need to be processed
 */
 void TRANSFER_THIS(String message);
 
 /**
     \brief PRINT THE BUFFER FOR ANY TIME IN ANIMATION
	 @return - Nothing
	 @param upcoming_message - Upcoming data that will be printed.
	 @param length_of_message - Length of the data.
	 @param initial_position - The starting position of data (display cursor).
 */ 
 void Buffer_Print(byte * upcoming_message, uint8_t length_of_message, uint8_t initial_position);
 void Buffer_Print(byte * upcoming_message){Buffer_Print(upcoming_message, LENGTH_OF_MESSAGE, digit_pos);}
 
 


 /** Public Functions*/
 public:
 /**
      CONSTRUCTOR 
	  @param CS_pin - Chip Select pin of the display module.
 */
 CK_MAX(uint16_t CS_pin);
 
 /**
      CONSTRUCTOR
	  @param CS_pin - Chip Select pin of the display module.
	  @param Number_of_Given_device - How many module connected serially.
 */
 CK_MAX(uint16_t CS_pin, int Number_of_Given_device);
 
 /**
      CONSTRUCTOR
	  @param data_pin - Data pin of User defined SPI's
	  @param clock_pin - Clock pin of User defined SPI's
	  @param CS_pin - Chip Select pin of the display module.
	  @param Number_of_Given_device - How many module connected serially.
 */
 CK_MAX(uint16_t data_pin, uint16_t clock_pin, uint16_t CS_pin, int Number_of_Given_device);
 
 /**
      CONSTRUCTOR
	  VCC  ---- GND ---- DIN ---- CS ---- CLK
 */
 CK_MAX(uint16_t VCC, uint16_t GND, uint16_t DIN, uint16_t CS, uint16_t CLK, int Number_of_Given_Device);
 
 /**
      DESTRUCTOR
	  free the allocated memory for every time destroying the object.
 */
 ~CK_MAX();
 
 /**
      PREPARATION / INITIALIZING
 */
 void begin();
 
 /**
      \brief KEY FUNCTION FOR ACTIVATING OR DEACTIVATING THE BCD MODE.
	  @return - Nothing
	  @param bm - Mode (ACTIVE or DEACTIVE)
 */
 void BCD_mode(BCD_MODE bm);
 
 /**
      \brief KEY FUNCTION FOR SET THE BRIGHTNESS
	  @return - Nothing
	  @param given_bright - Brightness Value (0 to 14)
 */
 void Set_Brightness(byte given_bright);

 /**
      \brief COMBINATION OF SOME SETTING (ENOUGH FOR START THE DISPLAY SMOOTHLY)
	  BCD          -> DEACTIVE
	  BRIGHTNESS   -> MAXIMUM (14)
	  SCAN LIMIT   -> ALL DIGIT (0x07)
	  SHUTDOWN     -> OFF (DISPLAY ACTIVATION)
	  DISPLAY TEST -> NORMAL OPERATION
 */
 void DefaultSettings();
 
 /**
      \brief SAME AS  DefaultSettings() , ONLY DIFFERENCE IS YOU CAN SET THE SCAN LIMIT AND OHTER SETTING WILL BE SAME AS PREVIOUS
	  @param num_of_digit - Scan limit (0x00 to 0x01)
	  ...
	  SCAN LIMIT   -> num_of_digit
	  ...
 */
 void DefaultSettings(int num_of_digit);
 
 /**
       \brief KEY FUNCTION FOR SET THE SHUTDOWN MODE
	   @return - Nothing
	   @param sl - ShutDown Level (OFF or ON)
 */
 void SetShutdown(Shutdown_level sl);
 
 /**
      \brief KEY FUNCTION FOR SET THE SCAN LIMIT
	  @return - Nothing
	  @param num_of_digit - How many digit will be used (SCAN_LIMIT)
 */
 void Using_digit(int num_of_digit);
 
 /**
      \brief THIS FUNCTION SET THE CURSOR POSITION
	  @return - Nothing
	  @param pos - Desire position
 */
 void Set_Position(byte pos);
 
 /**
      KEY FUNCTION FOR SET THE SPIN NUMBER(MAKE_BUFFER ONLY)
 */
 void Set_Buffer_Count(uint8_t number){SPIN_COUNTER = number;}
 
 /**
      SHOW THE INTEGER VALUE
 */
 void ShowMe(int number);
 
 /**
      SHOW THE LONG VALUE
 */
 void ShowMe(long number);
 
 /**
      SHOW THE FLOTING VALUE
 */
 void ShowMe(float number);
 
 /**
      SHOW THE DOUBLE VALUE
 */
 void ShowMe(double number);
 
 /**
      SHOW THE STRING
 */
 void ShowMe(String number);
 
 /**
      SHOW THE SINGLE CHARACTER
 */
  void ShowMe(char mychar);
  
 /**
      \brief SHOW THE USER DEFINDED CHARACTER
	  @param position - Cursor Position
	  @param sprite - user defined byte
 */
 void ShowMe(int position, byte sprite);
 
 /**
      KEY FUNCTION FOR SET THE AUTO REFRESH MODE
	  IF THE MODE IS ON, DISPLAY WILL BE AUTOMATICALLY REFRESH BEFORE THE ANOTHER DATA COME.
	  AND IF THE MODE WILL BE OFF, THE OLD DATA KEEP DISPLAYING NO MATTER NEW DATA COME.
 */
 void AutoRefresh(boolean ar){ Internal_Refresh = (ar)?true:false;}
 /**
      FOR REFRESING THE DISPLAY
 */
 void RefreshMe();
 
 /**
      REFRESING THE SPACIFIC LENGTH
 */
 void RefreshMeFrom(uint8_t Start, uint8_t End);
 void RefreshFrom(uint8_t Start, uint8_t End);

 /**
      \brief FUNCTION FOR ANIMATION
	  
	  @return - Nothing
	  @param message - Animating Data
	  @param Animation - Effect's Name (All_Animations::)
	  @param duration - Rendering delay
	  @param wait - Hold or Pause time.
	  
	  SUITABLE EFFECT : ALL
 */
 void AnimateMe(String message, All_Animations Animation, uint16_t duration, uint16_t wait);
 
 /**
      \brief FUNCTION FOR ANIMATION
	  
	  @return - Nothing
	  @param message - Animating Data
	  @param Animation - Effect's Name (All_Animations::)
	  @param wait - Hold or Pause time.
	  
	  SUITABLE EFFECTS : SCROLL_LEFT and SCROLL_RIGHT
 */
 void AnimateMe(String message, All_Animations Animation, uint16_t wait);
 
 /**
      \brief - FUNCTION FOR ANIMATION
	  
	  @return - Nothing
	  @param message - Animating Data
	  @param Animation - Effect's Name (All_Animations::MAKE_BUFFER)
	  @param number - SPIN_COUNTER .
	  @param duration - Rendering delay.
	  @param wait - Hold or Pause time.
	  
	  SUITABLE EFFECT : MAKE_BUFFER
 */
 void AnimateMe(String message, All_Animations Animation, uint8_t number, uint16_t duration, uint16_t wait);

 /**
      \brief - DOUBLE ANIMATION EFFECT
	  
	  @return - Nothing
	  @param message - Animating Data
	  @param Enter - Enter Effect's Name (All_Animations::)
	  @param Exit  - Exit Effect's Name (All_Animations::)
	  @param ENduration - Enter Effect Rendering delay.
	  @param EXduration - Exit Effect Rendering delay.
	  @param wait - Hold or Pause time.
 */
 void AnimateMe(String message, All_Animations Enter, All_Animations Exit, uint16_t ENduration,uint16_t EXduration, uint16_t wait);
};

#endif
