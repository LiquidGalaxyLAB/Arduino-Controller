/*-------------------------------------------------------------
 _ _             _     _               _                  
| (_) __ _ _   _(_) __| |   __ _  __ _| | __ ___  ___   _ 
| | |/ _` | | | | |/ _` |  / _` |/ _` | |/ _` \ \/ / | | |
| | | (_| | |_| | | (_| | | (_| | (_| | | (_| |>  <| |_| |
|_|_|\__, |\__,_|_|\__,_|  \__, |\__,_|_|\__,_/_/\_\\__, |
        |_|                |___/                    |___/ 
https://github.com/LiquidGalaxy/liquid-galaxy
https://github.com/LiquidGalaxyLAB/liquid-galaxy

https://github.com/LiquidGalaxyLAB/Arduino-Controller

Otávio Jesus França Oliveira - GSoC 2020
-------------------------------------------------------------*/

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "LiquidGalaxyController.h"

LiquidGalaxyController::JoysticSetup(int piny, int pinx, int button); // JOYSTICK CONTROLLER CONFIGURATION FUNCTION
{
	_piny = piny;
	_pinx = pinx;
	_pinPush = button;
	pinMode(_pinPush,INPUT);
}

char LiquidGalaxyController::JoysticRead() // FUNCTION FOR TO READ THE JOYSTIC CONTROLLER
{
	if(analogRead(_piny) > JoysticRanges[0]) return 'B';//IF THE JOYSTIC IS MOVED BACK
    else if(analogRead(_piny) < JoysticRanges[1]) return 'F';//IF THE JOYSTIC IS MOVED FRONT

    if(analogRead(_pinx) > JoysticRanges[2]) return 'R';//IF THE JOYSTIC IS MOVED RIGTH
    else if(analogRead(_pinx) < JoysticRanges[3]) return 'L';//IF THE JOYSTIC IS MOVED LEFT
    
    if(digitalRead(_pinPush))return 'P'; //IF THE BUTTON IS PRESSED 

    return 0;
}

LiquidGalaxyController::UltrasonicSetup(int trig, int echo) // PIN MODE SETUP 
{
	_trig = trig;
	_echo = echo;
	pinMode(_trig,OUTPUT); // Define the _trig pin OUTPUT
	digitalWrite(_trig,LOW);
	pinMode(_echo,INPUT);
}

int LiquidGalaxyController::UltrasonicMensure()
{
	digitalWrite(_trig, LOW);  
    delayMicroseconds(2);  
    digitalWrite(_trig, HIGH);  
    delayMicroseconds(10);  
    digitalWrite(_trig, LOW);  
    long duration = pulseIn(echoPin,HIGH);  
    long distance = duration /29 / 2 ;  
    
    return distance;
}

LiquidGalaxyController::KeypadSetup(*keyMatriz,*rowsPins, *colunsPins,nRow,nColun);
{
	_rows = nRow;
	_coluns = nColun;
	_conlunsPin = colunsPins ;
	_rowsPin = rowsPins ;
	_keys = keyMatriz;
	
	for(int x=0;x<rows;x++)
  	{
    	pinMode(linha[x], OUTPUT);
    	digitalWrite(linha[x], LOW);
  	}
  	for(int x=0;x<coluns;x++)pinMode(coluna[x], INPUT);
}

int LiquidGalaxyController:: KeyUpdate()//KeyPress()
{
	 for(int _x=0; _x < _rows; _x ++) 
	 {
      	for(int _r=0;_r < _rows;_r ++)
       	{
          digitalWrite(_rowsPin[_r],LOW);  // alterar para o vetor passado na função anetrior
       	}
   	 	digitalWrite(_rowsPin[_x], HIGH);

   		 for(int _s=0;_s < _coluns; _s ++)
   		{
     		 if (digitalRead(_colunsPin[_s]))       
    		{
    			return _keys[_x][_s];
     			 //printKey(_keys[_x][_s]);          /// substituir o print key por um retorno 
     			 //while(digitalRead(coluna[_s])){}  
      		}  
     		 delayMicroseconds(10);
    	}
 	  }  return 0;
}

int LiquidGalaxyController::KeyPress()
{
	_a = KeyUpdate();
	
	if (_a != _b )
	{
		_b = _a;
		return _a;
	}
	
	return 0;
}

LiquidGalaxyController::VoiceSetup(int rx, int tx, int pinOut)
{
	_rx = rx;
	_tx = tx;
	_pinOut = pinOut;
	SoftwareSerial VR3(_rx,_tx);
	VR3.begin(9600);
}

int LiquidGalaxyController::VoiceRead() 
{
	    if(VR3.available())
  	{
      for(int i = 0; i<27;i++)
     {
  		  _z[i] = VR3.read();
       	  delay(1); 
     }
      if(_z[2] == 13){Buzzer(1);return 0;}   //Fale Agora Serial.println("Speak Now");
      if(_z[2] == 15){Buzzer(1);return 0;}  //Fale de Novo Serial.println("Speak Again");
      if(_z[2] == 18){Buzzer(2);return 0;}  //ErroSerial.println("Error");
      if(_z[2] == 11){Buzzer(3);return 1;}  //Sucesso! Serial.println("Sucess!");
      if(_z[2] == 10){Buzzer(2);return 0;}  //Serial.println("End Time");
    } 
}

void LiquidGalaxyController::RecordCommands()
{
	int control;
   delay(100);
   for(int _t=0;_t<5;_t++) {VR3.write(Rec[t]);}
   
   delay(10);
   do
   {
    control = VoiceRead();
   }while (control != 1);
}

void LiquidGalaxyController::StartRecognition(int group) // Alterar o vetor de grupos com base no informado pelo usuário
{
	for(int k=0;k<8;k++)
  	{
    	VR3.write(groups[Group][k]);
  	}
}

void LiquidGalaxyController::PinOut(int Comand)
{
	_Comand = Coamnd;
	switch(_Comand)
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









