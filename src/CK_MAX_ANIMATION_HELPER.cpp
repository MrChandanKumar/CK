/**
   DOUBLE SIDE ANIMATION SUCCESSFULLY CHECKED FOR, 
   - MAKE
   - BREAK
   - SCROLL_UP
   - SCROLL_DOWN
   - SCAN_TOP
   - SCAN_BOTTOM
   - SCROLL_LEFT
   - SCROLL_RIGHT
   - WAVE
   - MAKE_BUFFER
   - RAND_UP
   - RAND_DOWN
   - SCROLL_UP_SINGLE
   - SCROLL_DOWN_SINGLE
   - SCROLL_UP_RANDOM
   - SCROLL_DOWN_RANDOM
*/

#include <CK_MAX.h>


void CK_MAX::AnimateMe(String message, All_Animations Animation, uint16_t duration, uint16_t wait){
	switch(Animation){
		case SCROLL_LEFT:
		ScrollMe(message, RIGHT_TO_LEFT, duration);
		break;
		
		case SCROLL_RIGHT:
		ScrollMe(message, LEFT_TO_RIGHT, duration);
		break;
		
		case SCROLL_UP:
		FlowMe(message, GO_UP,ENTRY, duration, wait);
		break;
		
		case SCROLL_DOWN:
		FlowMe(message, GO_DOWN,ENTRY, duration, wait);
		break;
		
		case MAKE_BUFFER:
		GrowMe(message, BUFFERING,ENTRY, duration, wait);
		break;
		
		case SLICE_OWN:
		SliceMe(message, OWN_SLICE,ENTRY, duration, wait);
		break;
		
		case SLICE_ALL:
		SliceMe(message, ALL_SLICE,ENTRY, duration, wait);
		break;
		
		case SCAN_TOP:
		ScanMe(message, TOP,ENTRY, duration, wait);
		break;
		
		case SCAN_BOTTOM:
		ScanMe(message, BOTTOM,ENTRY, duration, wait);
		break;
		
		case RAND_UP:
		GrowMe(message, UP, ENTRY, duration, wait);
		break;
		
		case RAND_DOWN:
		GrowMe(message, DOWN,ENTRY, duration, wait);
		break;
		
		case WAVE:
		WaveMe(message, duration, wait);
		break;
		
		case MAKE:
		BuildMe(message,MAKING,ENTRY, duration, wait);
		break;	
		
		case BREAK:
		BuildMe(message, BREAKING,ENTRY, duration, wait);
		break;
		
		case SCROLL_UP_SINGLE:
		ScrollMeNew(message, S_U_S, ENTRY, duration, wait);
		break;
		
		case SCROLL_DOWN_SINGLE:
		ScrollMeNew(message, S_D_S, ENTRY, duration, wait);
		break;
		
		case SCROLL_UP_RANDOM:
		ScrollMeRand(message, S_U_R, ENTRY, duration, wait);
		break;
		
		case SCROLL_DOWN_RANDOM:
		ScrollMeRand(message, S_D_R, ENTRY, duration, wait);
		break;
		
		case GROW_UP:
		GROWME( message, GROW_UP, ENTRY, duration, wait);
		break;
		
		case GROW_DOWN:
		GROWME( message, GROW_DOWN, ENTRY, duration, wait);
		break;

		case RANDOMIZED:
		RandomizeMe(message, duration, wait);
		break;
		/*
		case SCAN_X:
		SortMe(message, ENTRY, duration, wait);
		break;
		
		case SCAN_XX:
		GiveMe(message, ENTRY, duration, wait);
		break;
		*/
	}
}

void CK_MAX:: AnimateMe(String message, All_Animations Animation, uint16_t wait){
	switch(Animation){
		case SCROLL_LEFT:
		ScrollMe(message, RIGHT_TO_LEFT, wait);
		break;
		
		case SCROLL_RIGHT:
		ScrollMe(message, LEFT_TO_RIGHT, wait);
		break;
	}
}

