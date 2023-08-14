/**
    EXPERIMENT ON , CK_MAX ANIMATION EFFECT
	
	  CHANDAN KUMAR MONDAL (C) - 18 MAY, 2020
    *SAME EFFECT, WORKS BOTH IN AND OUT EFFECT
*/

#include <CK_MAX.h>
#include "DEBUG.h"

#define DEBUG 0
/*-------------------------------------------------------------------------------------------------
             RAND_UP  * RAND_DOWN  * MAKE_BUFFER
-------------------------------------------------------------------------------------------------*/

void CK_MAX::GrowMe(String message, Growing_Type G_T,Animation_Mode A_M, uint16_t duration, uint16_t wait){
	
    TRANSFER_THIS(message);
	/// OK... HERE IS THE END OF COLLECTING DATA SECTION, NOW LET'S ENTER THE ANIMATION SECTION
	
	/// TAKE A ARRAY EXACT SAME LENGTH OF THE MESSAGE
	byte buffer[LENGTH_OF_MESSAGE];
	int bitnumber = 0;
	/// CLEAN UP THIS BUFFER
if(A_M==ENTRY){
			for(uint8_t buf_id = 0; buf_id<LENGTH_OF_MESSAGE ; buf_id++){
				buffer[buf_id] = 0b00000000;
			}	
			if(G_T == UP){

				for( bitnumber = 0;bitnumber<8; bitnumber++)
				{
					for(uint8_t digitnumber = 0; digitnumber<LENGTH_OF_MESSAGE; digitnumber++){
						bitWrite(buffer[digitnumber] , bitnumber, bitRead(MY_MESSAGE_BUFFER[digitnumber],bitnumber));
					}
					
					/// DIPLAY THE SLOT
					uint8_t cursor = 0;
					uint8_t LoopNumber = 0;
					uint8_t RegNumber = 0;
		#if Correct_Align
			for(int i = digit_pos; i<digit_pos+LENGTH_OF_MESSAGE; i++){
				LoopNumber = givethecursor(i);
		#else 
			for(int i = digit_pos; i>digit_pos-LENGTH_OF_MESSAGE; i--){
				LoopNumber = givethecursor(((DIGIT_NUMBER*Number_of_Device)+1)-i);
		#endif
					RegNumber  = i - ((LoopNumber-1)*DIGIT_NUMBER);
					ForceExecute(buffer[cursor],LoopNumber,RegNumber);
					cursor++;
					}
					delay(duration);
				}
			}
			else if (G_T == DOWN)
			{
				for( bitnumber = 7;bitnumber>=0; bitnumber--)
				{
					for(uint8_t digitnumber = 0; digitnumber<LENGTH_OF_MESSAGE; digitnumber++){
						bitWrite(buffer[digitnumber] , bitnumber, bitRead(MY_MESSAGE_BUFFER[digitnumber],bitnumber));
					}
					
					/// DIPLAY THE SLOT
					uint8_t cursor = 0;
					uint8_t LoopNumber = 0;
					uint8_t RegNumber = 0;
		#if Correct_Align
			for(int i = digit_pos; i<digit_pos+LENGTH_OF_MESSAGE; i++){
				LoopNumber = givethecursor(i);
		#else 
			for(int i = digit_pos; i>digit_pos-LENGTH_OF_MESSAGE; i--){
				LoopNumber = givethecursor(((DIGIT_NUMBER*Number_of_Device)+1)-i);
		#endif
					RegNumber  = i - ((LoopNumber-1)*DIGIT_NUMBER);
					ForceExecute(buffer[cursor],LoopNumber,RegNumber);
					cursor++;
					}
					delay(duration);
				}
			}
			else if(G_T==BUFFERING){
				// FIRST CREATE A SPIN EFFECT,
				byte spin_buffer[LENGTH_OF_MESSAGE];
				// STORE THE INITIAL VALUE,
					for(uint8_t counter = 0; counter<SPIN_COUNTER; counter++) {
							for(uint8_t id = 0;id<LENGTH_OF_MESSAGE; id++){
								spin_buffer[id] = 0b11000000;
							}
							for(int index = 0;index<5;index++){
								for(int dig = 0;dig < LENGTH_OF_MESSAGE; dig++){
									spin_buffer[dig]=spin_buffer[dig]>>1;
								}
								//SHOW THE SPIN EFFECT, 
								uint8_t cursor = 0;
								uint8_t LoopNumber = 0;
								uint8_t RegNumber = 0;
					#if Correct_Align
						for(int i = digit_pos; i<digit_pos+LENGTH_OF_MESSAGE; i++){
							LoopNumber = givethecursor(i);
					#else 
						for(int i = digit_pos; i>digit_pos-LENGTH_OF_MESSAGE; i--){
							LoopNumber = givethecursor(((DIGIT_NUMBER*Number_of_Device)+1)-i);
					#endif
								RegNumber  = i - ((LoopNumber-1)*DIGIT_NUMBER);
								ForceExecute(spin_buffer[cursor],LoopNumber,RegNumber);
								cursor++;
								}
								delay(duration);
							}
						}
				///RefreshMe();
				uint8_t cursor=0;
				uint8_t LoopNumber = 0;
				uint8_t RegNumber = 0;
					#if Correct_Align
						for(int i = digit_pos; i<digit_pos+LENGTH_OF_MESSAGE; i++){
							LoopNumber = givethecursor(i);
					#else 
						for(int i = digit_pos; i>digit_pos-LENGTH_OF_MESSAGE; i--){
							LoopNumber = givethecursor(((DIGIT_NUMBER*Number_of_Device)+1)-i);
					#endif
								RegNumber  = i - ((LoopNumber-1)*DIGIT_NUMBER);
								ForceExecute(MY_MESSAGE_BUFFER[cursor],LoopNumber,RegNumber);
								cursor++;
								}
								delay(duration);
							}
			delay(wait);
			if(Internal_Refresh){
				RefreshMe();
			}
	}else{
		for(uint8_t index = 0; index < LENGTH_OF_MESSAGE ; index++){
			buffer[index] = MY_MESSAGE_BUFFER[index];
		}
		if(G_T==UP){
			for( bitnumber = 0;bitnumber<8; bitnumber++)
				{
					for(uint8_t digitnumber = 0; digitnumber<LENGTH_OF_MESSAGE; digitnumber++){
						bitClear(buffer[digitnumber] , bitnumber);
					}
					
					/// DIPLAY THE SLOT
					uint8_t cursor = 0;
					uint8_t LoopNumber = 0;
					uint8_t RegNumber = 0;
		#if Correct_Align
			for(int i = digit_pos; i<digit_pos+LENGTH_OF_MESSAGE; i++){
				LoopNumber = givethecursor(i);
		#else 
			for(int i = digit_pos; i>digit_pos-LENGTH_OF_MESSAGE; i--){
				LoopNumber = givethecursor(((DIGIT_NUMBER*Number_of_Device)+1)-i);
		#endif
					RegNumber  = i - ((LoopNumber-1)*DIGIT_NUMBER);
					ForceExecute(buffer[cursor],LoopNumber,RegNumber);
					cursor++;
					}
					delay(duration);
				}
		}

		else if(G_T == DOWN){
			for( bitnumber = 7;bitnumber>=0; bitnumber--)
				{
					for(uint8_t digitnumber = 0; digitnumber<LENGTH_OF_MESSAGE; digitnumber++){
						bitClear(buffer[digitnumber] , bitnumber);
					}
					
					/// DIPLAY THE SLOT
					uint8_t cursor = 0;
					uint8_t LoopNumber = 0;
					uint8_t RegNumber = 0;
		#if Correct_Align
			for(int i = digit_pos; i<digit_pos+LENGTH_OF_MESSAGE; i++){
				LoopNumber = givethecursor(i);
		#else 
			for(int i = digit_pos; i>digit_pos-LENGTH_OF_MESSAGE; i--){
				LoopNumber = givethecursor(((DIGIT_NUMBER*Number_of_Device)+1)-i);
		#endif
					RegNumber  = i - ((LoopNumber-1)*DIGIT_NUMBER);
					ForceExecute(buffer[cursor],LoopNumber,RegNumber);
					cursor++;
					}
					delay(duration);
				}
		}

		if(G_T==BUFFERING){
			byte spin_buffer[LENGTH_OF_MESSAGE];
				// STORE THE INITIAL VALUE,
					for(uint8_t counter = 0; counter<SPIN_COUNTER; counter++) {
							for(uint8_t id = 0;id<LENGTH_OF_MESSAGE; id++){
								spin_buffer[id] = 0b11000000;
							}
							for(int index = 0;index<5;index++){
								for(int dig = 0;dig < LENGTH_OF_MESSAGE; dig++){
									spin_buffer[dig]=spin_buffer[dig]>>1;
								}
								//SHOW THE SPIN EFFECT, 
								uint8_t cursor = 0;
								uint8_t LoopNumber = 0;
								uint8_t RegNumber = 0;
					#if Correct_Align
						for(int i = digit_pos; i<digit_pos+LENGTH_OF_MESSAGE; i++){
							LoopNumber = givethecursor(i);
					#else 
						for(int i = digit_pos; i>digit_pos-LENGTH_OF_MESSAGE; i--){
							LoopNumber = givethecursor(((DIGIT_NUMBER*Number_of_Device)+1)-i);
					#endif
								RegNumber  = i - ((LoopNumber-1)*DIGIT_NUMBER);
								ForceExecute(spin_buffer[cursor],LoopNumber,RegNumber);
								cursor++;
								}
								delay(duration);
							}
						}
				///RefreshMe();
				uint8_t cursor=0;
				uint8_t LoopNumber = 0;
				uint8_t RegNumber = 0;
					#if Correct_Align
						for(int i = digit_pos; i<digit_pos+LENGTH_OF_MESSAGE; i++){
							LoopNumber = givethecursor(i);
					#else 
						for(int i = digit_pos; i>digit_pos-LENGTH_OF_MESSAGE; i--){
							LoopNumber = givethecursor(((DIGIT_NUMBER*Number_of_Device)+1)-i);
					#endif
								RegNumber  = i - ((LoopNumber-1)*DIGIT_NUMBER);
								ForceExecute(0b00000000,LoopNumber,RegNumber);
								cursor++;
								}
								delay(duration);
							}
		}
	}
	

/*-------------------------------------------------------------------------------------------------
                     WAVE
-------------------------------------------------------------------------------------------------*/

void CK_MAX:: WaveMe(String message, uint16_t duration, uint16_t wait){
	TRANSFER_THIS(message);
	
	byte WAVE_BUFFER[LENGTH_OF_MESSAGE];
	
	/// FIRST PRINT THE MESSAGE BUFFER ....
	    Buffer_Print(MY_MESSAGE_BUFFER, LENGTH_OF_MESSAGE, digit_pos);
	delay(duration);
	
	/// TAKE THE MESSAGE BUFFER
	for(int index = 0; index <LENGTH_OF_MESSAGE; index++){
		WAVE_BUFFER[index] = MY_MESSAGE_BUFFER[index];
	}
	
	for(int index = 0; index <LENGTH_OF_MESSAGE ;index++){
		/// ROTATE SINGLE CHARACTER
		bitWrite(WAVE_BUFFER[index], 0, bitRead(MY_MESSAGE_BUFFER[index], 0));//NEW G - OLD G
		bitWrite(WAVE_BUFFER[index], 1, bitRead(MY_MESSAGE_BUFFER[index], 4));//NEW F - OLD D
		bitWrite(WAVE_BUFFER[index], 2, bitRead(MY_MESSAGE_BUFFER[index], 5));//NEW E - OLD B
		bitWrite(WAVE_BUFFER[index], 3, bitRead(MY_MESSAGE_BUFFER[index], 6));//NEW D - OLD A
		bitWrite(WAVE_BUFFER[index], 4, bitRead(MY_MESSAGE_BUFFER[index], 1));//NEW C - OLD F
		bitWrite(WAVE_BUFFER[index], 5, bitRead(MY_MESSAGE_BUFFER[index], 2));//NEW D - OLD E
		bitWrite(WAVE_BUFFER[index], 6, bitRead(MY_MESSAGE_BUFFER[index], 3));//NEW A - OLD D
		bitClear(WAVE_BUFFER[index], 7);                                   // CLAER THE DECIMAL POINT
		
		/// PRINTIT
		Buffer_Print(WAVE_BUFFER, LENGTH_OF_MESSAGE, digit_pos);
		/// DELAY
		delay(duration);	
	}
	
	delay(duration);
	
	/// AGAIN ROTATE....
	/// PRINTIT
	     int Cursor_pos = 1;
		 int LoopNumber = 0;
		 byte RegNumber = 0;
	    for(int i = digit_pos-LENGTH_OF_MESSAGE+1; i<=digit_pos; i++){
		   LoopNumber = givethecursor(((DIGIT_NUMBER*Number_of_Device)+1)-i);
		   RegNumber  = i - ((LoopNumber-1)*DIGIT_NUMBER);
		   ForceExecute(MY_MESSAGE_BUFFER[LENGTH_OF_MESSAGE-Cursor_pos], LoopNumber, RegNumber);
		   Cursor_pos++;
		   delay(duration);
	    }
		delay(wait);
	if(Internal_Refresh){	
		RefreshMe();
	}
}


/*--------------------------------------------------------------------------------------------------
                 SCROLL_UP      SCROLL_DOWN
---------------------------------------------------------------------------------------------------*/
/**
    \name FlowMe
	\brief It is mainly the scrolling effect. Every character will be scrolled in single frame. It has two category
	             - Scroll Up
				      * In Effect
					  * Out Effect
				 - Scroll down
				      * In Effect
					  * Out Effect
					  
	\def Scroll Up (In 
	
	       a                                    a
		+-----+                              +-----+
	  f |     | b                          f |     |  b 
		|  g  |                    a         |  g  |
		+-----+                 +-----+      +-----+
	  e |     | c             f |     |  b e |     |  c 
		|     |        a        |  g  |      |     |
		+-----+     +-----+     +-----+      +-----+
		   d        |     |     |     |         d
	   (DISPLAY)    |     |     |     |     (FRAME 3)
	                +-----+     +-----+
					|     |    (FRAME 2)
					|     |
					+-----+
				   (FRAME 1)
				   
		0 b 0 0 0 0 0 0 0 0
		   dp a b c d e f g
	        7 6 5 4 3 2 1 0 - index
	
	
		\brief FRAME 1
		     display (d) -> digit (a)   3->6
		\brief FRAME 2
		     display (g) -> digit (a)   0->6
			 display (c) -> digit (b)   4->5
			 disable (d) -> digit (g)   3->0
			 display (e) -> digit (f)   2->1
		\brief FRAME 3
		     display     -> digit
			 
			 
	\def Scroll Up (Out Effect)
	
                                                +-----+
                                                |     |
                                                |     |
                                   +-----+      +-----+
                                   |     |      |     |
	       a            a          |  g  |      |     |
		+-----+      +-----+       +-----+      +-----+
	  f |     | b  f |     |  b  e |     | c       d 
		|  g  |      |  g  |       |     |     (FRAME 3)
		+-----+      +-----+       +-----+
	  e |     | c  e |     |  c       d
		|     |      |     |      (FRAME 2)
		+-----+      +-----+
		   d             d
	   (DISPLAY)     (FRAME 1)
        
        \brief FRAME 1
            display     -> digit
		\brief FRAME 2
            display (a) -> digit (g)
            display (b) -> digit (c)
            display (g) -> digit (d)
            display (f) -> digit (e)
		\brief FRAME 3
            display (a) -> digit (d)

			
    \def Scroll Down (In Effect)
         -> same as Scroll up (Out Effect)		

    \def Scroll Down (Out Effect)		 
	     -> same as Scroll Up (In Effect)

		
*/
void CK_MAX::FlowMe(String message, Flow_Type F_T, Animation_Mode A_M,  uint16_t duration, uint16_t wait){
	TRANSFER_THIS(message);
	
	/// CREATE A SAME LENGTH BOX
	byte box[LENGTH_OF_MESSAGE];

	if(A_M==ENTRY){
		for(uint8_t index = 0; index < LENGTH_OF_MESSAGE ; index++){
			box[index] = 0b00000000;
		}
		
		// IT SHOW THREE STEPS
		for(uint8_t i=0;i<3;i++){
			for(uint8_t index = 0; index < LENGTH_OF_MESSAGE ; index++){
				box[index] = 0b00000000;
				}
			for(uint8_t index = 0;index<LENGTH_OF_MESSAGE;index++){
				if(F_T==GO_UP){
					switch(i){
						case 0:
						bitWrite(box[index], 3, bitRead(MY_MESSAGE_BUFFER[index], 6));
						break;
						
						case 1:
						bitWrite(box[index], 0, bitRead(MY_MESSAGE_BUFFER[index], 6));
						bitWrite(box[index], 2, bitRead(MY_MESSAGE_BUFFER[index], 1));
						bitWrite(box[index], 4, bitRead(MY_MESSAGE_BUFFER[index], 5));
						bitWrite(box[index], 3, bitRead(MY_MESSAGE_BUFFER[index], 0));
						break;
						
						case 2:
						box[index] = MY_MESSAGE_BUFFER[index];
						break;
					}
				}else{
					switch(i){
						case 0:
						bitWrite(box[index], 6, bitRead(MY_MESSAGE_BUFFER[index], 3));
						break;
						
						case 1:
						bitWrite(box[index], 0, bitRead(MY_MESSAGE_BUFFER[index], 3));
						bitWrite(box[index], 6, bitRead(MY_MESSAGE_BUFFER[index], 0));
						bitWrite(box[index], 1, bitRead(MY_MESSAGE_BUFFER[index], 2));
						bitWrite(box[index], 5, bitRead(MY_MESSAGE_BUFFER[index], 4));
						break;
						
						case 2:
						box[index] = MY_MESSAGE_BUFFER[index];
						break;
					}
					
				}
			}
			
			Buffer_Print(box, LENGTH_OF_MESSAGE, digit_pos);
			delay(duration);
		}
		delay(wait);
		if(Internal_Refresh){
			RefreshFrom(digit_pos, digit_pos-LENGTH_OF_MESSAGE);
		}
//EXIT................
   }else{
	   for(uint8_t index = 0; index < LENGTH_OF_MESSAGE ; index++){
			box[index] = 0b00000000;
		}
		
		// IT SHOW THREE STEPS
		for(uint8_t i=0;i<4;i++){
			for(uint8_t index = 0; index < LENGTH_OF_MESSAGE ; index++){
				box[index] = 0b00000000;
				}
			for(uint8_t index = 0;index<LENGTH_OF_MESSAGE;index++){
				if(F_T==GO_UP){
					switch(i){
						case 0:
						box[index] = MY_MESSAGE_BUFFER[index];
						break;
						
						case 1:
						bitWrite(box[index], 0, bitRead(MY_MESSAGE_BUFFER[index], 3));
						bitWrite(box[index], 6, bitRead(MY_MESSAGE_BUFFER[index], 0));
						bitWrite(box[index], 1, bitRead(MY_MESSAGE_BUFFER[index], 2));
						bitWrite(box[index], 5, bitRead(MY_MESSAGE_BUFFER[index], 4));
						break;
						
						case 2:
						bitWrite(box[index], 6, bitRead(MY_MESSAGE_BUFFER[index], 3));
						break;
						
						case 3:
						box[index] = 0b00000000;
						break;
					}
				}else{
					switch(i){
						case 0:
						box[index] = MY_MESSAGE_BUFFER[index];
						break;
						
						case 1:
						bitWrite(box[index], 0, bitRead(MY_MESSAGE_BUFFER[index], 6));
						bitWrite(box[index], 2, bitRead(MY_MESSAGE_BUFFER[index], 1));
						bitWrite(box[index], 4, bitRead(MY_MESSAGE_BUFFER[index], 5));
						bitWrite(box[index], 3, bitRead(MY_MESSAGE_BUFFER[index], 0));
						break;
						
						case 2:
						bitWrite(box[index], 3, bitRead(MY_MESSAGE_BUFFER[index], 6));
						break;
						
						case 3:
						box[index] = 0b00000000;
						break;
					}
					
				}
			}
			
			Buffer_Print(box, LENGTH_OF_MESSAGE, digit_pos);
			delay(duration);
		}
   }
}

/*--------------------------------------------------------------------------------------------------
                 GROW_UP         GROW_DOWN
---------------------------------------------------------------------------------------------------*/
void CK_MAX::GROWME(String message, All_Animations G_T, Animation_Mode A_T, uint16_t duration, uint16_t wait){
	// Transfer the message to corresponding byte
	TRANSFER_THIS(message);
	
	// Take an Array as same Length
	byte Buffer[LENGTH_OF_MESSAGE];
	
	// Initialized
	for(uint8_t index = 0; index<LENGTH_OF_MESSAGE; index++){
		if(A_T==ENTRY){
		  Buffer[index] = 0b00000000;
		}else{
		  Buffer[index] = MY_MESSAGE_BUFFER[index];
		}
	}

	if(G_T==GROW_UP){
		for(uint8_t step = 0; step<6; step++){
			if(A_T==ENTRY){
				for(uint8_t index=0; index<LENGTH_OF_MESSAGE ; index++){
					switch(step){
						case 0:
						bitWrite(Buffer[index], 7, bitRead(MY_MESSAGE_BUFFER[index], 7));
						break;
						
						case 1:
						bitWrite(Buffer[index], 3, bitRead(MY_MESSAGE_BUFFER[index], 3));
						break;
						
						case 2:
						bitWrite(Buffer[index], 2, bitRead(MY_MESSAGE_BUFFER[index], 2));
						bitWrite(Buffer[index], 4, bitRead(MY_MESSAGE_BUFFER[index], 4));
						break;
						
						case 3:
						bitWrite(Buffer[index], 0, bitRead(MY_MESSAGE_BUFFER[index], 0));
						break;
						
						case 4:
						bitWrite(Buffer[index], 5, bitRead(MY_MESSAGE_BUFFER[index], 5));
						bitWrite(Buffer[index], 1, bitRead(MY_MESSAGE_BUFFER[index], 1));
						break;
						
						case 5:
						bitWrite(Buffer[index], 6, bitRead(MY_MESSAGE_BUFFER[index], 6));
						break;
					}
				}
			}else{
			  Buffer_Print(Buffer, LENGTH_OF_MESSAGE, digit_pos);
				for(uint8_t index=0; index<LENGTH_OF_MESSAGE ; index++){
					switch(step){
						case 0:
						bitWrite(Buffer[index], 7, 0);
						break;
						
						case 1:
						bitWrite(Buffer[index], 3, 0);
						break;
						
						case 2:
						bitWrite(Buffer[index], 2, 0);
						bitWrite(Buffer[index], 4, 0);
						break;
						
						case 3:
						bitWrite(Buffer[index], 0, 0);
						break;
						
						case 4:
						bitWrite(Buffer[index], 5, 0);
						bitWrite(Buffer[index], 1, 0);
						break;
						
						case 5:
						bitWrite(Buffer[index], 6, 0);
						break;
					}
				}
			}
			  Buffer_Print(Buffer, LENGTH_OF_MESSAGE, digit_pos);
			  delay(duration);
		}
	}else{
			  
			  for(uint8_t step = 0; step<6; step++){
			if(A_T==ENTRY){
				for(uint8_t index=0; index<LENGTH_OF_MESSAGE ; index++){
					switch(step){
						case 0:
						bitWrite(Buffer[index], 6, bitRead(MY_MESSAGE_BUFFER[index], 6));
						break;
						
						case 1:
						bitWrite(Buffer[index], 5, bitRead(MY_MESSAGE_BUFFER[index], 5));
						bitWrite(Buffer[index], 1, bitRead(MY_MESSAGE_BUFFER[index], 1));
						break;
						
						case 2:
						bitWrite(Buffer[index], 0, bitRead(MY_MESSAGE_BUFFER[index], 0));
						break;
						
						case 3:
						bitWrite(Buffer[index], 2, bitRead(MY_MESSAGE_BUFFER[index], 2));
						bitWrite(Buffer[index], 4, bitRead(MY_MESSAGE_BUFFER[index], 4));
						break;
						
						case 4:
						bitWrite(Buffer[index], 3, bitRead(MY_MESSAGE_BUFFER[index], 3));
						break;
						
						case 5:
						bitWrite(Buffer[index], 7, bitRead(MY_MESSAGE_BUFFER[index], 7));
						break;
					}
				}
			}else{
				for(uint8_t index=0; index<LENGTH_OF_MESSAGE ; index++){
					switch(step){
						case 0:
						bitWrite(Buffer[index], 6, 0);
						break;
						
						case 1:
						bitWrite(Buffer[index], 5, 0);
						bitWrite(Buffer[index], 1, 0);
						break;
						
						case 2:
						bitWrite(Buffer[index], 0, 0);
						break;
						
						case 3:
						bitWrite(Buffer[index], 2, 0);
						bitWrite(Buffer[index], 4, 0);
						break;
						
						case 4:
						bitWrite(Buffer[index], 3, 0);
						break;
						
						case 5:
						bitWrite(Buffer[index], 7, 0);
						break;
					}
				}
			}
			Buffer_Print(Buffer, LENGTH_OF_MESSAGE, digit_pos);
			delay(duration);
		}
	}	
		if(A_T==ENTRY){
			delay(wait);
			if(Internal_Refresh){
			  RefreshMe();
			}
		}
}

/*--------------------------------------------------------------------------------------------------
                 MAKE            BREAK
---------------------------------------------------------------------------------------------------*/
void CK_MAX::BuildMe(String message,Build_Type B_T,Animation_Mode A_M, uint16_t duration, uint16_t wait){
	TRANSFER_THIS(message);
	
	byte MY_BUFFER_ML[LENGTH_OF_MESSAGE];

///************************ANIMATION ENTRY****************************///
if(A_M == ENTRY){
	for(uint8_t index = 0; index < LENGTH_OF_MESSAGE ; index++){
		if(B_T == BREAKING){
			MY_BUFFER_ML[index] = 0b11111111;
		}else{
			MY_BUFFER_ML[index] = 0b00000000;
		}
		
	}
    Buffer_Print(MY_BUFFER_ML, LENGTH_OF_MESSAGE, digit_pos);
		  delay(duration);
		  
		  
	for(uint16_t index = 0; index<LENGTH_OF_MESSAGE; index++){
		for(uint8_t bitIndex = 0; bitIndex < 8; bitIndex++){
			if(B_T == BREAKING){
				if(bitRead(MY_MESSAGE_BUFFER[index], bitIndex)==0){
					bitWrite(MY_BUFFER_ML[index], bitIndex, 0);
					delay(duration);
				}
			}else{
				if(bitRead(MY_MESSAGE_BUFFER[index], bitIndex)==1){
					bitWrite(MY_BUFFER_ML[index], bitIndex, 1);
					delay(duration);
				}
			}
			Buffer_Print(MY_BUFFER_ML, LENGTH_OF_MESSAGE, digit_pos);
		}
	}
	delay(wait);
	if(Internal_Refresh){
		RefreshMe();
	}
}
	      
	
	

///**********************ANIMATION EXIT**************************************
if(A_M==EXIT){
	/// PRINT THE MESSAGE FIRST,
	       Buffer_Print(MY_MESSAGE_BUFFER, LENGTH_OF_MESSAGE, digit_pos);

		for(int index = 0;index<LENGTH_OF_MESSAGE;index++){
			MY_BUFFER_ML[index] = MY_MESSAGE_BUFFER[index];
		}

	/// IF MAKE...
	if(B_T==MAKING){
		for(uint8_t digit = 0; digit <LENGTH_OF_MESSAGE ; digit++){
			for(uint8_t bitIndex = 0; bitIndex<8; bitIndex++){
				if(bitRead(MY_BUFFER_ML[digit], bitIndex)==0){
					bitWrite(MY_BUFFER_ML[digit], bitIndex, 1);
					delay(duration);
				}
				Buffer_Print(MY_BUFFER_ML, LENGTH_OF_MESSAGE, digit_pos);
			   }
		   }
		   if(Internal_Refresh){
		    RefreshMe();
	      }
	    }else{
			for(uint8_t digit = 0; digit <LENGTH_OF_MESSAGE ; digit++){
				for(uint8_t bitIndex = 0; bitIndex<8; bitIndex++){
					if(bitRead(MY_BUFFER_ML[digit], bitIndex)==1){
						bitWrite(MY_BUFFER_ML[digit], bitIndex, 0);
						delay(duration);
					}
					Buffer_Print(MY_BUFFER_ML, LENGTH_OF_MESSAGE, digit_pos);
				}
			}
		}
    }	
}

/*--------------------------------------------------------------------------------------------------
                 SCAN_TOP              SCRAN_BOTTOM
---------------------------------------------------------------------------------------------------*/
void CK_MAX::ScanMe(String message, Scan_Type S_T, Animation_Mode A_M,uint16_t duration, uint16_t wait){
	TRANSFER_THIS(message);
	
	byte Frame[LENGTH_OF_MESSAGE];

	//************************ENTRY ANIMATION*******************************************
if(A_M==ENTRY){
	for(uint8_t index = 0;index < LENGTH_OF_MESSAGE ;index++){
		Frame[index] = 0b00000000;
	}
	for(uint8_t seq = 0; seq <8 ;seq++){
		for(uint8_t digit = 0; digit<LENGTH_OF_MESSAGE; digit++){
			if(S_T==TOP){
			  switch(seq){
				  case 0:
				  bitWrite(Frame[digit], 6, bitRead(MY_MESSAGE_BUFFER[digit], 6));
				  break;
				  
				  case 1:
				  bitWrite(Frame[digit], 1, bitRead(MY_MESSAGE_BUFFER[digit], 1));
				  break;
				  
				  case 2:
				  bitWrite(Frame[digit], 5, bitRead(MY_MESSAGE_BUFFER[digit], 5));
				  break;
				  
				  case 3:
				  bitWrite(Frame[digit], 0, bitRead(MY_MESSAGE_BUFFER[digit], 0));
				  break;
				  
				  case 4:
				  bitWrite(Frame[digit], 2, bitRead(MY_MESSAGE_BUFFER[digit], 2));
				  break;
				  
				  case 5:
				  bitWrite(Frame[digit], 4, bitRead(MY_MESSAGE_BUFFER[digit], 4));
				  break;
				  
				  case 6:
				  bitWrite(Frame[digit], 3, bitRead(MY_MESSAGE_BUFFER[digit], 3));
				  break;
				  
				  case 7:
				  bitWrite(Frame[digit], 7, bitRead(MY_MESSAGE_BUFFER[digit], 7));
				  break;
				   
			    }
			}else{
				 switch(seq){
				  case 0:
				  bitWrite(Frame[digit], 7, bitRead(MY_MESSAGE_BUFFER[digit], 7));
				  break;
				  
				  case 1:
				  bitWrite(Frame[digit], 3, bitRead(MY_MESSAGE_BUFFER[digit], 3));
				  break;
				  
				  case 2:
				  bitWrite(Frame[digit], 4, bitRead(MY_MESSAGE_BUFFER[digit], 4));
				  break;
				  
				  case 3:
				  bitWrite(Frame[digit], 2, bitRead(MY_MESSAGE_BUFFER[digit], 2));
				  break;
				  
				  case 4:
				  bitWrite(Frame[digit], 0, bitRead(MY_MESSAGE_BUFFER[digit], 0));
				  break;
				  
				  case 5:
				  bitWrite(Frame[digit], 5, bitRead(MY_MESSAGE_BUFFER[digit], 5));
				  break;
				  
				  case 6:
				  bitWrite(Frame[digit], 1, bitRead(MY_MESSAGE_BUFFER[digit], 1));
				  break;
				  
				  case 7:
				  bitWrite(Frame[digit], 6, bitRead(MY_MESSAGE_BUFFER[digit], 6));
				  break;
			   
		        } 
			}
		Buffer_Print(Frame, LENGTH_OF_MESSAGE, digit_pos);
		  delay(duration);
		}
	}
	delay(wait);
	if(Internal_Refresh){
		RefreshMe();
	}
}
///***********EXIT************
else{
	// SAVE THE FRAME
	for(uint8_t index = 0; index <LENGTH_OF_MESSAGE ;index++){
		Frame[index] = MY_MESSAGE_BUFFER[index];
	}
//PRINT THE TEXT FIRST,
        Buffer_Print(Frame, LENGTH_OF_MESSAGE, digit_pos);

		for(uint8_t seq = 0; seq <8 ;seq++){
		for(uint8_t digit = 0; digit<LENGTH_OF_MESSAGE; digit++){
			if(S_T==TOP){
			  switch(seq){
				  case 0:
				  bitClear(Frame[digit], 6);
				  break;
				  
				  case 1:
				  bitClear(Frame[digit], 1);
				  break;
				  
				  case 2:
				  bitClear(Frame[digit], 5);
				  break;
				  
				  case 3:
				  bitClear(Frame[digit], 0);
				  break;
				  
				  case 4:
				  bitClear(Frame[digit], 2);
				  break;
				  
				  case 5:
				  bitClear(Frame[digit], 4);
				  break;
				  
				  case 6:
				  bitClear(Frame[digit], 3);
				  break;
				  
				  case 7:
				  bitClear(Frame[digit], 7);
				  break;
				   
			    }
			}else{
				 switch(seq){
				  case 0:
				  bitClear(Frame[digit], 7);
				  break;
				  
				  case 1:
				  bitClear(Frame[digit], 3);
				  break;
				  
				  case 2:
				  bitClear(Frame[digit], 4);
				  break;
				  
				  case 3:
				  bitClear(Frame[digit], 2);
				  break;
				  
				  case 4:
				  bitClear(Frame[digit], 0);
				  break;
				  
				  case 5:
				  bitClear(Frame[digit], 5);
				  break;
				  
				  case 6:
				  bitClear(Frame[digit], 1);
				  break;
				  
				  case 7:
				  bitClear(Frame[digit], 6);
				  break;
			   
		        } 
			}
		Buffer_Print(Frame, LENGTH_OF_MESSAGE, digit_pos);
		  delay(duration);
		}
	  }		
    }
  }
  
/*--------------------------------------------------------------------------------------------------
                 SCROLL_LEFT            SCROLL_RIGHT
---------------------------------------------------------------------------------------------------*/
void CK_MAX::ScrollMe(String message,Scroll_Type S_t, uint16_t duration){
    TRANSFER_THIS(message);
	Serial.println(message);
 
/// TAKE A DISPLAY BUFFER, AND SIZE OF THIS ARRAY WILL BE THE DISPLAY SIZE AND THE DOUBLE SIZE OF THE MESSAGE
	uint16_t size_of_buffer = (Number_of_Device * DIGIT_NUMBER) + (2*LENGTH_OF_MESSAGE);
	byte display_buffer[size_of_buffer];
	Serial.println(size_of_buffer);
/// CLEAR THIS BUFFER
	for(int x = 0;x<size_of_buffer;x++){
		display_buffer[x] = 0;
	}
/// TAKE THE MESSAGE BUFFER INTO THE DISPLAY BUFFER
	if(S_t == LEFT_TO_RIGHT){
		for(int x=0;x<LENGTH_OF_MESSAGE;x++){
			display_buffer[x] = MY_MESSAGE_BUFFER[x];
		}
	}else{
		for(int x=1;x<=LENGTH_OF_MESSAGE;x++){
			display_buffer[size_of_buffer-x] = MY_MESSAGE_BUFFER[LENGTH_OF_MESSAGE-x];
		}
	}

   int Buffer_position = 0;
   while(Buffer_position<(size_of_buffer-LENGTH_OF_MESSAGE)){
	   if(S_t==LEFT_TO_RIGHT){
		   for(int x = Buffer_position+LENGTH_OF_MESSAGE; x>Buffer_position; x--){
		      display_buffer[x] = display_buffer[x-1];
	     }
	   }else{
		   for(int x = size_of_buffer-(LENGTH_OF_MESSAGE+Buffer_position)-1;x<=(size_of_buffer-Buffer_position)-1;x++){
			   display_buffer[x] = display_buffer[x+1];
		   }
	   }  
	   if(S_t==LEFT_TO_RIGHT){display_buffer[Buffer_position] = 0; }
	   else{ display_buffer[size_of_buffer-Buffer_position-1] = 0; }
	   
	   int LoopNumber = 0;
	   byte RegNumber = 0;
	   // DISPLAY SECTION.....
	   int Cursor_pos = 0;
	   for(int i = Number_of_Device*DIGIT_NUMBER; i>0; i--){
		   LoopNumber = givethecursor(((DIGIT_NUMBER*Number_of_Device)+1)-i);
		   RegNumber  = i - ((LoopNumber-1)*DIGIT_NUMBER);
		   ForceExecute(display_buffer[LENGTH_OF_MESSAGE+Cursor_pos], LoopNumber, RegNumber);
		   Cursor_pos++;
	   }

	   // WAIT THE GIVEN TIME
	   delay(duration);

	   // INCREMENT THE BUFFER POSITION
	   Buffer_position++;
   }
}
/*--------------------------------------------------------------------------------------------------
                 SCROLL_UP_RANDOM           SCROLL_DOWN_RANDOM
---------------------------------------------------------------------------------------------------*/
void CK_MAX::ScrollMeRand(String message, Random_Scroll_Type R_T, Animation_Mode A_M, uint16_t duration, uint16_t wait){
	TRANSFER_THIS(message);
	
	byte BUFFER_SR[LENGTH_OF_MESSAGE];
	for(uint8_t index=0;index<LENGTH_OF_MESSAGE;index++){
		BUFFER_SR[index] =(byte)0;
	}
	
	/// RANDOMIZED
	int signeture[LENGTH_OF_MESSAGE];
	for(uint8_t index =0 ;index<LENGTH_OF_MESSAGE; index++){
		signeture[index]=-1;
	}
	uint8_t MY_CURSOR = 0;
	uint8_t Generated_number;
	while(MY_CURSOR < LENGTH_OF_MESSAGE){
		Generated_number = random(0, LENGTH_OF_MESSAGE);
		bool flag = false;
		for(uint8_t index=0;index<MY_CURSOR+1; index++){
			if(Generated_number == signeture[index]){
				flag = true;
			}
		}
		if(!flag){
			signeture[MY_CURSOR] = Generated_number;
			MY_CURSOR++;
		}
	}
uint8_t digit_index;
	if(A_M==ENTRY){
		for(uint8_t _index = 0; _index<LENGTH_OF_MESSAGE;_index++){
			for(uint8_t step = 0; step < 3;step ++){
				digit_index = signeture[_index];
				BUFFER_SR[digit_index] = 0b00000000;
				if(R_T==S_U_R){
					switch(step){
						case 0:
						bitWrite(BUFFER_SR[digit_index], 3, bitRead(MY_MESSAGE_BUFFER[digit_index], 6));
						break;
						
						case 1:
						bitWrite(BUFFER_SR[digit_index], 0, bitRead(MY_MESSAGE_BUFFER[digit_index], 6));
						bitWrite(BUFFER_SR[digit_index], 2, bitRead(MY_MESSAGE_BUFFER[digit_index], 1));
						bitWrite(BUFFER_SR[digit_index], 4, bitRead(MY_MESSAGE_BUFFER[digit_index], 5));
						bitWrite(BUFFER_SR[digit_index], 3, bitRead(MY_MESSAGE_BUFFER[digit_index], 0));
						break;
						
						case 2:
						BUFFER_SR[digit_index] = MY_MESSAGE_BUFFER[digit_index];
						break;
					}
				}else{
					switch(step){
						case 0:
						bitWrite(BUFFER_SR[digit_index], 6, bitRead(MY_MESSAGE_BUFFER[digit_index], 3));
						break;
						
						case 1:
						bitWrite(BUFFER_SR[digit_index], 0, bitRead(MY_MESSAGE_BUFFER[digit_index], 3));
						bitWrite(BUFFER_SR[digit_index], 6, bitRead(MY_MESSAGE_BUFFER[digit_index], 0));
						bitWrite(BUFFER_SR[digit_index], 1, bitRead(MY_MESSAGE_BUFFER[digit_index], 2));
						bitWrite(BUFFER_SR[digit_index], 5, bitRead(MY_MESSAGE_BUFFER[digit_index], 4));
						break;
						
						case 2:
						BUFFER_SR[digit_index] = MY_MESSAGE_BUFFER[digit_index];
						break;
					}
					
				}
				Buffer_Print(BUFFER_SR, LENGTH_OF_MESSAGE, digit_pos);
				delay(duration);
			}
		}
		delay(wait);
		if(Internal_Refresh){
			RefreshMe();
		}
	}else{
		for(uint8_t index=0;index<LENGTH_OF_MESSAGE;index++){
		BUFFER_SR[index] =MY_MESSAGE_BUFFER[index];
	}
		       Buffer_Print(BUFFER_SR, LENGTH_OF_MESSAGE, digit_pos);
		for(uint8_t _index = 0; _index<LENGTH_OF_MESSAGE;_index++){
			for(uint8_t step = 0; step < 4;step ++){
				digit_index = signeture[_index];
				BUFFER_SR[digit_index] = 0b00000000;
				if(R_T==S_U_R){
					switch(step){
						case 0:
						BUFFER_SR[digit_index] = MY_MESSAGE_BUFFER[digit_index];
						break;
						
						case 1:
						bitWrite(BUFFER_SR[digit_index], 0, bitRead(MY_MESSAGE_BUFFER[digit_index], 3));
						bitWrite(BUFFER_SR[digit_index], 6, bitRead(MY_MESSAGE_BUFFER[digit_index], 0));
						bitWrite(BUFFER_SR[digit_index], 1, bitRead(MY_MESSAGE_BUFFER[digit_index], 2));
						bitWrite(BUFFER_SR[digit_index], 5, bitRead(MY_MESSAGE_BUFFER[digit_index], 4));
						break;
						
						case 2:
						bitWrite(BUFFER_SR[digit_index], 6, bitRead(MY_MESSAGE_BUFFER[digit_index], 3));
						break;
						
						case 3:
						BUFFER_SR[digit_index] = 0b00000000;
						break;
					}
				}else{
					switch(step){
						case 0:
						BUFFER_SR[digit_index] = MY_MESSAGE_BUFFER[digit_index];
						break;
						
						case 1:
						bitWrite(BUFFER_SR[digit_index], 0, bitRead(MY_MESSAGE_BUFFER[digit_index], 6));
						bitWrite(BUFFER_SR[digit_index], 2, bitRead(MY_MESSAGE_BUFFER[digit_index], 1));
						bitWrite(BUFFER_SR[digit_index], 4, bitRead(MY_MESSAGE_BUFFER[digit_index], 5));
						bitWrite(BUFFER_SR[digit_index], 3, bitRead(MY_MESSAGE_BUFFER[digit_index], 0));
						break;
						
						case 2:
						bitWrite(BUFFER_SR[digit_index], 3, bitRead(MY_MESSAGE_BUFFER[digit_index], 6));
						break;
						
						case 3:
						BUFFER_SR[digit_index] = 0b00000000;
						break;
					}
					
				}
				Buffer_Print(BUFFER_SR, LENGTH_OF_MESSAGE, digit_pos);
				delay(duration);
			}
		}
	}
}
/*--------------------------------------------------------------------------------------------------
                 SCROLL_UP_SINGLE            SCROLL_DOWN_SINGLE
---------------------------------------------------------------------------------------------------*/
void CK_MAX::ScrollMeNew(String message, Scroll_New_Type S_T, Animation_Mode A_M, uint16_t duration, uint16_t wait){
	TRANSFER_THIS(message);
	
	byte BUFFER[LENGTH_OF_MESSAGE];
	for(uint8_t index=0;index<LENGTH_OF_MESSAGE;index++){
		BUFFER[index] =(byte)0;
	}
	
	if(A_M==ENTRY){
		for(uint8_t digit_index = 0; digit_index<LENGTH_OF_MESSAGE;digit_index++){
			for(uint8_t step = 0; step < 3;step ++){
				BUFFER[digit_index] = 0b00000000;
				if(S_T==S_U_S){
					switch(step){
						case 0:
						bitWrite(BUFFER[digit_index], 3, bitRead(MY_MESSAGE_BUFFER[digit_index], 6));
						break;
						
						case 1:
						bitWrite(BUFFER[digit_index], 0, bitRead(MY_MESSAGE_BUFFER[digit_index], 6));
						bitWrite(BUFFER[digit_index], 2, bitRead(MY_MESSAGE_BUFFER[digit_index], 1));
						bitWrite(BUFFER[digit_index], 4, bitRead(MY_MESSAGE_BUFFER[digit_index], 5));
						bitWrite(BUFFER[digit_index], 3, bitRead(MY_MESSAGE_BUFFER[digit_index], 0));
						break;
						
						case 2:
						BUFFER[digit_index] = MY_MESSAGE_BUFFER[digit_index];
						break;
					}
				}else{
					switch(step){
						case 0:
						bitWrite(BUFFER[digit_index], 6, bitRead(MY_MESSAGE_BUFFER[digit_index], 3));
						break;
						
						case 1:
						bitWrite(BUFFER[digit_index], 0, bitRead(MY_MESSAGE_BUFFER[digit_index], 3));
						bitWrite(BUFFER[digit_index], 6, bitRead(MY_MESSAGE_BUFFER[digit_index], 0));
						bitWrite(BUFFER[digit_index], 1, bitRead(MY_MESSAGE_BUFFER[digit_index], 2));
						bitWrite(BUFFER[digit_index], 5, bitRead(MY_MESSAGE_BUFFER[digit_index], 4));
						break;
						
						case 2:
						BUFFER[digit_index] = MY_MESSAGE_BUFFER[digit_index];
						break;
					}
					
				}
				Buffer_Print(BUFFER, LENGTH_OF_MESSAGE, digit_pos);
				delay(duration);
			}
		}
		delay(wait);
		if(Internal_Refresh){
			RefreshMe();
		}
	}else{
		for(uint8_t index=0;index<LENGTH_OF_MESSAGE;index++){
		BUFFER[index] =MY_MESSAGE_BUFFER[index];
	}
		       Buffer_Print(BUFFER, LENGTH_OF_MESSAGE, digit_pos);
		for(uint8_t digit_index = 0; digit_index<LENGTH_OF_MESSAGE;digit_index++){
			for(uint8_t step = 0; step < 4;step ++){
				BUFFER[digit_index] = 0b00000000;
				if(S_T==S_U_S){
					switch(step){
						case 0:
						BUFFER[digit_index] = MY_MESSAGE_BUFFER[digit_index];
						break;
						
						case 1:
						bitWrite(BUFFER[digit_index], 0, bitRead(MY_MESSAGE_BUFFER[digit_index], 3));
						bitWrite(BUFFER[digit_index], 6, bitRead(MY_MESSAGE_BUFFER[digit_index], 0));
						bitWrite(BUFFER[digit_index], 1, bitRead(MY_MESSAGE_BUFFER[digit_index], 2));
						bitWrite(BUFFER[digit_index], 5, bitRead(MY_MESSAGE_BUFFER[digit_index], 4));
						break;
						
						case 2:
						bitWrite(BUFFER[digit_index], 6, bitRead(MY_MESSAGE_BUFFER[digit_index], 3));
						break;
						
						case 3:
						BUFFER[digit_index] = 0b00000000;
						break;
					}
				}else{
					switch(step){
						case 0:
						BUFFER[digit_index] = MY_MESSAGE_BUFFER[digit_index];
						break;
						
						case 1:
						bitWrite(BUFFER[digit_index], 0, bitRead(MY_MESSAGE_BUFFER[digit_index], 6));
						bitWrite(BUFFER[digit_index], 2, bitRead(MY_MESSAGE_BUFFER[digit_index], 1));
						bitWrite(BUFFER[digit_index], 4, bitRead(MY_MESSAGE_BUFFER[digit_index], 5));
						bitWrite(BUFFER[digit_index], 3, bitRead(MY_MESSAGE_BUFFER[digit_index], 0));
						break;
						
						case 2:
						bitWrite(BUFFER[digit_index], 3, bitRead(MY_MESSAGE_BUFFER[digit_index], 6));
						break;
						
						case 3:
						BUFFER[digit_index] = 0b00000000;
						break;
					}
					
				}
				Buffer_Print(BUFFER, LENGTH_OF_MESSAGE, digit_pos);
				delay(duration);
			}
		}
	}
}


/*--------------------------------------------------------------------------------------------------
                 SLICE_OWN                   SLICE_ALL
---------------------------------------------------------------------------------------------------*/
/**
   \name  SliceMe
   \brief Slicing Effect Acts on a single character. It's has two category
           - slice all
		       * Effect In
			   * Effect Out
		   - slice own
		       * Effect In
			   * Effect Out
			   
	\def slice all (In effect)
	    -> Display Initially clear from Digit position(digit_pos) to digit_pos + length of message.
		-> First Character of message( \param ) come from (digit_pos + length of message) and fixed to digit pos.
		-> Second Character of message( \param ) come from (digit_pos + length of message) and fixed to digit_pos+1
		-> Every step's digit will be cleared ( it is the only difference from the slice own).
		
	\def slice all (Out effect)
	    -> First print the message( \param ) in the display.
		-> Every time take last character and slide until the position will be maximum (Number_of_Device*DIGIT_NUMBER)
		-> And Every step must be cleared.
		
	\def slice own (In effect)
	    -> Only difference from slice all is, it doestn't clear any digit.
		-> Character will be over written.
		
	\def slice own (Out effect)
	    -> Print the message ( \param )
	    -> Simply Remove from the last character of the message ( \param ).
		   
*/
void CK_MAX::SliceMe(String message, Slicing_Type S_T,Animation_Mode A_M, uint16_t duration, uint16_t wait){
	TRANSFER_THIS(message);
	
	///..........MAIN SECTION................///
	if(A_M==ENTRY){
		uint8_t cursor = 0;
		uint8_t Loop = 0;
		byte Reg = 0;
		byte Current_Digit = 0;
			for(uint8_t Stay_Here = digit_pos ; Stay_Here>=digit_pos - LENGTH_OF_MESSAGE ;Stay_Here--){
				for(uint16_t buf = digit_pos - LENGTH_OF_MESSAGE +1 ; buf<=digit_pos-cursor; buf++){
					Loop = givethecursor(((DIGIT_NUMBER*Number_of_Device)+1)-buf);
					Reg  = buf - ((Loop-1)*DIGIT_NUMBER);
					ForceExecute(MY_MESSAGE_BUFFER[cursor], Loop, Reg);
					if(S_T==ALL_SLICE){
						Loop = givethecursor(((DIGIT_NUMBER*Number_of_Device)+1)-(buf+1));
						Reg  = (buf-1) - ((Loop-1)*DIGIT_NUMBER);
						ForceExecute(0b00000000, Loop, Reg);
					}
					delay(duration);
				}
				cursor++;
			}
			delay(wait);
		if(Internal_Refresh){
			RefreshMe();
		}
	}else{
		if(S_T==OWN_SLICE){
			/// PRINT THE MESSAGE FIRST.....
			int LoopNumber = 0;
			byte RegNumber = 0;
			// DISPLAY SECTION.....
			int Cursor_pos = 0;
			for(int i = digit_pos; i>digit_pos-LENGTH_OF_MESSAGE; i--){
				LoopNumber = givethecursor(((DIGIT_NUMBER*Number_of_Device)+1)-i);
				RegNumber  = i - ((LoopNumber-1)*DIGIT_NUMBER);
				ForceExecute(MY_MESSAGE_BUFFER[Cursor_pos], LoopNumber, RegNumber);
				Cursor_pos++;
			}

			/// THEN LIT OFF ONE ARFER ONE DIGIT
			Cursor_pos=0;
			for(int i = digit_pos; i>digit_pos-LENGTH_OF_MESSAGE; i--){
				LoopNumber = givethecursor(((DIGIT_NUMBER*Number_of_Device)+1)-i);
				RegNumber  = i - ((LoopNumber-1)*DIGIT_NUMBER);
				ForceExecute(0b00000000, LoopNumber, RegNumber);
				Cursor_pos++;
				delay(duration);
			}
		}else{
			// DIPLAY BUFFER
			byte DISPLAY_BUFFER_SL[LENGTH_OF_MESSAGE];
			// STORE THE VALUE
			for(uint8_t index = 0; index<LENGTH_OF_MESSAGE; index++){
				DISPLAY_BUFFER_SL[index]=MY_MESSAGE_BUFFER[index];
			}
			// PRINT THE LINE FIRST
			int LoopNumber = 0;
			byte RegNumber = 0;
			int Cursor_pos = 0;
			for(int i = digit_pos; i>digit_pos-LENGTH_OF_MESSAGE; i--){
				LoopNumber = givethecursor(((DIGIT_NUMBER*Number_of_Device)+1)-i);
				RegNumber  = i - ((LoopNumber-1)*DIGIT_NUMBER);
				ForceExecute(DISPLAY_BUFFER_SL[Cursor_pos], LoopNumber, RegNumber);
				Cursor_pos++;
			}

            uint8_t digit_index = LENGTH_OF_MESSAGE-1;
			for(int location = digit_pos-LENGTH_OF_MESSAGE+1 ; location<=digit_pos; location++){
			    if(DISPLAY_BUFFER_SL[digit_index] != 0b00000000){ //IGNROE THE SPACE
					for(int slide = location; slide>=0;slide--){
						LoopNumber = givethecursor(((DIGIT_NUMBER*Number_of_Device)+1)-slide);
						RegNumber  = slide - ((LoopNumber-1)*DIGIT_NUMBER);
						ForceExecute(DISPLAY_BUFFER_SL[digit_index], LoopNumber, RegNumber);
						delay(duration);
						ForceExecute(0b00000000, LoopNumber, RegNumber);
				    }
				}				
				digit_index--;
			}
		}
	}
			
}


/**

*/

void CK_MAX :: RandomizeMe(String message,  uint16_t duration, uint16_t wait){
	TRANSFER_THIS(message);

	/****************RANDOMIZED THE NUMBER***********************/
  int signeture[LENGTH_OF_MESSAGE];
  for (uint8_t index = 0 ; index < LENGTH_OF_MESSAGE; index++) {
    signeture[index] = -1;
  }
  uint8_t MY_CURSOR = 0;
  uint8_t Generated_number;
  while (MY_CURSOR < LENGTH_OF_MESSAGE) {
    Generated_number = random(0, LENGTH_OF_MESSAGE);
    bool flag = false;
    for (uint8_t index = 0; index < MY_CURSOR + 1; index++) {
      if (Generated_number == signeture[index]) {
        flag = true;
      }
    }
    if (!flag) {
      signeture[MY_CURSOR] = Generated_number;
      MY_CURSOR++;
    }
  }
  /******************END RANDOMIZED*******************************/
  byte BUFFER[LENGTH_OF_MESSAGE];
    for (uint8_t i = 0; i < LENGTH_OF_MESSAGE; i++) {
          BUFFER[i] = MY_MESSAGE_BUFFER[signeture[i]];
        }
	Buffer_Print(BUFFER);
	
  uint8_t temp = 0;
  for (uint8_t index = 0 ; index < LENGTH_OF_MESSAGE; index++) {
    for (uint8_t subIndex = 0; subIndex < LENGTH_OF_MESSAGE - index; subIndex++) {
      if (signeture[subIndex] > signeture[subIndex + 1]) {
        temp = signeture[subIndex];
        signeture[subIndex] = signeture[subIndex + 1];
        signeture[subIndex+1] = temp;
		
		for(uint8_t index = 0; index<7 ;index++){
			switch(index){
				case 0:
				bitClear(BUFFER[subIndex], 7);
				break;
				
				case 1:
				bitClear(BUFFER[subIndex], 3);
				bitClear(BUFFER[subIndex+1], 6);
				break;
				
				case 2:
				bitClear(BUFFER[subIndex], 2);
				bitClear(BUFFER[subIndex], 4);
				bitClear(BUFFER[subIndex+1], 1);
				bitClear(BUFFER[subIndex+1], 5);
				break;
				
				case 3:
				bitClear(BUFFER[subIndex], 0);
				bitClear(BUFFER[subIndex+1], 0);
				break;
				
				case 4:
				bitClear(BUFFER[subIndex], 1);
				bitClear(BUFFER[subIndex], 5);
				bitClear(BUFFER[subIndex+1], 2);
				bitClear(BUFFER[subIndex+1], 4);
				break;
				
				case 5:
				bitClear(BUFFER[subIndex], 6);
				bitClear(BUFFER[subIndex+1], 3);
				break;
				
				case 6:
				bitClear(BUFFER[subIndex+1], 7);
				break;
			}
			Buffer_Print(BUFFER);
			delay(duration);
		}

		byte SEC_BUF[2];
        for (uint8_t i = 0; i < LENGTH_OF_MESSAGE; i++) {
			if(i!=subIndex && i!=(subIndex+1)){
				BUFFER[i] = MY_MESSAGE_BUFFER[signeture[i]];
			}else{
			   i == subIndex ? 	SEC_BUF[0] = MY_MESSAGE_BUFFER[signeture[i]] : SEC_BUF[1] = MY_MESSAGE_BUFFER[signeture[i]];
			}
        }
		
		for(uint8_t index = 0; index<7 ;index++){
			switch(index){
				case 0:
				bitWrite(BUFFER[subIndex], 7, bitRead(SEC_BUF[0], 7));
				break;
				
				case 1:
				bitWrite(BUFFER[subIndex], 3, bitRead(SEC_BUF[0], 3));
				bitWrite(BUFFER[subIndex+1], 6, bitRead(SEC_BUF[1], 6));
				break;
				
				case 2:
				bitWrite(BUFFER[subIndex], 2, bitRead(SEC_BUF[0], 2));
				bitWrite(BUFFER[subIndex], 4, bitRead(SEC_BUF[0], 4));
				bitWrite(BUFFER[subIndex+1], 1, bitRead(SEC_BUF[1], 1));
				bitWrite(BUFFER[subIndex+1], 5, bitRead(SEC_BUF[1], 5));
				break;
				
				case 3:
				bitWrite(BUFFER[subIndex], 0, bitRead(SEC_BUF[0], 0));
				bitWrite(BUFFER[subIndex+1], 0, bitRead(SEC_BUF[1], 0));
				break;
				
				case 4:
				bitWrite(BUFFER[subIndex], 1, bitRead(SEC_BUF[0], 1));
				bitWrite(BUFFER[subIndex], 5, bitRead(SEC_BUF[0], 5));
				bitWrite(BUFFER[subIndex+1], 2, bitRead(SEC_BUF[1], 2));
				bitWrite(BUFFER[subIndex+1], 4, bitRead(SEC_BUF[1], 4));
				break;
				
				case 5:
				bitWrite(BUFFER[subIndex], 6, bitRead(SEC_BUF[0], 6));
				bitWrite(BUFFER[subIndex+1], 3, bitRead(SEC_BUF[1], 3));
				break;
				
				case 6:
				bitWrite(BUFFER[subIndex+1], 7, bitRead(SEC_BUF[1], 7));
				break;
			}
			Buffer_Print(BUFFER);
			delay(duration);
		}

        Buffer_Print(BUFFER);
		delay(duration);
      }
    }
  }
    delay(wait);
	if(Internal_Refresh){
	  RefreshMe();
	}
}
/*
        -------------------------------------------------------------------
        ! WARNING ! - THESE TWO EFFECTS CREATES BUGS FOR ARDUINO MEGA...... 
		-------------------------------------------------------------------
void CK_MAX :: SortMe(String message, Animation_Mode A_M, uint16_t duration, uint16_t wait){
	TRANSFER_THIS(message);
	byte my_buffer[LENGTH_OF_MESSAGE];
	
	if(A_M==ENTRY){
		for(uint8_t index = 0; index<LENGTH_OF_MESSAGE; index++){
			my_buffer[index] = 0b00000000;
		}
		
		for(uint8_t character = 0; character < LENGTH_OF_MESSAGE; character++){
			for(uint8_t step = 0; step < 4; step++){
				switch(step){
					case 0:
					bitWrite(my_buffer[character],1, bitRead(MY_MESSAGE_BUFFER[character],1));
					bitWrite(my_buffer[character],2, bitRead(MY_MESSAGE_BUFFER[character],2));
					break;
					
					case 1:
					bitWrite(my_buffer[character],6, bitRead(MY_MESSAGE_BUFFER[character],6));
					bitWrite(my_buffer[character],0, bitRead(MY_MESSAGE_BUFFER[character],0));
					bitWrite(my_buffer[character],3, bitRead(MY_MESSAGE_BUFFER[character],3));
					break;
					
					case 2:
					bitWrite(my_buffer[character],5, bitRead(MY_MESSAGE_BUFFER[character],5));
					bitWrite(my_buffer[character],4, bitRead(MY_MESSAGE_BUFFER[character],4));
					break;
					
					case 3:
					bitWrite(my_buffer[character],7, bitRead(MY_MESSAGE_BUFFER[character],7));
					break;
				}
				Buffer_Print(my_buffer);
				delay(duration);
			}
		}
		delay(wait);
		if(Internal_Refresh){
			RefreshMe();
		}
	}else{
		for(uint8_t index = 0; index<LENGTH_OF_MESSAGE; index++){
			my_buffer[index] = MY_MESSAGE_BUFFER[index];
		}
		
		for(int character = LENGTH_OF_MESSAGE-1; character>=0; character--){
			for(int step = 0; step<4; step++){
				switch(step){
					case 0:
					bitClear(my_buffer[character], 7);
					break;
					
					case 1:
					bitClear(my_buffer[character], 5);
					bitClear(my_buffer[character], 4);
					break;
					
					case 2:
					bitClear(my_buffer[character], 6);
					bitClear(my_buffer[character], 0);
					bitClear(my_buffer[character], 3);
					break;
					
					case 3:
					bitClear(my_buffer[character], 1);
					bitClear(my_buffer[character], 2);
					break;
				}
				Buffer_Print(my_buffer);
				delay(duration);
			}
		}
	}
	
}

void CK_MAX::GiveMe(String message, Animation_Mode A_M, uint16_t duration, uint16_t wait){
	TRANSFER_THIS(message);
	byte D_BUF[LENGTH_OF_MESSAGE];
	for(uint8_t index = 0; index<LENGTH_OF_MESSAGE; index++){
		D_BUF[index] = 0b00000000;
	}
	
	if(A_M == ENTRY){
		uint8_t steps = 1;
		for(uint8_t index = 0; index < LENGTH_OF_MESSAGE; index++){
			D_BUF[index] = 0b01111111;
			Buffer_Print(D_BUF, LENGTH_OF_MESSAGE, digit_pos);
			delay(duration);
			for(uint8_t subIndex = 0 ;subIndex<steps; subIndex++){
				D_BUF[subIndex] = MY_MESSAGE_BUFFER[subIndex];
			}
			steps++;
		}
		Buffer_Print(D_BUF, LENGTH_OF_MESSAGE, digit_pos);
		delay(wait);
		if(Internal_Refresh){
	      RefreshMe();
	    }
	}else{
		for(uint8_t index = 0; index<LENGTH_OF_MESSAGE; index++){
			D_BUF[index] = MY_MESSAGE_BUFFER[index];
		}
		Buffer_Print(D_BUF);
		uint8_t steps = 2;
		for(int index = LENGTH_OF_MESSAGE-1; index >= 0; index--){
			D_BUF[index] = 0b01111111;
			Buffer_Print(D_BUF);
			delay(duration);
			for(int subIndex = LENGTH_OF_MESSAGE-1 ;subIndex>=LENGTH_OF_MESSAGE-steps; subIndex--){
				D_BUF[subIndex] = 0b00000000;
			}
			steps++;
		}
		Buffer_Print(D_BUF, LENGTH_OF_MESSAGE, digit_pos);
	}
}

*/