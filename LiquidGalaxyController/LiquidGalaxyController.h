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

#ifndef LiquidGalaxyController_h
#define LiquidGalaxyController_h

#include "Arduino.h"

class LiquidGalaxyController
{
	public:
		void JoysticSetup(*Jpins);
		char JoysticRead();
		
		void UltrasonicSetup(*UltrasonicPins);
		int  UltrasonicMensure();
		
		void KeypadSetup(*keyMatriz,*rows, *coluns,nRow,nColun);
		int KeyPress();
		
		Void VoiceSetup(int rx, int tx);
		void VoiceRead();
		void RecordCommands();
		void StartRecognition(int group);
	
		
	private:
		int _piny,_pinx,_pinPush;
		int _trig, _echo;
		int _row, _colun;
		int _rx, _tx;
		
		
			
}

#endif