void CK_MAX::AnimateMe(String message, All_Animations Animation, uint8_t number,uint16_t duration, uint16_t wait){
	if(Animation == MAKE_BUFFER){
		SPIN_COUNTER = number;
		GrowMe(message, BUFFERING,ENTRY, duration, wait);
	}
}

void CK_MAX::AnimateMe(String message, All_Animations Entry, All_Animations Exit, uint16_t ENduration, uint16_t EXduration, uint16_t wait){
	// SWITCH THE ENTRY ANIMATION ....
	switch(Entry){
		case MAKE:
		BuildMe(message, MAKING, ENTRY, ENduration, wait);
		break;

		case BREAK:
		BuildMe(message, BREAKING, ENTRY, ENduration, wait);
		break;

		case SCROLL_UP:
		FlowMe(message, GO_UP, ENTRY, ENduration, wait);
		break;

		case SCROLL_DOWN:
		FlowMe(message, GO_DOWN, ENTRY, ENduration, wait);
		break;

		case SCAN_TOP:
		ScanMe(message, TOP, ENTRY, ENduration, wait);
		break;

		case SCAN_BOTTOM:
		ScanMe(message, BOTTOM, ENTRY, ENduration, wait);
		break;

		case SCROLL_LEFT:
		ScrollMe(message, RIGHT_TO_LEFT, ENduration);
		delay(wait);
		break;

		case SCROLL_RIGHT:
		ScrollMe(message, LEFT_TO_RIGHT, ENduration);
		delay(wait);
		break;

		case WAVE:
		WaveMe(message, ENduration, wait);
		break;

		case RAND_UP:
		GrowMe(message, UP, ENTRY, ENduration, wait);
		break;

		case RAND_DOWN:
		GrowMe(message, DOWN, ENTRY, ENduration, wait);
		break;

		case MAKE_BUFFER:
		GrowMe(message, BUFFERING, ENTRY, ENduration, wait);
		break;

		case SLICE_OWN:
		SliceMe(message, OWN_SLICE, ENTRY, ENduration, wait);
		break;

		case SLICE_ALL:
		SliceMe(message, ALL_SLICE, ENTRY, ENduration, wait);
		break;
		
		case SCROLL_UP_SINGLE:
		ScrollMeNew(message, S_U_S, ENTRY, ENduration, wait);
		break;
		
		case SCROLL_DOWN_SINGLE:
		ScrollMeNew(message, S_D_S, ENTRY, ENduration, wait);
		break;
		
		case SCROLL_UP_RANDOM:
		ScrollMeRand(message, S_U_R, ENTRY, ENduration, wait);
		break;
		
		case SCROLL_DOWN_RANDOM:
		ScrollMeRand(message, S_D_R, ENTRY, ENduration, wait);
		break;
		
		case GROW_UP:
		GROWME(message, GROW_UP, ENTRY, ENduration, wait);
		break;
		
		case GROW_DOWN:
		GROWME(message, GROW_DOWN, ENTRY, ENduration, wait);
		break;

		case RANDOMIZED:
		RandomizeMe(message, ENduration, wait);
		break;
		/*
		case SCAN_X:
		SortMe(message, ENTRY, ENduration, wait);
		break;
		
		case SCAN_XX:
		GiveMe(message, ENTRY, ENduration, wait);
		break;
        */
		default:
		break;
	}

	// SWITCH THE EXIT ANIMATION ....
	switch(Exit){
		case MAKE:
		BuildMe(message, MAKING, EXIT, EXduration, wait);
		break;

		case BREAK:
		BuildMe(message, BREAKING, EXIT, EXduration, wait);
		break;

		case SCROLL_UP:
		FlowMe(message, GO_UP, EXIT, EXduration, wait);
		break;

		case SCROLL_DOWN:
		FlowMe(message, GO_DOWN, EXIT, EXduration, wait);
		break;

		case SCAN_TOP:
		ScanMe(message, TOP, EXIT, EXduration, wait);
		break;

		case SCAN_BOTTOM:
		ScanMe(message, BOTTOM, EXIT, EXduration, wait);
		break;

		case SCROLL_LEFT:
		ScrollMe(message, RIGHT_TO_LEFT, EXduration);
		break;

		case SCROLL_RIGHT:
		ScrollMe(message, LEFT_TO_RIGHT, EXduration);
		break;

		case WAVE:
		WaveMe(message, EXduration, wait);
		break;

		case RAND_UP:
		GrowMe(message, UP, EXIT, EXduration, wait);
		break;

		case RAND_DOWN:
		GrowMe(message, DOWN, EXIT, EXduration, wait);
		break;

		case MAKE_BUFFER:
		GrowMe(message, BUFFERING, EXIT, EXduration, wait);
		break;

		case SLICE_OWN:
		SliceMe(message, OWN_SLICE, EXIT, EXduration, wait);
		break;

		case SLICE_ALL:
		SliceMe(message, ALL_SLICE, EXIT, EXduration, wait);
		break;
		
		case SCROLL_UP_SINGLE:
		ScrollMeNew(message, S_U_S, EXIT, EXduration, wait);
		break;
		
		case SCROLL_DOWN_SINGLE:
		ScrollMeNew(message, S_D_S, EXIT, EXduration, wait);
		break;
		
		case RANDOMIZED:
		case SCROLL_UP_RANDOM:
		ScrollMeRand(message, S_U_R, EXIT, EXduration, wait);
		break;
		
		case SCROLL_DOWN_RANDOM:
		ScrollMeRand(message, S_D_R, EXIT, EXduration, wait);
		break;
		
		case GROW_UP:
		GROWME(message, GROW_UP, EXIT, EXduration, wait);
		break;
		
		case GROW_DOWN:
		GROWME(message, GROW_DOWN, EXIT, EXduration, wait);
		break;
	/*	
		case SCAN_X:
		SortMe(message, EXIT, EXduration, wait);
		break;
		
		case SCAN_XX:
		GiveMe(message, EXIT, EXduration, wait);
		break;
	*/
	}
	
	RefreshMe();
}

