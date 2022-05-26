#include <Servo.h>

Servo servoUD;
Servo servoLR;

int LDR1 = A0; // Analog 0  
int LDR2 = A1;
int LDR3 = A2;
int LDR4 = A3;
  
void setup()  
{  
    Serial.begin(9600);  
    servoUD.attach(6);
    servoLR.attach(5);
}  
void loop()  
{  
  
    Serial.println(analogRead(LDR1));  
    int LDRWest=analogRead(LDR1);
    delay(1000); 
    
    if ( LDRWest<400){
       servoLR.write(90);
       servoUD.write(90);
    }
}  
