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

String Commands[]={"zero","linear","zOut","zIn","right","left","up","down","rightUp","rightDown","leftUp","leftDown",
                   "CamUp","CamDown","CamRight","CamLeft","rollRight","rollLeft","tiltUp","tiltDown"};

String Coordnates[16][3]={
  {"-122.485046","37.820047","3000"},
  {"78.042202","27.172969","1500"},
  {"-43.210317","-22.951838","400"},
  {"-88.567935","20.683510","600"},
  {"12.492135","41.890079","600"},
 };
int moviment =0;

void setup() 
{
  Serial.begin(9600);
   
}

void loop() 
{   
  if(digitalRead(5))Tour(15);
   int key = LGKey.KeyPress(); // KEYBOARD FUNCTION
   if(key) 
   {
     Serial.println(MakeKML(Coordnates[key-1][0],Coordnates[key-1][1],Coordnates[key-1][2]));
   }

   char joy = joystic.JoysticRead();// JOYSTICK FUNCTION
   if(joy)
   {
    //delay(10);
    moviment =1;
    JoysticAnalyser(3,joy);
   } else  if(moviment==1)
            { LGMove(0);
              //Serial.println(0);
              moviment=0;
            }

   //int distance = Ultrasonic.UltrasonicMensure();// ULTRASONIC FUNCTION 
   //if(distance < 15) 
   //{ 
    //delay(300);
   // LGMove(3);
    //Serial.println("zIn");
  // }   

}

//-------------------------------------------------------------------------------------------------------
void LGMove(int Command)
{
 Serial.println(Commands[Command]);
}
//-------------------------------------------------------------------------------------------------------

String MakeKML(String longitude, String latitude, String range)
{
  /*String kml = "flytoview=<gx:duration>5</gx:duration><gx:flyToMode>smooth</gx:flyToMode><LookAt><longitude>";
  kml += longitude;
  kml += "</longitude><latitude>";
  kml +=latitude ;
  kml += "</latitude><altitude>700";
  //kml +=altitude ;
  kml += "</altitude><heading>90</heading><tilt>45</tilt><range>";
  kml += range;
  kml += "</range><gx:altitudeMode>absolute</gx:altitudeMode></LookAt>";*/

  String kml ="flytoview=<LookAt><longitude>";
  kml += longitude;
  kml += "</longitude><latitude>";
  kml +=latitude ;
  kml += "</latitude><range>";
  kml += range;
  kml += "</range></LookAt>";
  
  return kml;
  
}
//-------------------------------------------------------------------------------------------------------
void JoysticAnalyser(int State, char Position)
{
  if(State == 1) // Simple Moviments
  {switch (Position)
    {
      case 'F':
      LGMove(6);
      break;
      case 'B':
      LGMove(7);
      break;
      case 'R':
      LGMove(4);
      break;
      case 'L':
      LGMove(5);
      break;
      case 'P':
      LGMove(2);
      break;
    }// end switch
  }// end Simple Moviments
  if(State == 2) // Camera Moviments
  {switch (Position)
    {
      case 'F':
      LGMove(12);
      break;
      case 'B':
      LGMove(13);
      break;
      case 'R':
      LGMove(14);
      break;
      case 'L':
      LGMove(15);
      break;
      case 'P':
      LGMove(2);
      break;
    }// end switch
  }// end Cam Moviments
  if(State == 3) // Tlt and Roll
  {switch (Position)
    {
      case 'F':
      LGMove(18);
      break;
      case 'B':
      LGMove(19);
      break;
      case 'R':
      LGMove(16);
      break;
      case 'L':
      LGMove(17);
      break;
      case 'P':
      LGMove(2);
      break;
    }// end switch
  }// end Tlt and Roll
}
//-------------------------------------------------------------------------------------------------------
void Tour(int Time)
{
  for(int tour;tour<16;tour++)
  {
    Serial.println(MakeKML(Coordnates[tour][0],Coordnates[tour][1],Coordnates[tour][2]));
    delay(Time*1000);
  }
}