void CK_MAX::TRANSFER_THIS(String message){
		/// MEASURE THE LENGTH OF THE STRING
	uint8_t Len = message.length();
	
	/// TOTAL DISPLAY DIGIT
	uint8_t size_of_display = Number_of_Device * DIGIT_NUMBER;
	
	/// IF THE STRING WILL BE EXCESSED THE DISPLAY SIZE THEN CUT IT FIRST
	if(Len > size_of_display){
		message.substring(0, size_of_display);
	}
	
	
	LENGTH_OF_MESSAGE = message.length();
	
	/// CHECK THE DECIMAL POINT...
	uint8_t INDEX_OF_DECIMAL_POINT = 0;
	for(uint8_t index = 0; index<LENGTH_OF_MESSAGE;index++){
		if(message.charAt(index)=='.'){
			INDEX_OF_DECIMAL_POINT = index;
		}
	}
	
	/// IF WE FOUND THE DECIMAL POINT, REMOVE THIS FROM MESSAGE
	uint8_t CARE_ABOUT_POSITION = 0;
	if(INDEX_OF_DECIMAL_POINT > 0){
		CARE_ABOUT_POSITION = INDEX_OF_DECIMAL_POINT - 1;
		message.replace(".", "");
		LENGTH_OF_MESSAGE = message.length();
	}
	
	/// INITIALIZING THE MESSAGE BUFFER AND SAVE THE CORRESPONDING BYTE
	for(uint8_t index = 0; index<LENGTH_OF_MESSAGE ;index++){
		MY_MESSAGE_BUFFER[index] = 0b00000000;
		MY_MESSAGE_BUFFER[index] = give_me_byte(uint8_t(message.charAt(index)));
		if(index==CARE_ABOUT_POSITION && INDEX_OF_DECIMAL_POINT!=0){
			MY_MESSAGE_BUFFER[index] |= 0b10000000;
		}
	}
}
	