#include <LiquidGalaxyController.h>

//---------------------------------------------------------------------------------------------
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
LG_JoysticSetup joystic(A6,A7,4,JoysticRanges);
LG_UltrasonicSetup Ultrasonic(21,19);

int moviment =0;

void setup() 
{
  Serial.begin(9600);
   
}

void loop() 
{   
   int key = LGKey.KeyPress(); // KEYBOARD FUNCTION
   if(key) 
   {
     Serial.println(key);
   }

   char joy = joystic.JoysticRead();// JOYSTICK FUNCTION
   if(joy)
   {
    moviment =1;
    //Serial.println(joy);
    switch (joy)
    {
      case 'F':
      //SendMessageSerial(5);
      Serial.println(5);
      break;

      case 'B':
      //SendMessageSerial(6);
      Serial.println(6);
      break;
      
      case 'R':
      //SendMessageSerial(3);
      Serial.println(3);
      break;

      case 'L':
      //SendMessageSerial(4);
      Serial.println(4);
      break;

      case 'P':
      //SendMessageSerial(2);
      Serial.println(2);
      break;
    }
   } else  if(moviment==1)
            { //Serial.println("Stop"); 
//              SendMessageSerial(0); 
                Serial.println(0);
              moviment=0;
            }

   int distance = Ultrasonic.UltrasonicMensure();// ULTRASONIC FUNCTION 
   if(distance < 15) 
   { 
    delay(300);
    Serial.println(1);
   }   

}
