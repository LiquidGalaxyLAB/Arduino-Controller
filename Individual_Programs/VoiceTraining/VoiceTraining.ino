#include <SoftwareSerial.h>

SoftwareSerial VR3(22,23);
byte a[27];
char Rec[] = {0xaa,0x03,0x20,0x01,0x0a};
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
  if(digitalRead(15)) // mudar para um valor recebido pela função
  {
    delay(100);
    for(int t=0;t<5;t++){VR3.write(Rec[t]);}
      Serial.println("Voice Record");//Gravar voz
      delay(10);
  }
  
  if(VR3.available())
  {
    for(int i = 0; i<27;i++)
     {
       a[i] = VR3.read();
       delay(1); 
     }
      if(a[2] == 13){Serial.println("Speak Now");buzzer(1);}   //Fale Agora
      if(a[2] == 15){Serial.println("Speak Again");buzzer(1);} //Fale de Novo
      if(a[2] == 18){Serial.println("Error");buzzer(2);}         //Erro
      if(a[2] == 11){Serial.println("Sucess!");buzzer(3);}     //Sucesso!
  } 
}

void RecordVoice()
{
  
}

void StartRecognition()
{
  
}

void buzzer(int B)
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
