/**
    CK_MAX
	copyright (c) 2020, Chandan Kumar Mondal
	All rights reserved.
	
*/
#include "CK_MAX.h"
#include "CK_MAX_DIGITS.h"
/**
   CONSTRUCTOR PART
   - CK_MAX(LOAD_PIN) > HERE NUMBER OF DEVICE IS 1
   - CK_MAX(LOAD_PIN, NUMBER_OF_GIVEN_DEVICE) > HERE "NUMBER_OF_GIVEN_DEVICE" IS ASSIGN TO "NUMBER_OF_DEVICE"
   
   - TURN ON THE NORMAL OPERATION 
*/
CK_MAX::CK_MAX(uint16_t CS_pin):_CS_pin(CS_pin){
    pinMode(_CS_pin, OUTPUT);
    SPI.begin();
    Execute(DisplayT, 0x00);
}

CK_MAX::CK_MAX(uint16_t CS_pin, int Number_of_Given_Device):_CS_pin(CS_pin){
	ACTUAL_DEVICES = Number_of_Given_Device;
	Number_of_Device = (Number_of_Given_Device%2==1)?Number_of_Given_Device : Number_of_Given_Device+1;
    pinMode(_CS_pin, OUTPUT);
    SPI.begin();
    Execute(DisplayT, 0x00);
}

CK_MAX::CK_MAX(uint16_t data_pin, uint16_t clock_pin,uint16_t CS_pin, int Number_of_Given_Device):_CS_pin(CS_pin), _DATA_PIN(data_pin), _CLOCK_PIN(clock_pin){
    ACTUAL_DEVICES = Number_of_Given_Device;
	Number_of_Device = (Number_of_Given_Device%2==1)?Number_of_Given_Device : Number_of_Given_Device+1;
    pinMode(_CLOCK_PIN, OUTPUT);
    pinMode(_DATA_PIN, OUTPUT);
    pinMode(_CS_pin, OUTPUT);
    User_s_SPI = true;
	
}

CK_MAX::CK_MAX(uint16_t VCC, uint16_t GND, uint16_t DIN, uint16_t CS, uint16_t CLK, int Number_of_Given_Device):_CS_pin(CS), _DATA_PIN(DIN), _CLOCK_PIN(CLK),_VCC(VCC), _GND(GND){
	ACTUAL_DEVICES = Number_of_Given_Device;
	Number_of_Device = (Number_of_Given_Device%2==1)?Number_of_Given_Device : Number_of_Given_Device+1;
    pinMode(_CLOCK_PIN, OUTPUT);
    pinMode(_DATA_PIN, OUTPUT);
    pinMode(_CS_pin, OUTPUT);
	pinMode(_VCC, OUTPUT);
	pinMode(_GND, OUTPUT);
    User_s_SPI = true;
	Power_Supply = true;
}

CK_MAX::~CK_MAX(){
	free(MY_MESSAGE_BUFFER);
}

void CK_MAX::begin(){
	if(Power_Supply){
		digitalWrite(_VCC, HIGH);
		digitalWrite(_GND, LOW);
		delay(1000);
	}
	DefaultSettings();
	MY_MESSAGE_BUFFER = (byte*)malloc(sizeof(byte)*Number_of_Device*DIGIT_NUMBER*3);
	RefreshMe();
	Set_Position(0);
}
/**
   "EXECUTE" IS USE FOR PERFORM SAME ACTION FOR EACH MODULE(DEVICE).
   LIKE, BCD_MODE, BRIGHTNESS LEVEL, SHUTDOWN LEVEL, SCAN_LIMIT ETC.
*/

void CK_MAX::Execute(byte address, byte value){
	  digitalWrite(_CS_pin, LOW);
      if(!User_s_SPI){
          for(int i=0;i<Number_of_Device;i++){
			  SPI.transfer(address);
			  SPI.transfer(value);
			}
      }else{
          for(int i=0;i<Number_of_Device;i++){
			  shiftOut(_DATA_PIN, _CLOCK_PIN, MSBFIRST, address);
              shiftOut(_DATA_PIN, _CLOCK_PIN, MSBFIRST, value);
			}
      }
			
	  digitalWrite(_CS_pin, HIGH);
}

