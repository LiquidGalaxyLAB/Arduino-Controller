//HexaCodeMapping

#include <SoftwareSerial.h>
SoftwareSerial VR3(2,3);
byte a[11];
int selecao = 1;
void setup() {
VR3.begin(9600);

delay(1000);
VR3.write(0xAA);
VR3.write(0x02);
VR3.write(0x31);
VR3.write(0x0A);

delay(100);
VR3.write(0xAA);
VR3.write(0x06);
VR3.write(0x30);
VR3.write(0X01); 
VR3.write(0X03); 
VR3.write(0X04); 
VR3.write(0X05); 
VR3.write(0x0A);
delay(100);

}

void loop() {

if(VR3.available()){

for(int i = 0; i < 10 ; i++){
  a[i] = VR3.read();
  delay(10);
}

if( a[1] == 7 ) {

   switch (a[5]){
   
   case 1:
   Serial.println("Alternar entre os grupos!");

    //Carregar - Grupo 1
   if(selecao ==1){
    VR3.write(0xAA);
    VR3.write(0x06);
    VR3.write(0x30);
    VR3.write(0X01); 
    VR3.write(0X03); 
    VR3.write(0X04); 
    VR3.write(0X05);
    VR3.write(0x0A); 
  
   }
   if(selecao ==2){
   VR3.write(0xAA);
   VR3.write(0X05);
   VR3.write(0X30);
   VR3.write(0X01);
   VR3.write(0X07);
   VR3.write(0X08);
   VR3.write(0x0A); 
   }
   if(selecao ==3){
   VR3.write(0xAA);
   VR3.write(0X08);
   VR3.write(0X30);
   VR3.write(0X01);
   VR3.write(0X09);
   VR3.write(0X0a);
   VR3.write(0X0b);
   VR3.write(0X0c);
   VR3.write(0X0d);
   VR3.write(0x0A); 
  
   }
   if(selecao ==4){
   VR3.write(0xAA);
   VR3.write(0X09);
   VR3.write(0X30);
   VR3.write(0X01);
   VR3.write(0X0e);
   VR3.write(0X0f);
   VR3.write(0X10);
   VR3.write(0X11);
   VR3.write(0X12);
   VR3.write(0X13);
   VR3.write(0x0A); 
  
   }
   if(selecao ==5){
   VR3.write(0xAA);
   VR3.write(0X09);
   VR3.write(0X30);
   VR3.write(0X01);
   VR3.write(0X14);
   VR3.write(0X15);
   VR3.write(0X16);
   VR3.write(0X17);
   VR3.write(0X18);
   VR3.write(0X19);
   VR3.write(0x0A); 
  
   }
   if(selecao ==6){
      VR3.write(0xAA);
   VR3.write(0X09);
   VR3.write(0X30);
   VR3.write(0X01);
   VR3.write(0X1a);
   VR3.write(0X1b);
   VR3.write(0X1c);
   VR3.write(0X1d);
   VR3.write(0X1e);
   VR3.write(0X1f);
   VR3.write(0x0A); 
   
   }
   if(selecao ==7){
      VR3.write(0xAA);
   VR3.write(0X09);
   VR3.write(0X30);
   VR3.write(0X01);
   VR3.write(0X20);
   VR3.write(0X21);
   VR3.write(0X22);
   VR3.write(0X23);
   VR3.write(0X24);
   VR3.write(0x25);
   VR3.write(0x0A); 
   
   }
   if(selecao ==8){
      VR3.write(0xAA);
   VR3.write(0X09);
   VR3.write(0X30);
   VR3.write(0X01);
   VR3.write(0X26);
   VR3.write(0X27);
   VR3.write(0X28);
   VR3.write(0X29);
   VR3.write(0X2a);
   VR3.write(0X2b);
   VR3.write(0x0A); 
   
   }
   if(selecao ==9){
      VR3.write(0xAA);
   VR3.write(0X09);
   VR3.write(0X30);
   VR3.write(0X01);
   VR3.write(0X2c);
   VR3.write(0X2d);
   VR3.write(0X2e);
   VR3.write(0X2f);
   VR3.write(0X30);
   VR3.write(0X31);
   VR3.write(0x0A); 
   
   }
   if(selecao ==10){
   VR3.write(0xAA);
   VR3.write(0X09);
   VR3.write(0X30);
   VR3.write(0X01);
   VR3.write(0X32);
   VR3.write(0X33);
   VR3.write(0X34);
   VR3.write(0X35);
   VR3.write(0X36);
   VR3.write(0X37);
   VR3.write(0x0A); 
   
   }
   if(selecao ==11){
   VR3.write(0xAA);
   VR3.write(0X09);
   VR3.write(0X30);
   VR3.write(0X01);
   VR3.write(0X38);
   VR3.write(0X39);
   VR3.write(0X3a);
   VR3.write(0X3b);
   VR3.write(0X3c);
   VR3.write(0X3d);
   VR3.write(0x0A); 
   
   }
   if(selecao ==12){
      VR3.write(0xAA);
   VR3.write(0X09);
   VR3.write(0X30);
   VR3.write(0X01);
   VR3.write(0X3e);
   VR3.write(0X3f);
   VR3.write(0X40);
   VR3.write(0X41);
   VR3.write(0X42);
   VR3.write(0X43);
   VR3.write(0x0A); 
   
   }
   if(selecao ==13){
   VR3.write(0xAA);
   VR3.write(0X09);
   VR3.write(0X30);
   VR3.write(0X01);
   VR3.write(0X44);
   VR3.write(0X45);
   VR3.write(0X46);
   VR3.write(0X47);
   VR3.write(0X48);
   VR3.write(0X49);
   VR3.write(0x0A); 
   
   }
   if(selecao ==14){
   VR3.write(0xAA);
   VR3.write(0X09);
   VR3.write(0X30);
   VR3.write(0X01);
   VR3.write(0X4a);
   VR3.write(0X4b);
   VR3.write(0X4c);
   VR3.write(0X4d);
   VR3.write(0X4e);
   VR3.write(0X4f);
   VR3.write(0x0A); 
   selecao = 0;
   }
 
   if(selecao < 14){
    selecao = selecao + 1; 
   }
      break;
   case 2:
   Serial.println("Carregar comandos da sala de estar!");
   //Carregar comandos 1, 3, 4 e 5
    VR3.write(0xAA);
    VR3.write(0x06);
    VR3.write(0x30);
    VR3.write(0X01); 
    VR3.write(0X03);
    VR3.write(0X04); 
    VR3.write(0X05); 
    VR3.write(0x0A);
   break;

    case 3:
   Serial.println("Ligar/Desligar lâmpada da sala de estar");
   break;

   case 4:
   Serial.println("Ligar/Desligar televisão!");
   break;

   case 5:
   Serial.println("Ligar/Desligar Abajur!");
   break;

   case 6:
   Serial.println("Carregar comandos da cozinha");
    //Carregar comandos 1, 7, 8
    VR3.write(0xAA);
    VR3.write(0x05);
    VR3.write(0x30);
    VR3.write(0X01);
    VR3.write(0X03); 
    VR3.write(0X04);
    VR3.write(0x0A);
   break;

   case 7:
   Serial.println("Ligar/Desligar lâmpada da cozinha");
   break;

   case 8:
   Serial.println("Ligar/Desligar cafeteira");
   break;

   case 9:
   Serial.println("Ligar/Desligar lâmpada do banheiro");
   break;

   case 10:
   Serial.println("Ligar/Desligar lâmpada do quarto");
   break;

   case 11:
   Serial.println("Ligar/Desligar lâmpada escritório");
   break;

   case 12:
   Serial.println("Ligar/Desligar lâmpada da terraço");
   break;

   case 13:
   Serial.println("Ligar/Desligar jardim");
   break;

   case 14:
   break;
  
    case 15:
   break;


    case 16:
   break;


    case 17:
   break;

    case 18:
   break;

   case 19:
   
   break;

   case 20:
   
   break;

   case 21:
   
   break;

   case 22:
   
   break;

   case 23:
   
   break;

   //basta você adicionar até o comando 79. case 24...case24....case25...
   
   default:
   Serial.println("Comando não contemplado no projeto");
   break;
    
   }

}
  
}

}
