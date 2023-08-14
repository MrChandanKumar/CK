/**
##########POSITION#############
 
 - N MODULES
 - POSITION 1 TO 16
 - SAME FOR RIGHT TO LEFT AND LEFT TO RIGHT DIRECTION
 
 
             1                                  2                                N          - MODULE NUMBER
			 
   0   1   2   3   4   5   6   7      8   9  10  11  12  13  14  15       (8*N-2)(8*N-1)    - POSITION
 +-------------------------------+  +-------------------------------+         --------+
 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |  | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |  .....  | 6 | 7 |     - LEFT TO RIGHT
 +-------------------------------+  +-------------------------------+         --------+
 
 +-------------------------------+  +-------------------------------+         --------+
 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |  | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |  .....  | 1 | 0 |     - RIGHT TO LEFT
 +-------------------------------+  +-------------------------------+         --------+


*/

#ifndef DEBUG_H
#define DEBUG_H

#define SPrintNL(x) {Serial.println(x);}
#define SPrint(x)   {Serial.print(x);}
#define FULL_SIZE_DISP (Number_of_Devices*DIGIT_NUMBER)
#define SPrintB(x) {Serial.print(x, BIN);}


#endif