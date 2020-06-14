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

class LG_JoysticSetup
{
	public:
		LG_JoysticSetup(int piny, int pinx, int button,int *_Range);
		char JoysticRead();
		
	private:
		int _piny,_pinx,_pinPush; // ALL VARIABLES ARE CHANGED
		byte *_range;
	
};

class LG_UltrasonicSetup
{
	public:
		LG_UltrasonicSetup(int _Trig, int _Echo);
		int  UltrasonicMensure();
		
	private:
		int _trig, _echo;
		long _duration;
		long _distance;
	
};

class LG_Keypad
{
	public:
		LG_Keypad(int *keyMatriz,byte *rowsPins,byte *colunsPins,byte nRow,byte nColun);
		int KeyPress();
		
	private:
		int KeyUpdate(); // GANGED THE TIPE
		
		byte _rows, _coluns;
    	byte *_rowsPin;
    	byte *_colunsPin;
    	int *_keys;
    	int _a = 0;
    	int _b = 0;
};
	
class LG_VoiceSetup
{
	public:
		LG_VoiceSetup(int _pin);				
		void RecordCommands(int Ncommand);
		void StartRecognition(int group);
		void GetRecognition(); 
		
	private:
		int VoiceRead();
		void PinOut(int Command) 
		
		int _rx, _tx;
		byte _z[27]; // antigo a
    	int _pinOut = 0; // Voice record indicator
    	int _Command;
    	int _control;
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
};

#endif


//	public:
		//void JoysticSetup(int piny, int pinx, int button);
		//char joysticRead();
		
		//void UltrasonicSetup(int trig, int echo);
		//int  UltrasonicMensure();
		
		//void KeypadSetup(int *keyMatriz,byte *rowsPins,byte *colunsPins,byte nRow,byte nColun);
		//int KeyPress();
		
		//int VoiceRead();
		//void RecordCommands(int Ncommand);
		//void StartRecognition(int group);

		
	//private:
		//int _piny,_pinx,_pinPush; // ALL VARIABLES ARE CHANGED
    	//int _trig, _echo;
   		//byte _rows, _coluns;
    	//byte *_rowsPin;
    	//byte *_colunsPin;
    	//int _rx, _tx; 
    	//int *_keys;
    	//int _a = 0;
    	//int _b = 0;
    	//byte _z[27]; // antigo a
    	//int _pinOut; // Voice record indicator
    	//int _Command;

    	/*byte a[27];
    	char Rec[] = {0xaa,0x03,0x20};// Comand test
    	int gorups[] = {0,1,2,3,4}; // Array with groups index
    	byte ComandsNumber[] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14};
    	byte groups[5] [8]={
      		{0xAA,0x06,0x30,0x01,0x02,0x03,0x04,0x0A}, // PLace Groups this command is used to recognize the voice commands of the first group
      		{0xAA,0x06,0x30,0x05,0x06,0x07,0x08,0x0A}, // First Group
      		{0xAA,0x06,0x30,0x09,0x0A,0x0B,0x0C,0x0A}, // Second Group
      		{0xAA,0x06,0x30,0x0D,0x0E,0x0F,0x10,0x0A}, // Third Group
      		{0xAA,0x06,0x30,0x11,0x12,0x13,0x14,0x0A} }; */
      		
      	//void VoiceSetPinOut(int _pin); //new
      	//void PinOut(int Command); // Verificar necessidade
       //void VoiceSetPinOut(int _pin);
      			
		//int KeyUpdate(); // GANGED THE TIPE
		


