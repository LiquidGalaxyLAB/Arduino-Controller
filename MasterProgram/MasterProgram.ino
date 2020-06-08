#include <SoftwareSerial.h>

//---------------------------------------------------------------------- VOICE RECOGNITION CONFIGURATIONS
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
//---------------------------------------------------------------------- KEYBOARD CONFIGURATIONS
const byte NumberRows = 4;
const byte NumberColuns = 4;
int linha[NumberRows] ={13,12,14,27}; 
int coluna[NumberColuns]={26,25,33,32};
char Keys[NumberRows] [NumberColuns] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
//----------------------------------------------------------------------
#define echoPin 19  
#define trigPin 21 
#define buz 18
#define pinY A12
#define pinX A13
int bot = 4;

void setup() 
{
  Serial.begin(9600);
  VR3.begin(9600);
  pinMode(4,INPUT);// JOYSTIC BUTTON
  pinMode(buz,OUTPUT);// LED CONNECTION
  digitalWrite(buz,LOW);
  //------------------------------------- // ULTRASONIC SENSOR COMMANDS
   pinMode(echoPin, INPUT);   
   pinMode(trigPin, OUTPUT);   
   pinMode(11, OUTPUT); 
   digitalWrite(11,HIGH);
  //-------------------------------------
  KeyConfig(NumberRows,NumberColuns); // KEYBOARD SETUP
}

void loop() 
{
  if(digitalRead(5))
  {
    RecordComands();// RECORD COMMANDS
  }
   VoiceRead(); // READ VOICE MODULE COMMANDS
   joystic(pinY,pinX,bot); // JOYSTICK FUNCTION
   Ultrasonic(); // ULTRASONIC FUNCTION
   KeyPress(); // KEYBOARD FUNCTION
}

//--------------------------------------------------------------------------------------------------------------
//VOICE RECOGNITION COMMANDS
int VoiceRead()
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
      if(a[2] == 13){Serial.println("Speak Now");Buzzer(1);return 0;}   //Fale Agora
      if(a[2] == 15){Serial.println("Speak Again");Buzzer(1);return 0;} //Fale de Novo
      if(a[2] == 18){Serial.println("Error");Buzzer(2);return 0; }         //Erro
      if(a[2] == 11){Serial.println("Sucess!");Buzzer(3);return 1;}     //Sucesso!
      if(a[2] == 10){Serial.println("End Time");Buzzer(2);return 0;}   
    } 
}

void RecordComands()
{
   int control;
   delay(100);
   for(int t=0;t<5;t++){VR3.write(Rec[t]);}
   Serial.println("Voice Record");//Gravar voz
   delay(10);
   do
   {
    control = VoiceRead();
   }while (control != 1);
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
//--------------------------------------------------------------------------------------------------------------
//JOYSTICK COMMANDS
void joystic(int pin1, int pin2, int bot)
{
    if(analogRead(pin1) > 3200) Serial.println("BACK");
    else if(analogRead(pin1) < 100) Serial.println("FRONT");

    if(analogRead(pin2) > 3200) Serial.println("RIGTH");
    else if(analogRead(pin2) < 600) Serial.println("LEFT"); 
    
    if(digitalRead(bot)) Serial.println("BUTTON");
}
//--------------------------------------------------------------------------------------------------------------
//ULTRASONIC FUNCTION
void Ultrasonic()
{
    digitalWrite(trigPin, LOW);  
    delayMicroseconds(2);  
    digitalWrite(trigPin, HIGH);  
    delayMicroseconds(10);  
    digitalWrite(trigPin, LOW);  
    long duration = pulseIn(echoPin,HIGH);  
    long distance = duration /29 / 2 ;  
  
  if(distance < 25)
  {
    Serial.print("Distance CM: ");  
    Serial.print(map(distance,0,25,0,100));  
    Serial.println("  %");
  }
}
//--------------------------------------------------------------------------------------------------------------
//KEYBOARD FUNCTIONS
void KeyPress()
{
    for(int x=0;x<NumberRows;x++) 
  {
      for(int r=0;r<NumberRows;r++)
       {
          digitalWrite(linha[r],LOW);
       }
    digitalWrite(linha[x], HIGH);

    for(int s=0;s<NumberColuns;s++)
    {
      if (digitalRead(coluna[s]))       
      {
    
      printKey(Keys[x][s]);   
      while(digitalRead(coluna[s])){}  
      }  
      delayMicroseconds(10);
    }
   }  
}
//------------------------------------------------------------------------------

void printKey(char x)
{ Serial.print(x);  Serial.println(); }

void KeyConfig(int rows, int coluns)
{
  for(int x=0;x<rows;x++)
  {
    pinMode(linha[x], OUTPUT);
    digitalWrite(linha[x], LOW);
   }
   
  for(int x=0;x<coluns;x++)pinMode(coluna[x], INPUT);   
}
