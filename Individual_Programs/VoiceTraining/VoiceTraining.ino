#include <SoftwareSerial.h>

SoftwareSerial VR3(22,23);
byte a[27];
char Rec[] = {0xaa,0x03,0x20,0x01,0x0a};// Comand test
int gorups[] = {0,1,2,3,4}; // Array with groups index 
byte groups[5] [8]={
{0xAA,0x06,0x30,0x01,0x02,0x03,0x04,0x0A}, // PLace Groups
{0xAA,0x06,0x30,0x05,0x06,0x07,0x08,0x0A}, // First Group
{0xAA,0x06,0x30,0x09,0x0A,0x0B,0x0C,0x0A}, // Second Group
{0xAA,0x06,0x30,0x0D,0x0E,0x0F,0x10,0x0A}, // Third Group
{0xAA,0x06,0x30,0x11,0x12,0x13,0x14,0x0A}
}; 

int buz = 21;

void setup() 
{
  Serial.begin(9600);
  VR3.begin(9600);
  pinMode(buz,OUTPUT);
  digitalWrite(buz,LOW);
}

void loop() 
{
  if(digitalRead(15))
  {
    RecordComands();
  }
   VoiceRead();
   
}

//--------------------------------------------------------------------------------------------------------------

char VoiceRead()
{
    if(VR3.available())
  {
    for(int i = 0; i<27;i++)
     {
       a[i] = VR3.read();
      // Serial.print(a[i],HEX);
      // Serial.print("-");
       delay(1); 
     }
     //Serial.println("");
      if(a[2] == 13){Serial.println("Speak Now");Buzzer(1);}   //Fale Agora
      if(a[2] == 15){Serial.println("Speak Again");Buzzer(1);} //Fale de Novo
      if(a[2] == 18){Serial.println("Error");Buzzer(2);}         //Erro
      if(a[2] == 11){Serial.println("Sucess!");Buzzer(3);}     //Sucesso!
      if(a[2] == 10){Serial.println("End Time");Buzzer(2);}   
  } 
}

void RecordComands()
{
   delay(100);
   for(int t=0;t<5;t++){VR3.write(Rec[t]);}
   Serial.println("Voice Record");//Gravar voz
   delay(10);
}

void StartRecognition(byte Group)
{
  for(int k=0;k<8;k++)
  {
    VR3.write(groups[Group][k]);
  }
}

void Buzzer(int B)
{
  
  switch(B)
  {
    case 1:
    digitalWrite(buz,!digitalRead(buz));
    delay(800);
    digitalWrite(buz,!digitalRead(buz));
    break;
    case 2:
    digitalWrite(buz,!digitalRead(buz));
    delay(200);
    digitalWrite(buz,!digitalRead(buz));
    delay(200);
    digitalWrite(buz,!digitalRead(buz));
    delay(200);
    digitalWrite(buz,!digitalRead(buz));
    break;
    case 3:
    digitalWrite(buz,!digitalRead(buz));
    delay(500);
    digitalWrite(buz,!digitalRead(buz));
    delay(500);
    digitalWrite(buz,!digitalRead(buz));
    delay(500);
    digitalWrite(buz,!digitalRead(buz));
    delay(500);
    digitalWrite(buz,!digitalRead(buz));
    delay(500);
    digitalWrite(buz,!digitalRead(buz));
    break;
  }
}
