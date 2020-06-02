//#include <SoftwareSerial.h>
//SoftwareSerial VR3(2,3); // 2 receptor do microcontrolador  3 transmissor

byte a[11]; // a variável byte armazena possui 8 bits de tamanho. Como a informação que chega do 
            // do módulo V3 possui dois caractere hexadecimal (FC, por exemplo), byte se torna
            // um tipo de variável ideal

void setup()
{
  Serial1.begin(9600);
  Serial.begin(9600);    //Serial.println("SEJAM BEM-VINDOS AO CANAL L GUSTAVO");
  
      Serial1.write(0xaa); // COMANDO PARA INICIAR COMUNICACAO
      Serial1.write(0x07); // QUANTIDADE DE COMANDOS CARREGADOS ( 3 + n )
      Serial1.write(0x30); // COMANDO ENVIADO PARA CARREGAR COMANDOS
      Serial1.write(0x01); // CARREGA COMANDO 0
      Serial1.write(0x02); // CARREGA COMANDO 1
      Serial1.write(0x03); // CARREGA COMANDO 2
      Serial1.write(0x04); // CARREGA COMANDO 3
      Serial1.write(0x05); // CARREGA COMANDO 4
      Serial1.write(0x0a); // COMANDO PARA FINALIZAR COMUNICAÇÃO
      
  delay(100);
  for(int i = 0; i<11;i++){
  a[i] = Serial1.read();
  Serial.print( a[i],HEX);
  Serial.print("-");
  delay(1); 
}
 Serial.println("");
 
delay(100);
  // Mensagem para habilitar o modulo v3 para reconhecer os comandos
      Serial1.write(0xaa);
      Serial1.write(0x0D);
      Serial1.write(0x0a);

delay(100);
}

void loop()
{
  if(Serial1.available())
  {
    for(int i = 0; i<9;i++)
    {
      a[i] = Serial1.read();
      Serial.print( a[i],HEX);
      Serial.print("-");
      delay(1); 
    }
    Serial.println("");
    Serial.print("Comando reconhecido:"); // MOSTRA NO MONITOR SERIAL QUAL COMANDO FOI RECONHECIDO
    Serial.println(a[5]);
  }
}
