#include <Servo.h>

Servo servoUD; // Black Servo
int servoUDpin = 8;
Servo servoLR; // Blue Servo
int servoLRpin = 9;

// Set limit it rotate
int servoLimitHigh = 180;
int servoLimitLow = 180;

// LDR
int LdrTR = A0; // Top right
int LdrTL = A1; // Top left
int LdrBR = A2; // Bot right
int LdrBL = A3; // Bot left

int tempt = A4; // Temperature sensor

void setup()
{
    servoUD.attach(servoUDpin);
    servoLR.attach(servoLRpin);
    servoUD.write(60);
    servoLR.write(60);

    Serial.begin(9600);
    delay(500);
}
void loop()
{

    int valServoUD = servoUD.read();
    int valServoLR = servoLR.read();

    int topR = analogRead(LdrTR);
    int topL = analogRead(LdrTL);
    int botR = analogRead(LdrBR);
    int botL = analogRead(LdrBL);

    int avgtop = (topL + topR);   // average of top
    int avgbot = (botL + botL);   // average of bottom
    int avgleft = (topL + botL);  // average of left
    int avgright = (topR + botR); // average of right

    // To move Up and down of the servo
    if (avgtop < avgbot)
    {
        servoUD.write(valServoUD + 1);

        if (valServoUD > servoLimitHigh)
        {
            valServoUD = servoLimitHigh;
        }
        delay(10);
    }
    else if (avgbot < avgtop)
    {

        servoUD.write(valServoUD - 1);

        if (valServoUD < servoLimitLow)
        {
            valServoUD = servoLimitLow;
        }

        delay(10);
    }
    else
    {
        servoUD.write(valServoUD);
    }

    // To move Left and Right of the servo

    if (avgleft > avgright)
    {
        servoLR.write(valServoLR + 1);

        if (valServoLR > servoLimitHigh)
        {
            valServoLR = servoLimitHigh;
        }
    }
    else if (avgright > avgleft)
    {
        servoLR.write(valServoLR - 1);
    }
    else
    {
        servoLR.write(valServoLR);
    }

    delay(10);
}