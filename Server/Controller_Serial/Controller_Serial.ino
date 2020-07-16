#include <LiquidGalaxyController.h>
#include <SoftwareSerial.h>
SoftwareSerial VR3(22,23);
//-------------------------------------------------- Voice Commands
byte a[27];
int rec =17;
int _pinOut = 18;
int received;
byte headVoice[4]={0xAA,0x02,0x31,0x0A};
byte groups[4] [11]={
      {0xAA,0x09,0x30,0x01,0x02,0x03,0x04,0x12,0x13,0x14,0x0A}, // First Group
      {0xAA,0x09,0x30,0x05,0x06,0x07,0x08,0x11,0x13,0x14,0x0A}, // Second Group 
      {0xAA,0x09,0x30,0x09,0x0A,0x0B,0x0C,0x11,0x12,0x14,0x0A},  
      {0xAA,0x09,0x30,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x0A}};
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
LG_JoysticSetup joystic(A6,A7,4,JoysticRanges);  //B,F,R,P and define the value that you consider best
LG_UltrasonicSetup Ultrasonic(21,19);

String Commands[]={"zero","linear","zOut","zIn","right","left","up","down","rightUp","rightDown","leftUp","leftDown",
                   "CamUp","CamDown","CamRight","CamLeft","rollRight","rollLeft","tiltUp","tiltDown"};

String Coordnates[16][3]={
  {"-122.485046","37.820047","3000"},{"78.042202","27.172969","1500"},{"-43.210317","-22.951838","400"},{"-88.567935","20.683510","600"},{"12.492135","41.890079","600"},
  {"-72.545224","-13.163820","600"},{"35.441919","30.328456","600"},{"2.294473","48.857730","1000"},{"-0.124419","51.500769","500"},{"-74.044535","40.689437","500"},
  {"37.623446","55.752362","500"},{"-73.985359","40.748360","500"},{"-51.049260","0.030478","500"},{"31.132695","29.976603","500"},{"0.626502","41.617540","600"},{"116.562771","40.435456","500"}
  };
int moviment, moviment2 =0;

void setup() 
{
  Serial.begin(9600);
  VR3.begin(9600);
  pinMode(_pinOut,OUTPUT); 
  digitalWrite(_pinOut,LOW);
  delay(1000);
  for(int h =0; h<11;h++)VR3.write(groups[0] [h]);
  delay(100);
 for(int i = 0; i<11;i++)
 {
  a[i] = VR3.read();
  Serial.print( a[i],HEX);
  Serial.print("-");
  delay(1); 
 }
 Serial.println("");
delay(100);
      VR3.write(0xaa);
      VR3.write(0x0D);
      VR3.write(0x0a);
}

void loop() 
{   
  //if(digitalRead(5))Tour(15);
    if(digitalRead(5))
    { while(digitalRead(5) == HIGH){} 
      grupos(rec);
      rec ++;
      if(rec == 21)rec =17;
    }
    
    received = GetRec();
    if (received <17 && received>0)
    {
      Serial.println(received);
      Serial.println(MakeKML(Coordnates[received-1][0],Coordnates[received-1][1],Coordnates[received-1][2])); 
    }
  //--------------------------------------------------
   int key = LGKey.KeyPress(); // KEYBOARD FUNCTION
   if(key){Serial.println(MakeKML(Coordnates[key-1][0],Coordnates[key-1][1],Coordnates[key-1][2]));}

   char joy = joystic.JoysticRead();// JOYSTICK FUNCTION
   if(joy)
   {
    moviment =1;
    JoysticAnalyser(3,joy);
   } else  if(moviment==1)
            { 
              LGMove(0);
              moviment=0;
            }

   int distance = Ultrasonic.UltrasonicMensure();// ULTRASONIC FUNCTION 
   if(distance < 15) 
   { 
    moviment2 =1;
    LGMove(3);
   } else  if(moviment2==1)
            { 
              LGMove(0);
              moviment2=0;
            }   
}

//-------------------------------------------------------------------------------------------------------
void LGMove(int Command)
{
 Serial.println(Commands[Command]);
}
//-------------------------------------------------------------------------------------------------------

String MakeKML(String longitude, String latitude, String range)
{
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
String MakeCompleteKML(String longitude, String latitude,String altitude, String range)
{
  String kml = "flytoview=<gx:duration>5</gx:duration><gx:flyToMode>smooth</gx:flyToMode><LookAt><longitude>";
  kml += longitude;
  kml += "</longitude><latitude>";
  kml +=latitude ;
  kml += "</latitude><altitude>700";
  kml +=altitude ;
  kml += "</altitude><heading>90</heading><tilt>45</tilt><range>";
  kml += range;
  kml += "</range><gx:altitudeMode>absolute</gx:altitudeMode></LookAt>";
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
//-------------------------------------------------------------------------------------------------------
int GetRec()
{
    if(VR3.available())
   {
      for(int i = 0; i<27;i++)
     {
      a[i] = VR3.read();
      delay(1); 
     }
   return a[5];
  }
  return 0;
}
void grupos(int rec)
{
  int h,t;
  delay(500);
  switch (rec)
  {
    case 17:// First Group
    //Serial.println("Grupo 1");
    digitalWrite(_pinOut,!digitalRead(_pinOut)); delay(500);
    digitalWrite(_pinOut,!digitalRead(_pinOut));
    for(t =0; t<4;t++)VR3.write(headVoice[t]);
    delay(500);
    for(h =0; h<11;h++)VR3.write(groups[0] [h]);
    break;
    case 18:// First Group
    //Serial.println("Grupo 2");
    for(int p =0;p<4;p++){digitalWrite(_pinOut,!digitalRead(_pinOut)); delay(500);}
    for(t =0; t<4;t++)VR3.write(headVoice[t]);
    delay(500);
    for(h =0; h<11;h++)VR3.write(groups[1] [h]);
    break;
    case 19:// First Group
    //Serial.println("Grupo 3");
    for(int p =0;p<6;p++){digitalWrite(_pinOut,!digitalRead(_pinOut)); delay(500);}
    for(t =0; t<4;t++)VR3.write(headVoice[t]);
    delay(500);
    for(h =0; h<11;h++)VR3.write(groups[2] [h]);
    break;
    case 20:// First Group
    //Serial.println("Grupo 4");
    for(int p =0;p<8;p++){digitalWrite(_pinOut,!digitalRead(_pinOut)); delay(500);}
    for(t =0; t<4;t++)VR3.write(headVoice[t]);
    delay(500);
    for(h =0; h<11;h++)VR3.write(groups[3] [h]);
    break;
    default:
    break;
  } 
}
