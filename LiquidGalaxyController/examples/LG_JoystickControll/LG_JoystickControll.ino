#include <LiquidGalaxyController.h>

int JoysticRanges[] = {3200,10,3200,100};        // You can check these values just by reading the analog inputs corresponding to the joystic 
                       //B,F,R,P                 //and define the value that you consider best
LG_JoysticSetup joystic(A12,A13,4,JoysticRanges); //Insert the pins corresponding to: (Analog Y Axis, Analog X Axis, Push pin, Value_Range)
                                                  //The range is used to identify from which analog reading variation value the commands will be recognized
void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
   char joy = joystic.JoysticRead();// JOYSTICK FUNCTION
   if(joy) Serial.println(joy);
}