/**
   "FORCE_EXECUTE" IS USE FOR TRANSFER SPACIFIC DATA FOR SPACIFIC MODULE AND REGISTER.
    @param - value       > THE GIVEN VALUE, THAT WOULD BE DISPLAYED
	@param - loopNumber  > IT IS MAINLY THE MODULE NUMBER
	@param - regNumber   > IT IS THE DIGIT NUMBER OF THE DISPLAY
	
	         1                                  2                                N          - loopNumber ( @param )
 +-------------------------------+  +-------------------------------+         --------+
 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |  .....  | 7 | 8 |     - regNumber  ( @param )
 +-------------------------------+  +-------------------------------+         --------+
   1   2   3   4   5   6   7   8      9   10  11  12  13  14  15  16         (8N-1) 8N      - POSITION
	FOR LEFT TO RIGHT CONFIG. 
	
	SUPPOSE, WE PRINT 'A' IN THE "POSITION" 12, THEN 'A' = value ( @param )
	
	WE FIND THE "loopNumber" AND "regNumber" USING "givethecursor(int c)" FUNCTION
	@param - c           > THE POSITION NUMBER
	@return #THE DEVICE INDEX OR NUMBER
	HERE c = 12 
	RETURN = 2 (loopNumber)
	
	regNumber = POSITION - ((loopNumber-1) * DIGIT_NUMBER) HERE, DIGIT_NUMBER = 8
	          = 12 - ((2-1) * 8)
			  = 12 - 8
			  = 4 
	SO HERE, 
	FOR(i=0;i<2;i++)
		WHEN i == 0, THE GIVEN VALUE WILL BE TRANSMITTED 
	
	@SEQUENCE WILL BE LIKE THAT,
	
	LOAD_PIN -> LOW
	WHEN i==0
	+-------------------------------+  +-------------------------------+
    |   |   |   | A |   |   |   |   |  |   |   |   |   |   |   |   |   |  - value ( @param )
    +-------------------------------+  +-------------------------------+
	
	i++
	+-------------------------------+  +-------------------------------+
    |   |   |   |   |   |   |   |   |  |   |   |   | A |   |   |   |   |  - value ( @param )
    +-------------------------------+  +-------------------------------+	
	LOAD_PIN -> HIGH (EXECUTION)
*/
void CK_MAX::ForceExecute(byte value, int loopNumber, byte regNumber){
    digitalWrite(_CS_pin, LOW);
    if(!User_s_SPI){
       for(int i=0;i<loopNumber;i++){
            if(i==0){
            SPI.transfer(regNumber);
            SPI.transfer(value); 
            }else{
            SPI.transfer(0x00);
            SPI.transfer(0);
            }           
        }
    }else{
        for(int i=0; i<loopNumber; i++){
            if(i==0){
                shiftOut(_DATA_PIN, _CLOCK_PIN, MSBFIRST, regNumber);
                shiftOut(_DATA_PIN, _CLOCK_PIN, MSBFIRST, value);
            }else{
                shiftOut(_DATA_PIN, _CLOCK_PIN, MSBFIRST, 0x00);
                shiftOut(_DATA_PIN, _CLOCK_PIN, MSBFIRST, 0);
            }
        }
    }
    
    digitalWrite(_CS_pin, HIGH);
}

/**
	 BCD MODE ACTIVE OR DEACTIVE
*/
void CK_MAX::BCD_mode(BCD_MODE bm){
	BCD_Active = (bm == ACTIVE)? true:false;
    Execute(BCD,bm);
}

/**
     SET THE BRIGHTNESS, 0 FOR MINIMUM AND 15 FOR MAXIMUM
*/
void CK_MAX::Set_Brightness(byte given_bright){
	given_bright = constrain(given_bright, 0, 14);
    Execute(Bright, given_bright);
}

/**
     SHUTDOWN MODE - 'OFF' FOR DISPLAY ACTIVATION
*/
void CK_MAX::SetShutdown(Shutdown_level sl){
    Execute(ShutDown, sl);
}

/**
    HOW MANY DIGIT ARE USEING (0 FOR MINIMUM AND 7 FOR MAXIMUM)
*/
void CK_MAX::Using_digit(int num_of_digit){
    byte final_digit = 0;
    if(num_of_digit> 8 || num_of_digit<=0 || num_of_digit== ALL){
        final_digit = 7;
    }else{
        final_digit = num_of_digit - 1;
    }
    Execute(Scan, final_digit);
}

