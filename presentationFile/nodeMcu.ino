#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <dht.h>
#define dht_apin 5
dht DHT;
const char *ssid =  "Hotspot@PUTRA-2.4G";  
const char *pass =  "";
 
 
WiFiClient client;
 
long myChannelNumber = 1781971;
const char myWriteAPIKey[] = "BP8SWGJNHKJI35ZO";
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  DHT.read11(dht_apin);
  float h = DHT.humidity;
  float t = DHT.temperature;
  Serial.println("Temperature: " + (String) t);
  Serial.println("Humidity: " + (String) h);
  ThingSpeak.writeField(myChannelNumber, 1, t, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 2, h, myWriteAPIKey);
  delay(2000);
}