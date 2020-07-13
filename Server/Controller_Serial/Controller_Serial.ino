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

String places[] = 
  { "flytoview=<gx:duration> 5 </gx:duration><gx:flyToMode>smooth</gx:flyToMode><LookAt><longitude>-122.478015</longitude><latitude>37.819859</latitude><altitude>100.0</altitude><heading>90</heading><tilt>45</tilt><range>3000</range><gx:altitudeMode>absolute</gx:altitudeMode></LookAt>",
    "flytoview=<gx:duration> 5 </gx:duration><gx:flyToMode>smooth</gx:flyToMode><LookAt><longitude>-122.478015</longitude><latitude>37.819859</latitude><altitude>100.0</altitude><heading>90</heading><tilt>45</tilt><range>3000</range><gx:altitudeMode>absolute</gx:altitudeMode></LookAt>",
    "flytoview=<gx:duration> 5 </gx:duration><gx:flyToMode>smooth</gx:flyToMode><LookAt><longitude>78.042202</longitude><latitude>27.172969</latitude><altitude>100.0</altitude><heading>0</heading><tilt>45</tilt><range>1500</range><gx:altitudeMode>absolute</gx:altitudeMode></LookAt>",
    "flytoview=<gx:duration> 5 </gx:duration><gx:flyToMode>smooth</gx:flyToMode><LookAt><longitude>-43.2110</longitude><latitude>-22.9520</latitude><altitude>100.0</altitude><heading>-45</heading><tilt>45</tilt><range>1000</range><gx:altitudeMode>absolute</gx:altitudeMode></LookAt>",
    "flytoview=<gx:duration> 5 </gx:duration><gx:flyToMode>smooth</gx:flyToMode><LookAt><longitude>-88.567935</longitude><latitude>20.683510</latitude><altitude>100.0</altitude><heading>-180</heading><tilt>45</tilt><range>600</range><gx:altitudeMode>absolute</gx:altitudeMode></LookAt>",
    "flytoview=<gx:duration> 5 </gx:duration><gx:flyToMode>smooth</gx:flyToMode><LookAt><longitude>12.492316</longitude><latitude>41.890240</latitude><altitude>100.0</altitude><heading>10</heading><tilt>45</tilt><range>600</range><gx:altitudeMode>absolute</gx:altitudeMode></LookAt>"
  };

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
     //Serial.println(key);
     Serial.println(places[key]);
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
      //Serial.println(5);
      Serial.println(9); // UP Tilt
      break;

      case 'B':
      //SendMessageSerial(6);
      //Serial.println(6);
      Serial.println(10);// Down Tilt
      break;
      
      case 'R':
      //SendMessageSerial(3);
      //Serial.println(3);
      Serial.println(7); // Cam Right
      break;

      case 'L':
      //SendMessageSerial(4);
      //Serial.println(4);
      Serial.println(8); // Cam Left
      break;

      case 'P':
      //SendMessageSerial(2);
      Serial.println("zOut");
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
    Serial.println("zIn");
   }   

}