/**
   DefaultSettings() # 
                        > BCD MODE - DEACTIVE
						> BRIGHTNESS - 15 (MAXIMUM)
						> USING DIGIT - 7 (ALL)
						> SHUTDOWN - OFF (DISPLAY ACTIVE)
*/
void CK_MAX::DefaultSettings(){
    Execute(BCD, 0x00);
    Execute(ShutDown, 0x01);
    Execute(Bright, 0x08);
    Execute(Scan, 0x07);
	RefreshMe();
}

/**
   DefaultSettings(num_of_digit) # 
                        > BCD MODE - DEACTIVE
						> BRIGHTNESS - 15 (MAXIMUM)
						> USING DIGIT - num_of_digit ( @param )
						> SHUTDOWN - OFF (DISPLAY ACTIVE)
*/

void CK_MAX::DefaultSettings(int num_of_digit){
    byte final_digit = 0;
    if(num_of_digit> 8 || num_of_digit<=0 || num_of_digit== ALL){
        final_digit = 7;
    }else{
        final_digit = num_of_digit - 1;
    }
    Execute(Scan, final_digit);
    Execute(BCD, 0x00);
    Execute(ShutDown, 0x01);
    Execute(Bright, 0x08);
    Execute(Scan, 0x07);
	RefreshMe();
}

/**
    CLEAR THE WHOLE SCREEN
*/
void CK_MAX::RefreshMe(){
    for(int i=1;i<9;i++){
        Execute(i,0b00000000);
    }
}

void CK_MAX::RefreshMeFrom(uint8_t Start, uint8_t End){
   int LoopNumber = 0;
   byte RegNumber = 0;
   int position = 0;
   for(int i = Start; i <= End ; i++){
	   position = ((Number_of_Device*DIGIT_NUMBER)+1)-(i+1);
	   LoopNumber = givethecursor(((DIGIT_NUMBER*Number_of_Device)+1)-position);
	   RegNumber  = position - ((LoopNumber-1)*DIGIT_NUMBER);
	   ForceExecute(0b00000000, LoopNumber, RegNumber);
   }
}

void CK_MAX::RefreshFrom(uint8_t Start, uint8_t End){
   int LoopNumber = 0;
   byte RegNumber = 0;
   for(int i = Start; i > End ; i--){
	   LoopNumber = givethecursor(((DIGIT_NUMBER*Number_of_Device)+1)-i);
	   RegNumber  = i - ((LoopNumber-1)*DIGIT_NUMBER);
	   ForceExecute(0b00000000, LoopNumber, RegNumber);
   }
}


/**
     CURSOR POSITION, 
*/
void CK_MAX ::  Set_Position(byte pos){
  if(!Correct_Align){
   digit_pos = ((Number_of_Device*DIGIT_NUMBER)+1)-(pos+1);
  }else{
   digit_pos = pos+1;
  }
}

/**
    PRINT -> INTEGER, FLOAT / OVERLOADED
*/
void CK_MAX::ShowMe(int number){
    String S_Number = String(number);
    ShowIt(S_Number);
}

void CK_MAX::ShowMe(long number){
    String S_Number = String(number);
    ShowIt(S_Number);
}

void CK_MAX::ShowMe(float number){
    String F_Number = String(number);
    ShowItF(F_Number);
}

void CK_MAX::ShowMe(double number){
    String F_Number = String(number);
    ShowItF(F_Number);
}

