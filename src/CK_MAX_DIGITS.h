 #ifndef CK_MAX_DIGITS_H
 #define CK_MAX_DIGITS_H
/**
           0  b  0  0  0  0  0  0  0  0  
                dp  A  B  C  D  E  F  G
*/

byte mynumber[129] = {
  0b00000000, // ASCII - 0 - nothing
  0b00000000, // ASCII - 1 - nothing
  0b00000000, // ASCII - 2 - nothing
  0b00000000, // ASCII - 3 - nothing 
  0b00000000, // ASCII - 4 - nothing
  0b00000000, // ASCII - 4 - nothing
  0b00000000, // ASCII - 6 - nothing
  0b00000000, // ASCII - 7 - nothing
  0b00000000, // ASCII - 8 - nothing
  0b00000000, // ASCII - 9 - nothing
  0b00000000, // ASCII - 10 - nothing
  0b00000000, // ASCII - 11 - nothing
  0b00000000, // ASCII - 12 - nothing
  0b00000000, // ASCII - 13 - nothing
  0b00000000, // ASCII - 14 - nothing
  0b00000000, // ASCII - 15 - nothing
  0b00000000, // ASCII - 16 - nothing
  0b00000000, // ASCII - 17 - nothing
  0b00000000, // ASCII - 18 - nothing
  0b00000000, // ASCII - 19 - nothing 
  0b00000000, // ASCII - 20 - nothing
  0b00000000, // ASCII - 21 - nothing
  0b00000000, // ASCII - 22 - nothing
  0b00000000, // ASCII - 23 - nothing
  0b00000000, // ASCII - 24 - nothing
  0b00000000, // ASCII - 25 - nothing
  0b00000000, // ASCII - 26 - nothing
  0b00000000, // ASCII - 27 - nothing
  0b00000000, // ASCII - 28 - nothing
  0b00000000, // ASCII - 29 - nothing
  0b00000000, // ASCII - 30 - nothing
  0b00000000, // ASCII - 31 - nothing
  0b00000000, // ASCII - 32 - nothing
  0b10100000, // ASCII - 33 - !
  0b01100011, // ASCII - 34 - "
  0b00000000, // ASCII - 35 - nothing 
  0b00000000, // ASCII - 36 - nothing
  0b00000000, // ASCII - 37 - nothing
  0b00000000, // ASCII - 38 - nothing
  0b00000000, // ASCII - 39 - nothing
  0b00000000, // ASCII - 40 - nothing
  0b00000000, // ASCII - 41 - nothing
  0b00000000, // ASCII - 42 - nothing
  0b00000000, // ASCII - 43 - nothing
  0b00000001, // ASCII - 45 - -
  0b10000000, // ASCII - 46 - .
  0b00000000, // ASCII - 47 - nothing
  0b01111110, //0
  0b00110000, //1
  0b01101101, //2
  0b01111001, //3
  0b00110011, //4
  0b01011011, //5
  0b01011111, //6
  0b01110000, //7
  0b01111111, //8
  0b01111011, //9
  0b00000000, // ASCII - 58 - nothing
  0b00000000, // ASCII - 59 - nothing
  0b00000000, // ASCII - 60 - nothing
  0b00000000, // ASCII - 61 - nothing
  0b00000000, // ASCII - 62 - nothing
  0b00000000, // ASCII - 63 - nothing
  0b00000000, // ASCII - 64 - nothing
  0b01110111, // ASCII - 65 - A
  0b00011111, // ASCII - 66 - b
  0b01001110, // ASCII - 67 - C
  0b00111101, // ASCII - 68 - d 
  0b01001111, // ASCII - 69 - E
  0b01000111, // ASCII - 70 - F
  0b01011110, // ASCII - 71 - G
  0b00110111, // ASCII - 72 - H
  0b00000110, // ASCII - 73 - I
  0b00111000, // ASCII - 74 - J
  0b00110111, // ASCII - 75 - K
  0b00001110, // ASCII - 76 - L
  0b01001111, // ASCII - 77 - M
  0b00010101, // ASCII - 78 - n
  0b01111110, // ASCII - 79 - O
  0b01100111, // ASCII - 80 - P
  0b01110011, // ASCII - 81 - Q
  0b00000101, // ASCII - 82 - r
  0b01011011, // ASCII - 83 - S
  0b01000110, // ASCII - 84 - T 
  0b00111110, // ASCII - 85 - U
  0b00111110, // ASCII - 86 - V
  0b01111001, // ASCII - 87 - W
  0b00110111, // ASCII - 88 - X
  0b00111011, // ASCII - 89 - Y
  0b01001001, // ASCII - 90 - Z
  0b00000000, // ASCII - 91 - nothing
  0b00000000, // ASCII - 92 - nothing
  0b00000000, // ASCII - 93 - nothing
  0b00000000, // ASCII - 94 - nothing
  0b00000000, // ASCII - 95 - nothing
  0b00000000, // ASCII - 96 - nothing
  0b01110111, // ASCII - 97 - A
  0b00011111, // ASCII - 98 - b
  0b00001101, // ASCII - 99 - c
  0b00111101, // ASCII - 100 - d 
  0b01001111, // ASCII - 101 - E
  0b01000111, // ASCII - 102 - F
  0b01110011, // ASCII - 103 - g
  0b00010111, // ASCII - 104 - h
  0b00010000, // ASCII - 105 - I
  0b00111000, // ASCII - 106 - J
  0b00110111, // ASCII - 107 - K
  0b00000110, // ASCII - 108 - l
  0b01001111, // ASCII - 109 - m
  0b00010101, // ASCII - 110 - n
  0b00011101, // ASCII - 111 - o
  0b01100111, // ASCII - 112 - p
  0b01110011, // ASCII - 113 - q
  0b00000101, // ASCII - 114 - r 
  0b01011011, // ASCII - 115 - s
  0b00001111, // ASCII - 116 - t
  0b00011100, // ASCII - 117 - u
  0b00011100, // ASCII - 118 - v
  0b01111001, // ASCII - 119 - w
  0b00110111, // ASCII - 120 - X
  0b00111011, // ASCII - 121 - Y
  0b01001001, // ASCII - 122 - Z
  0b00000000, // ASCII - 123 - nothing
  0b00000000, // ASCII - 124 - nothing
  0b00000000, // ASCII - 125 - nothing
  0b00000000, // ASCII - 126 - nothing
  0b00000000, // ASCII - 127 - nothing
  0b00000000, // ASCII - 128 - nothing    
};


#endif
