#include <Servo.h>

Servo servoUD;
Servo servoLR; //blueservo

int LDR1 = A0; // Analog 0  
int LDR2 = A1;
int LDR3 = A2;
int LDR4 = A3;
  
void setup()  
{  
    servoUD.attach(8);
    servoLR.attach(9);  
    Serial.begin(9600);
    delay(500);
}  
void loop()  
{  
  Serial.println(analogRead(LDR1)); 
  servoUD.write(360);
  servoLR.write(360);
}  
