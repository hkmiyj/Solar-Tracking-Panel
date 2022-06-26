#include <SoftwareSerial.h>
#include <SimpleTimer.h>
#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

const char* ssid = "Hotspot@PUTRA-2.4G";   // your network SSID (name)
const char* password = "";   // your network password
WiFiClient  client;

unsigned long myChannelNumber = 1773686;
const char * myWriteAPIKey = "00121Z2ZVSQ5SO3T";

// Timer variables
unsigned long lastTime = 0;
unsigned long timerDelay = 30000;

SimpleTimer timer;

char rdata;
String myString;
int temperature, humid;

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}

void loop() {
    // Connect or reconnect to WiFi
    if (WiFi.status() != WL_CONNECTED) {
      Serial.print("Attempting to connect");
      while (WiFi.status() != WL_CONNECTED) {
        WiFi.begin(ssid, password);
        delay(5000);
      }
      Serial.println("\nConnected.");
    }

    // Get a sensor reading
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
        // Serial.println("fahad");
        // new code
        String t = getValue(myString, ',', 0);
        String h = getValue(myString, ',', 1);

        temperature = t.toInt();
        humid = h.toInt();

        Serial.print("Temperature : ");
        Serial.print(temperature);
        Serial.print(" Humidity : ");
        Serial.println(humid);
        myString = "";
        // end new code
      }
    }
    // set the fields with the values
    
    ThingSpeak.setField(1, temperature);
    ThingSpeak.setField(2, humid);
    int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
    
    if (x == 200) {
      Serial.println("Channel update successful.");
    }
    else {
      Serial.println("Problem updating channel. HTTP error code " + String(x));
    }
  delay(15000);
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