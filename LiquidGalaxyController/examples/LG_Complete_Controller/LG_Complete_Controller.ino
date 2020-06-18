#include <LiquidGalaxyController.h>

const byte NumberRows = 4;
const byte NumberColuns = 4;
byte linha[NumberRows] ={13,12,14,27}; 
byte coluna[NumberColuns]={26,25,33,32};
int Keys[NumberRows*NumberColuns] = 
  {1, 2, 3, 4,
   5, 6, 7, 8,
   9,10,11,12,
  13,14,15,16};

LG_Keypad LGKey(Keys,linha,coluna,NumberRows,NumberColuns);
int JoysticRanges[] = {3200,10,3200,100};        // You can check these values just by reading the analog inputs corresponding to the joystic 
                       //B,F,R,P                 //and define the value that you consider best
LG_JoysticSetup joystic(A12,A13,4,JoysticRanges);
LG_UltrasonicSetup Ultrasonic(21,19);

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
   int key = LGKey.KeyPress(); // KEYBOARD FUNCTION
   if(key) Serial.println(key);

   char joy = joystic.JoysticRead();// JOYSTICK FUNCTION
   if(joy) Serial.println(joy);

   int distance = Ultrasonic.UltrasonicMensure();// ULTRASONIC FUNCTION 
   if(distance < 25) { Serial.print("Distance CM: "); Serial.print(map(distance,0,25,0,100)); Serial.println("  %"); }
}
