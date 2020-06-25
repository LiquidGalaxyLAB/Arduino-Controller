//#include <ESP8266WiFi.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <OSCBundle.h>                 // for receiving OSC messages

char ssid[] = "Ilana";                 // your network SSID (name)
char pass[] = "32513296";              // your network password

const int ledPin = 14; 
unsigned int ledState = 1;
WiFiUDP Udp;                           // A UDP instance to let us send and receive packets over UDP
const unsigned int localPort = 8000;   // local port to listen for UDP packets at the NodeMCU (another device must send OSC messages to this port)
const unsigned int destPort = 9000;    // remote port of the target device where the NodeMCU sends OSC to

void setup() {
    Serial.begin(115200);

     // Specify a static IP address for NodeMCU
     // If you erase this line, your ESP8266 will get a dynamic IP address
    WiFi.config(IPAddress(192,168,0,123),IPAddress(192,168,0,3), IPAddress(255,255,255,0)); 

    // Connect to WiFi network
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
//    Serial.println(Udp.localPort());

    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);   // turn *off* led

}


void loop() {
  OSCMessage msgIN;
  int size;
  if((size = Udp.parsePacket())>0){
    while(size--)
      msgIN.fill(Udp.read());
    if(!msgIN.hasError()){
      msgIN.route("/1/push1",toggleOnOff);
    }
  }
}


void toggleOnOff(OSCMessage &msg, int addrOffset){
  ledState = (boolean) msg.getFloat(0);

  digitalWrite(ledPin, HIGH);
  Serial.println(ledState);              // External LED
  
  if (ledState) {
    Serial.println("LED on");
  }
  else {
    Serial.println("LED off");
  }
  ledState = !ledState;     // toggle the state from HIGH to LOW to HIGH to LOW ...
}
