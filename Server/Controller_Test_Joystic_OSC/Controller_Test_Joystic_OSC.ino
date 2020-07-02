#include <LiquidGalaxyController.h>
//---------------------------------------------------------------------------------------------
#include <WiFi.h>
#include <WiFiUdp.h>
#include <OSCBundle.h>  
#include <OSCMessage.h>
char ssid[] = "Ilana"; 
char pass[] = "32513296";
WiFiUDP Udp;                           // UDP instance to let us send and receive UDP packets
const IPAddress outIp(192,168,0,11);
const unsigned int localPort = 8000;   // Local port to listen for UDP packets 
const unsigned int outPort = 5005;    // Destination port for sending OSC messages
//---------------------------------------------------------------------------------------------
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
int JoysticRanges[] = {3200,10,3200,100};        // You can check these values just by reading the analog inputs corresponding to the joystic 
                       //B,F,R,P                 //and define the value that you consider best
LG_JoysticSetup joystic(A6,A7,4,JoysticRanges);
LG_UltrasonicSetup Ultrasonic(21,19);

int moviment =0;

void setup() 
{
  Serial.begin(9600);
  //WiFi.config(IPAddress(192,168,0,123),IPAddress(192,168,0,5), IPAddress(255,255,255,0));
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, pass);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    Serial.println("Starting UDP");
    Udp.begin(localPort);
    Serial.print("Local port: "); 
}

void loop() 
{ 
   
  
   int key = LGKey.KeyPress(); // KEYBOARD FUNCTION
   if(key) 
   {
     Serial.println(key);
   }

   char joy = joystic.JoysticRead();// JOYSTICK FUNCTION
   if(joy)
   {
    moviment =1;
    Serial.println(joy);
    switch (joy)
    {
      case 'F':
      SendMessage(5);
      break;

      case 'B':
      SendMessage(6);
      break;
      
      case 'R':
      SendMessage(3);
      break;

      case 'L':
      SendMessage(4);
      break;

      case 'P':
      SendMessage(2);
      break;
    }
   } else  if(moviment==1){ Serial.println("Stop"); SendMessage(0); moviment=0;}
/*
   int distance = Ultrasonic.UltrasonicMensure();// ULTRASONIC FUNCTION 
   if(distance < 15) 
   { 
    Serial.print("Distance CM: "); 
    Serial.print(map(distance,0,25,0,100)); 
    Serial.println("  %"); 
    SendMessage(1);
   }    */

}
//-------------------------------------------------------------------------------------------------------------------------
void SendMessage(int rec)
{
    OSCMessage msg("/lg/Controller");
    msg.add(rec);
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp);
    Udp.endPacket();
    msg.empty();
    //delay(500); 
}

//-------------------------------------------------------------------------------------------------------------------------
