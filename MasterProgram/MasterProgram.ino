#include <SoftwareSerial.h>
SoftwareSerial VR3(22,23); // VOICE RECOGNITION CONFIGURATIONS

//----------------------------------------------------------------------VARIABLES
    int _piny,_pinx,_pinPush;
    int _trig, _echo;
    byte _rows, _coluns;
    byte *_rowsPin;
    byte *_colunsPin;
    int _rx, _tx; 
    int *_keys;
    int _a = 0;
    int _b = 0;
    byte _z[27]; // antigo a
    int _pinOut; // Voice record indicator
    int _Command;

    byte a[27];
    char Rec[] = {0xaa,0x03,0x20};// Comand test
    int gorups[] = {0,1,2,3,4}; // Array with groups index
    byte ComandsNumber[] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14};
    byte groups[5] [8]={
      {0xAA,0x06,0x30,0x01,0x02,0x03,0x04,0x0A}, // PLace Groups this command is used to recognize the voice commands of the first group
      {0xAA,0x06,0x30,0x05,0x06,0x07,0x08,0x0A}, // First Group
      {0xAA,0x06,0x30,0x09,0x0A,0x0B,0x0C,0x0A}, // Second Group
      {0xAA,0x06,0x30,0x0D,0x0E,0x0F,0x10,0x0A}, // Third Group
      {0xAA,0x06,0x30,0x11,0x12,0x13,0x14,0x0A} }; 

//---------------------------------------------------------------------- KEYBOARD CONFIGURATIONS
const byte NumberRows = 4;
const byte NumberColuns = 4;
byte linha[NumberRows] ={13,12,14,27}; 
byte coluna[NumberColuns]={26,25,33,32};
int Keys[NumberRows*NumberColuns] = 
  {1, 2, 3, 4,
   5, 6, 7, 8,
   9,10,11,12,
  13,14,15,16};

  int _VoiceControlN = 1;
//----------------------------------------------------------------------SETUP CONFIGURATION
void setup() 
{
  Serial.begin(9600);

  VR3.begin(9600);
  VoiceSetPinOut(18);
  JoysticSetup(A12,A13,4);
  UltrasonicSetup(21,19);
  KeypadSetup(Keys,linha,coluna,NumberRows,NumberColuns);
}

void loop() 
{
  if(digitalRead(5))
  {
    Serial.print("Regording: ");
    Serial.println(_VoiceControlN );
    RecordCommands(_VoiceControlN);// RECORD COMMANDS
    _VoiceControlN ++;
    if(_VoiceControlN == 22){_VoiceControlN = 1;}
  }
   VoiceRead(); // READ VOICE MODULE COMMANDS
   
   char joy = joysticRead();// JOYSTICK FUNCTION
   if(joy) Serial.println(joy);
   
   int distance = UltrasonicMensure();// ULTRASONIC FUNCTION 
   if(distance < 25) { Serial.print("Distance CM: "); Serial.print(map(distance,0,25,0,100)); Serial.println("  %"); } 
       
   int key = KeyPress(); // KEYBOARD FUNCTION
   if(key) Serial.println(key);
}

//------------------------------------------------------------------------------- VOICE RECOGNITION COMMANDS AND FUNCTIONS
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
     //Serial.println("");
      if(_z[2] == 13){Serial.println("Speak Now");PinOut(1);return 0;}  
      if(_z[2] == 15){Serial.println("Speak Again");PinOut(1);return 0;} 
      if(_z[2] == 18){Serial.println("Error");PinOut(2);return 0;}        
      if(_z[2] == 11){Serial.println("Sucess!");PinOut(3);return 1;}    
      if(_z[2] == 10){Serial.println("End Time");PinOut(2);return 0;}   
    } 
}

void RecordCommands(int Ncommand) // This function is responsible for sending the recording commands to the voice module
{                                 // Ncommand is a control variable to identify the position of the command that will be recorded
   int control;
   delay(100);
   for(int _t=0;_t<3;_t++) {VR3.write(Rec[_t]);} // At this point the first command is sent for to start recording
   VR3.write(ComandsNumber[Ncommand]);
   VR3.write(0x0A);
   delay(10);
   do                       // This function is responsible for controlling the process of recording a command and prevents the command from being recorded 
   {
    control = VoiceRead();
   }while (control != 1);
}

