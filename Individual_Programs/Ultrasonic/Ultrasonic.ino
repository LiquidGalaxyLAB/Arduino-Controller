
#define echoPin 13  
#define trigPin 12   
  
void setup()  
{  
   Serial.begin(115200);   
   pinMode(echoPin, INPUT);   
   pinMode(trigPin, OUTPUT);   
   pinMode(11, OUTPUT); 
   digitalWrite(11,HIGH);
}  
  
void loop()  
{  
  
    digitalWrite(trigPin, LOW);  
    delayMicroseconds(2);  
    digitalWrite(trigPin, HIGH);  
    delayMicroseconds(10);  
    digitalWrite(trigPin, LOW);  
    long duration = pulseIn(echoPin,HIGH);  
    long distance = duration /29 / 2 ;  
  
  if(distance < 25)
  {
    Serial.print("Distance CM: ");  
    Serial.print(map(distance,0,25,0,100));  
    Serial.println("  %");
  }
}  
