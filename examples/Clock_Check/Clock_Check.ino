/******
 * .......Clock Test............N.B. : This example is just for testing purpose. Use RTC for real Clock.
 *  Example of "CK_MAX" Version : 1.0
 *  Author : Chandan Kumar Mondal
 *  Date : 28/04/2020
 *  
 *  See the result in, CK_MAX/media/results/Result_of_Clock_Check.bmp
 */

int Second=30, Minute=56, Hour=9;

// First Include the Library
#include <CK_MAX.h>

// Object... Load or CS pin connected to 10
CK_MAX my_clock(10);

// Hold the current time
uint32_t Current_time;

void setup(){
  // take a shortcut
  Serial.begin(9600);
  //my_clock.DefaultSettings();
  my_clock.begin();

  // Assigning the time
  Current_time = millis();

  // Turn Off the Auto Refresh
  my_clock.AutoRefresh(false);


}

void loop(){
  if(Current_time+1000 < millis()){ // Update every 1 second
    // Save the Current time
    Current_time = millis();
    
    // Refresh The Clock
    my_clock.RefreshMe();
    
    // Update time
    Second++;
    if(Second>59){
      Second=0;
      Minute++;
      if(Minute>59){
        Minute = 0;
        Hour++;
        if(Hour > 12){
          Hour = 1;
        }
      }
    }

    // Print Hour 
    my_clock.Set_Position(0);
    my_clock.ShowMe(Hour);

    // Print a Separator
    my_clock.Set_Position(2);
    my_clock.ShowMe("-");
    
    // Print Minute
    my_clock.Set_Position(3);
    my_clock.ShowMe(Minute);

    // Print a Separator
    my_clock.Set_Position(5);
    my_clock.ShowMe("-");

    // Print Second
    my_clock.Set_Position(6);
    my_clock.ShowMe(Second);
  }
}

