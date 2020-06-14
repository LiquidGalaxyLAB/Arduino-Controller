#include <SoftwareSerial.h>

SoftwareSerial VR3(22,23);
  int _VoiceControlN = 1;
  int verificator = 0;

void setup() 
{
  Serial.begin(9600);
  VR3.begin(9600);
  
  VoiceSetPinOut(18);
}

void loop() 
{
    if(verificator = 0){StartRecognition(0); verificator =1;}
  
  if(digitalRead(5))
  {
    Serial.print("Regording: ");
    Serial.println(_VoiceControlN );
    RecordCommands(_VoiceControlN);// RECORD COMMANDS, receive the record index 
    _VoiceControlN ++;
    if(_VoiceControlN == 22){_VoiceControlN = 1;}
  }

}
