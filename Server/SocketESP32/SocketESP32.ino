#include <WiFi.h>
 
const char* ssid = "Ilana";
const char* password =  "32513296";
 
const uint16_t port = 8090;
const char * host = "192.168.0.10";

String places[16] = 
  { "flyto/55.270782/25.204849/107000",
    "flyto/100.501762/13.756331/58000",
    "flyto/-0.127758/51.507351/37000",
    "flyto/2.352413/48.856483/2000",
  };
 
void setup()
{
 
  Serial.begin(9600);
 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("...");
  }
 
  Serial.print("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());
 
}
 
void loop()
{
    WiFiClient client;
 
    if (!client.connect(host, port)) {
 
        Serial.println("Connection to host failed");
 
        delay(1000);
        return;
    }
 
    Serial.println("Connected to server successful!");
 for(int x; x<4;x++)
 {
    client.print(places[x]);
    delay(1000);
 }
    client.stop();
 
    delay(1000);
}
