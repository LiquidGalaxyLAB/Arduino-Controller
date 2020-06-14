

void VoiceSetPinOut(int _pin) // This function is used to set the pin that indicates the results of the recording process
{
    _pinOut = _pin;
    pinMode(_pinOut,OUTPUT);
    digitalWrite(_pinOut,LOW);
}

int VoiceRead() 
{
      if(VR3.available())
    {
      for(int i = 0; i<27;i++)
     {
        _z[i] = VR3.read();
          delay(1); 
     }
      if(_z[2] == 13){Serial.println("Speak Now");PinOut(1);return 0;} 
      if(_z[2] == 15){Serial.println("Speak Again");PinOut(1);return 0;}
      if(_z[2] == 18){Serial.println("Error");PinOut(2);return 0;}
      if(_z[2] == 11){Serial.println("Sucess!");PinOut(3);return 1;}
      if(_z[2] == 10){Serial.println("End Time");PinOut(2);return 0;}
    } 
}

void RecordCommands(int Ncommand) // This function is responsible for sending the recording commands to the voice module
{                                 // Ncommand is a control variable to identify the position of the command that will be recorded
  
   //delay(100);
   for(int _t=0;_t<3;_t++) {VR3.write(Rec[_t]);} // At this point the first command is sent for to start recording
   VR3.write(ComandsNumber[Ncommand]);
   VR3.write(0x0A);
   
   delay(1);
   do                       // This function is responsible for controlling the process of recording a command and prevents the command from being recorded 
   {
    control = VoiceRead();
   }while (control != 1);

   Serial.print("Comando gravado: ");Serial.println(Ncommand);
}

void GetRecognition() // This function sends the necessary commands for the voice module to start the speech recognition process.
{
     if(VR3.available())
    {
      for(int i = 0; i<27;i++)
     {
        _z[i] = VR3.read();
          delay(1); 
     }

    } 
}

void StartRecognition(int _Vgroup)
{
    for(int _k=0;_k<9;_k++)
    {
      VR3.write(groups[_Vgroup][_k]);
    }
}

void PinOut(int Command) // Here is configured the pin responsible for indicate de recording processes, if is ok or error, the user can use the led or buzzer in this pin
{
    if(_pinOut !=0)
  {
    switch(Command)
    {
    case 1:
    digitalWrite(_pinOut,!digitalRead(_pinOut));
    delay(800);
    digitalWrite(_pinOut,!digitalRead(_pinOut));
    break;
    case 2:
    digitalWrite(_pinOut,!digitalRead(_pinOut));
    delay(200);
    digitalWrite(_pinOut,!digitalRead(_pinOut));
    delay(200);
    digitalWrite(_pinOut,!digitalRead(_pinOut));
    delay(200);
    digitalWrite(_pinOut,!digitalRead(_pinOut));
    break;
    case 3:
    digitalWrite(_pinOut,!digitalRead(_pinOut));
    delay(500);
    digitalWrite(_pinOut,!digitalRead(_pinOut));
    delay(500);
    digitalWrite(_pinOut,!digitalRead(_pinOut));
    delay(500);
    digitalWrite(_pinOut,!digitalRead(_pinOut));
    delay(500);
    digitalWrite(_pinOut,!digitalRead(_pinOut));
    delay(500);
    digitalWrite(_pinOut,!digitalRead(_pinOut));
    break;
  }
 }
  
}
