int pinY = A13;
int pinX = A12;

void setup()  { Serial.begin(115200); }

void loop()   { joystic(pinY,pinX); }

void joystic(int pin1, int pin2)
{
    if(analogRead(A13) > 3200) Serial.println("FRONT");
    else if(analogRead(A13) < 1000) Serial.println("BACK");

    if(analogRead(A12) > 2100) Serial.println("LEFT");
    else if(analogRead(A12) < 600) Serial.println("RIGHT");
}