void CK_MAX::ShowMe(String number){
    if(Internal_Refresh){RefreshMe();}
	TRANSFER_THIS(number);
    int Cursor = 0;
    int LoopNumber = 0;
    byte RegNumber = 0;
#if Correct_Align
	for(byte i=digit_pos; i<digit_pos + LENGTH_OF_MESSAGE;i++){
	  LoopNumber = givethecursor(i);
#else
	for(int i=digit_pos; i>digit_pos - LENGTH_OF_MESSAGE;i--){
	  LoopNumber = givethecursor(((DIGIT_NUMBER*Number_of_Device)+1)-i);
#endif 
	  RegNumber  = i - ((LoopNumber-1)*DIGIT_NUMBER);
	  ForceExecute(MY_MESSAGE_BUFFER[Cursor], LoopNumber, RegNumber);
	  Cursor++;
	}
}

void CK_MAX::ShowMe(char mychar){
	if(Internal_Refresh){RefreshMe();}
	int LoopNumber = 0;
	byte RegNumber = 0;
	#if Correct_Align
	LoopNumber = givethecursor(digit_pos);
	#else
	LoopNumber = givethecursor(((DIGIT_NUMBER*Number_of_Device)+1)-digit_pos);
	#endif

	RegNumber = digit_pos - ((LoopNumber-1)*DIGIT_NUMBER);
	ForceExecute(mynumber[mychar - 1], LoopNumber, RegNumber);
}

void CK_MAX::ShowMe(int position, byte sprite){
	if(Internal_Refresh){RefreshMe();}
	if(!Correct_Align){
       position = ((Number_of_Device*DIGIT_NUMBER)+1)-(position+1);
    }else{
       position = position+1;
    }
    int LoopNumber = 0;
	byte RegNumber = 0;
	#if Correct_Align
	LoopNumber = givethecursor(((DIGIT_NUMBER*Number_of_Device)+1)-position);
	#else
	LoopNumber = givethecursor(position);
	#endif

	RegNumber = position - ((LoopNumber-1)*DIGIT_NUMBER);
	ForceExecute(sprite, LoopNumber, RegNumber);
}

void CK_MAX::ShowIt(String snumber){
    if(Internal_Refresh){RefreshMe();}
    int LoopNumber = 0;
    byte RegNumber = 0;
    int length_of_number = snumber.length();
    int Cursor = 0;
#if Correct_Align
	for(byte i=digit_pos; i<digit_pos + length_of_number;i++){
	  LoopNumber = givethecursor(i);
#else
	for(int i=digit_pos; i>digit_pos - length_of_number;i--){
	  LoopNumber = givethecursor(((DIGIT_NUMBER*Number_of_Device)+1)-i);
#endif 
        RegNumber  = i - ((LoopNumber-1)*DIGIT_NUMBER);
        int number_index = snumber.charAt(Cursor);
		if(!BCD_Active){
			ForceExecute(mynumber[number_index-1],LoopNumber,RegNumber);
		}else{
			ForceExecute(String(snumber.charAt(Cursor)).toInt(), LoopNumber, RegNumber);
		}
        
        Cursor++;
      }
    }

/**
       ShowItF .... It is used for printing the float value....
     @call from float and double value.....
*/

void CK_MAX::ShowItF(String fnumber){
    if(Internal_Refresh){RefreshMe();}  
    int LoopNumber = 0;
    byte RegNumber = 0;  
  /** first ensure the dot index... suppose the string is "123.45".. here the index of dot is 3 */
  int my_dot_index = fnumber.indexOf('.');

  /// remove the dot from the string, so now the string is 12345
  fnumber.replace(".","");

  /// Now measure the length
  int length_of_this = fnumber.length();

  /// Now Print this but,, Careful about the dot.. it always associated with.. (my_dot_index - 1)
  int Cursor = 0;
  int Care_about_position = my_dot_index - 1;
#if Correct_Align
      for(int i = digit_pos; i<digit_pos+length_of_this; i++){
		  LoopNumber = givethecursor(i);
#else 
	  for(int i = digit_pos; i>digit_pos-length_of_this; i--){
		  LoopNumber = givethecursor(((DIGIT_NUMBER*Number_of_Device)+1)-i);
#endif
      int _index = fnumber.charAt(Cursor);
      byte printalbe_byte = 0;
      if(Cursor == Care_about_position){
          printalbe_byte = mynumber[_index - 1] | 0b10000000; /// Turn on the dp
      }else{
          printalbe_byte = mynumber[_index-1];
      }
      
      RegNumber  = i - ((LoopNumber-1)*DIGIT_NUMBER);
      ForceExecute(printalbe_byte,LoopNumber,RegNumber);
      Cursor++;
      }
 }


 int CK_MAX :: givethecursor(int c){
    for(int i=0;i<=Number_of_Device;i++){
		if( c>(i*8) && c<=((i+1)*8)) {return i+1;}
	}
}

byte CK_MAX :: give_me_byte(int index){
    return (mynumber[index-1]);
}

void CK_MAX:: Buffer_Print(byte * upcoming_message, uint8_t length_of_message, uint8_t initial_position){
	  int LoopNumber = 0;
	  byte RegNumber = 0;
	  // DISPLAY SECTION.....
	  int Cursor_pos = 0;
	  for(int i = initial_position; i>initial_position-length_of_message; i--){
	   LoopNumber = givethecursor(((DIGIT_NUMBER*Number_of_Device)+1)-i);
	   RegNumber  = i - ((LoopNumber-1)*DIGIT_NUMBER);
	   ForceExecute(upcoming_message[Cursor_pos], LoopNumber, RegNumber);
	   Cursor_pos++;
	  }
}