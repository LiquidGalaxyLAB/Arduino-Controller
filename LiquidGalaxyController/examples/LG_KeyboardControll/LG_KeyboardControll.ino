#include <LiquidGalaxyController.h>

const byte NumberRows = 4;
const byte NumberColuns = 4;
byte linha[NumberRows] ={13,12,14,27}; 
byte coluna[NumberColuns]={26,25,33,32};
int Keys[NumberRows*NumberColuns] = 
  {1, 2, 3, 4,
   5, 6, 7, 8,
   9,10,11,12,
  13,14,15,16};

LG_Keypad LGKey(Keys,linha,coluna,NumberRows,NumberColuns);

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
   int key = LGKey.KeyPress(); // KEYBOARD FUNCTION
   if(key) Serial.println(key);
}
