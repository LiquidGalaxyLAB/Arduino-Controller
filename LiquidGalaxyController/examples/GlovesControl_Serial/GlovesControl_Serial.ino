#include <Wire.h>
#include <ADXL345.h>
ADXL345 adxl; //variable adxl is an instance of the ADXL345 library

String Commands[]={"zero","linear","zOut","zIn","right","left","up","down","rightUp","rightDown","leftUp","leftDown",
                   "CamUp","CamDown","CamRight","CamLeft","rollRight","rollLeft","tiltUp","tiltDown"};
String Coordnates[16][3]={
  {"-122.485046","37.820047","3000"},{"78.042202","27.172969","1500"},{"-43.210317","-22.951838","400"},{"-88.567935","20.683510","600"},{"12.492135","41.890079","600"},
  {"-72.545224","-13.163820","600"},{"35.441919","30.328456","600"},{"2.294473","48.857730","1000"},{"-0.124419","51.500769","500"},{"-74.044535","40.689437","500"},
  {"37.623446","55.752362","500"},{"-73.985359","40.748360","500"},{"-51.049260","0.030478","500"},{"31.132695","29.976603","500"},{"0.626502","41.617540","600"},{"116.562771","40.435456","500"}
  };
  
int x,y,z;
int control = 1;
int button = 27;
int tour = 26;
int r = 14;
int g =12;
int b =13;
int xLimitUp = 290;
int xLimitD = -170; 
int yLimitUp = 245; 
int yLimitD = -245;
int tag,tag2,tag3,tagx,tagx2,tagx3,count =0;

void setup()
{
  Serial.begin(9600);

  adxl.powerOn();
  pinMode(button, INPUT);
  pinMode(tour, INPUT);
  pinMode(r, OUTPUT);digitalWrite(r,LOW);
  pinMode(g, OUTPUT);digitalWrite(g,LOW);
  pinMode(b, OUTPUT);digitalWrite(b,LOW);

}

void loop()
{
  if(digitalRead(tour))
  {
    while (digitalRead(tour)){}
    Tour(count);
    count ++;
    if(count == 16) count =0;
  }
  
    adxl.readXYZ(&x, &y, &z); //read the accelerometer values and store them in variables  x,y,z
  
  if (digitalRead(button)) 
  { 
    control ++;
    while (digitalRead(button)){}
    if(control == 4)control =1;
    RGB(control);
  }

switch (control)
 {
  case 1:
  if(x < xLimitD){LGMove(7);tagx =1;}
  else if(x > xLimitUp ) {LGMove(6);tagx =1;}
      else if(tagx == 1) {LGMove(0); tagx = 0;}
  if(y < yLimitD){LGMove(5);tag =1;}
  else if(y > yLimitUp){LGMove(4);tag =1;}
      else if(tag == 1) {LGMove(0); tag = 0;}
  break;
  case 2:
  if(x < xLimitD){LGMove(2);tagx2 = 1;}
  else if(x > xLimitUp) {LGMove(3);tagx2 = 1;}
      else if(tagx2 == 1) {LGMove(0); tagx2 = 0;}
  if(y < yLimitD){LGMove(13);tag2 = 1;}
  else if(y > yLimitUp){LGMove(12);tag2 = 1;}
      else if(tag2 == 1) {LGMove(0); tag2 = 0;}
  break;
  case 3:
  if(x < xLimitD){LGMove(19);tagx3 = 1;}
  else if(x > xLimitUp ) {LGMove(18);tagx3 = 1;}
  else if(tagx3 == 1) {LGMove(0); tagx3 = 0;}
  if(y < yLimitD){LGMove(17);tag3 = 1;}
  else if(y > yLimitUp){LGMove(16);tag3 = 1;}
      else if(tag3 == 1) {LGMove(0); tag3 = 0;}
  break;
  default:
  break;
 }
}// end loop
void LGMove(int Command)
{
 Serial.println(Commands[Command]);
}

void RGB(int cont)
{
  switch (cont)
  {
    case 1:
    digitalWrite(r,!digitalRead(r)); delay(500);
    digitalWrite(r,!digitalRead(r));
    break;
    case 2:
    digitalWrite(g,!digitalRead(g)); delay(500);
    digitalWrite(g,!digitalRead(g));
    break;
    case 3:
    digitalWrite(b,!digitalRead(b)); delay(500);
    digitalWrite(b,!digitalRead(b));
    break;
  }
}

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
void Tour(int place)
{
   Serial.println(MakeKML(Coordnates[place][0],Coordnates[place][1],Coordnates[place][2]));
}
