#include <SoftwareSerial.h>
#include <SimpleTimer.h>

SimpleTimer timer;

char rdata;
String myString;
int temperature, humid, angServoUD,angServoLR,avgLdrUD,avgLdrLR;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() == 0 )
  {
    timer.run();
  }
  if (Serial.available() > 0 )
  {
    rdata = Serial.read();
    myString = myString + rdata;
    // Serial.print(rdata);
    if ( rdata == '\n')
    {
      //  Serial.println(myString);
      String t = getValue(myString, ',', 0);
      String h = getValue(myString, ',', 1);
      String angServoUD = getValue(myString, ',', 2);
      String angServoLR = getValue(myString, ',', 3);
      String avgLdrUD = getValue(myString, ',', 4);
      String avgLdrLR = getValue(myString, ',', 5);

      temperature = t.toInt();
      humid = h.toInt();
      angServoUD = h.toInt();
      angServoLR = h.toInt();
      avgLdrUD = h.toInt();
      avgLdrLR = h.toInt();

      Serial.print("Temperature : ");
      Serial.println(temperature);
      Serial.print(" Humidity : ");
      Serial.println(humid);
      Serial.print(" Angle Servo Up-Down : ");
      Serial.println(angServoUD);
      Serial.print(" Angle Servo Left-Right : ");
      Serial.println(angServoLR);
      Serial.print(" Average LDR Up-Down : ");
      Serial.println(avgLdrUD);
      Serial.print(" Average LDR Left-Right : ");
      Serial.println(avgLdrLR);
      myString = "";
      // end new code
    }
  }
}

String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}