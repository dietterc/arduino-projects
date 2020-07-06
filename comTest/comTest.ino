#include "ESP8266WiFi.h"
 
const char* ssid = "Dietterle-guest";
const char* password = "97ca22f7ce";
 
WiFiServer wifiServer(80);

void setup() {
  Serial.begin(115200);
 
  delay(1000);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting..");
  }
 
  Serial.print("Connected to WiFi. IP:");
  Serial.println(WiFi.localIP());
  
 
  wifiServer.begin();
}

void loop() {

  WiFiClient client = wifiServer.available();
 
  if (client) {
    while (client.connected()) {
      //client loop
      while (client.available()>0) {
        char c = (char) client.read();
        Serial.write(c);
      }
      delay(10);
    }

    client.stop();
    Serial.println("\nClient disconnected");
  }
}
