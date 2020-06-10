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
		void JoysticSetup(int piny, int pinx, int pin button);
		char JoysticRead();
		
		void UltrasonicSetup(int trig, int echo);
		int  UltrasonicMensure();
		
		void KeypadSetup(*keyMatriz,*rows, *coluns,nRow,nColun);
		int KeyPress();
		
		void VoiceSetup(int rx, int tx, int pinOut);
		int VoiceRead();
		void RecordCommands();
		void StartRecognition(int group);
	
		
	private:
		int _piny,_pinx,_pinPush;
		int _trig, _echo;
		int _rows, _coluns;
		int _rx, _tx;
		byte *_rowsPin;
		byte  *_conlunsPin;
		byte *_keys;
		int _a = 0;
		int _b = 0;
		byte _z[27]; // antigo a
		int _pinOut; // Voice record indicator
		int _Comand;
		
		int  KeyUpdate();
		void PinOut(int Comand); // Verificar necessidade
			
}

#endif
