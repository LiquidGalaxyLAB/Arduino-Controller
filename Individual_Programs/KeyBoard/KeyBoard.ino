
//------------------------------------------------------------------------
//DEFINICOES DE PARAMETROS PARA O TECLADO
const byte NumberRows = 4;
const byte NumberColuns = 4;
int linha[NumberRows] ={14,27,26,25}; 
int coluna[NumberColuns]={33,32,35,34};

char control;

char Keys[NumberRows] [NumberColuns] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
//------------------------------------------------------------------------
int x;
void setup()
{
  KeyConfig(NumberRows,NumberColuns);  
    
  Serial.begin(9600);
}

void loop()
{ 

KeyPress();

}
//------------------------------------------------------------------------------

void KeyPress()
{
    for(x=0;x<NumberRows;x++) 
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
{
       Serial.print(x);
       Serial.println();
      
}

void KeyConfig(int rows, int coluns)
{
  for(x=0;x<rows;x++)
  {
    pinMode(linha[x], OUTPUT);
    digitalWrite(linha[x], LOW);
   }
   
  for(x=0;x<coluns;x++)pinMode(coluna[x], INPUT);   
}