void StartRecognition(int group)// This function sends the necessary commands for the voice module to start the speech recognition process.
{
  for(int k=0;k<8;k++)
  {
    VR3.write(groups[group][k]);
  }
}

void PinOut(int Command)
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

//------------------------------------------------------------------------------- JOYSTIC FUNCTIONS

int JoysticRanges[] = {3200,100,3200,600};  // Joystic modules can have different operating characteristics
                                            //here actuation limits are inserted for better definition of the joystick's direction of movement

void JoysticSetup(int piny, int pinx, int button)  // Here the pins are configurade 
{
  _piny = piny;
  _pinx = pinx;
  _pinPush = button;
  pinMode(_pinPush,INPUT);
}

char joysticRead() // This function is respnsible for to read de analog pin conocted in the joystick
{
    if(analogRead(_piny) > JoysticRanges[0]) return 'B';//IF THE JOYSTIC IS MOVED BACK
    else if(analogRead(_piny) < JoysticRanges[1]) return 'F';//IF THE JOYSTIC IS MOVED FRONT

    if(analogRead(_pinx) > JoysticRanges[2]) return 'R';//IF THE JOYSTIC IS MOVED RIGTH
    else if(analogRead(_pinx) < JoysticRanges[3]) return 'L';//IF THE JOYSTIC IS MOVED LEFT 
    
    if(digitalRead(_pinPush))return 'P'; //IF THE BUTTON IS PRESSED

    return 0;
}

//------------------------------------------------------------------------------- KEYBOARD FUNCTIONS

void KeypadSetup(int *keyMatriz,byte *rowsPins,byte *colunsPins,byte nRow,byte nColun) // This function receive the all information about the keyboard 
{                                                                                      // And map the pins and variables 
  _rows = nRow;
  _coluns = nColun;
  _colunsPin = colunsPins ;
  _rowsPin = rowsPins ;
  _keys = keyMatriz;
  
  for(int x=0;x < _rows; x++)
    {
      pinMode(_rowsPin[x], OUTPUT);
      digitalWrite(_rowsPin[x], LOW);
    }
    for(int _y=0;_y < _coluns; _y++)
    pinMode(_colunsPin[_y], INPUT);
}

int KeyUpdate() // This function is responsible for to updating the keyboard, if anykey is pressed 
{
   for(int _x=0; _x < _rows; _x ++) 
   {
        for(int _r=0;_r < _rows;_r ++)
        {
          digitalWrite(_rowsPin[_r],LOW);  
        }
      digitalWrite(_rowsPin[_x], HIGH);

       for(int _s=0;_s < _coluns; _s ++)
      {
         if (digitalRead(_colunsPin[_s])) { return _keys[(_x*4)+_s];}// At that point the function returns the value corresponding to the arrey's position 
         delayMicroseconds(10);
      }
    }  return 0;
}


int KeyPress()// This function is called to check if any key was pressed, if was pressed call the KeyUpdate function for to updating 
{
  _a = KeyUpdate();
  
  if (_a != _b )
  {
    _b = _a;
    return _a;
  }
  return 0; 
}

//------------------------------------------------------------------------------- ULTRASONIC FUNCTIONS

void UltrasonicSetup(int trig, int echo) // Here are configured the ultrasonic control pins, configuring the necesary pins 
{
  _trig = trig;
  _echo = echo;
  pinMode(_trig,OUTPUT); // Define the _trig pin OUTPUT
  digitalWrite(_trig,LOW);
  pinMode(_echo,INPUT);
}

int UltrasonicMensure() // This function calculates the distance whit mathematical calculations
{
    digitalWrite(_trig, LOW);  
    delayMicroseconds(2);  
    digitalWrite(_trig, HIGH);  
    delayMicroseconds(10);  
    digitalWrite(_trig, LOW);  
    long _duration = pulseIn(_echo,HIGH);  
    long _distance = _duration /29 / 2 ;  
    return _distance;
}
