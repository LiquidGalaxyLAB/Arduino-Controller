#include <LiquidGalaxyController.h>

LG_UltrasonicSetup Ultrasonic(21,19);

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
   int distance = Ultrasonic.UltrasonicMensure();// ULTRASONIC FUNCTION 
   if(distance < 25) { Serial.print("Distance CM: "); Serial.print(map(distance,0,25,0,100)); Serial.println("  %"); }
}
