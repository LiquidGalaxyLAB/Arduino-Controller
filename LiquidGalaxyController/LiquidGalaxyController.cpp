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
#include "LiquidGalaxyController.h"

LiquidGalaxyController::JoysticSetup(*Jpins);
{
	_piny = Jpins[0];
	_pinx = Jpins[1];
	_pinPush = Jpins[2];
	pinMode(_pinPush,INPUT);
}

char LiquidGalaxyController::JoysticRead()
{
	if(analogRead(_piny) > JoysticRanges[0]) return 'B';//Serial.println("BACK");
    else if(analogRead(_piny) < JoysticRanges[1]) return 'F';//Serial.println("FRONT");

    if(analogRead(_pinx) > JoysticRanges[2]) return 'R';//Serial.println("RIGTH");
    else if(analogRead(_pinx) < JoysticRanges[3]) return 'L';//Serial.println("LEFT"); 
    
    if(digitalRead(_pinPush))return 'P'; //Serial.println("BUTTON");

    return 0;
}

LiquidGalaxyController::UltrasonicSetup(*UltrasonicPins)
{
	_trig = Ultrasonic[0];
	_echo = Ultrasonic[1];
	pinMode(_trig,OUTPUT);
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

LiquidGalaxyController::KeypadSetup(*keyMatriz,*rows, *coluns,nRow,nColun);
{
	keys[]=keyMatriz;
	
	for(int x=0;x<rows;x++)
  	{
    	pinMode(linha[x], OUTPUT);
    	digitalWrite(linha[x], LOW);
  	}
  	for(int x=0;x<coluns;x++)pinMode(coluna[x], INPUT);
}
