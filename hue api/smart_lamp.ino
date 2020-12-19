#include "ESP8266HTTPClient.h"
#include "ESP8266WiFi.h"
 
const char* ssid = "Dietterle-guest";
const char* password =  "97ca22f7ce";

int switchState = 0;
const int switchPin = D6;

void setup() {
 
  Serial.begin(115200);
  
  //switch
  pinMode(switchPin, INPUT_PULLUP);
 
  WiFi.begin(ssid, password); 
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
 
}
 
void loop() {
 
  if(WiFi.status()== WL_CONNECTED) {
    int newState = digitalRead(switchPin);

    if(switchState != newState) {
      switchState = newState;
      
      HTTPClient http;   
      http.begin("http://192.168.0.234/api/qVdY4BaRx5XkhQDi4Qe5G4Llh68XHTuBbr-68sb6/lights/1/state"); 
      http.addHeader("Content-Type", "text/plain");
      int httpResponseCode = 0;
      
      if(switchState == 0) {
        char json[] = "{\"on\":false}";
        httpResponseCode = http.PUT(json);
      }
      else {
        char json[] = "{\"on\":true}";
        httpResponseCode = http.PUT(json);
      }
   
      if(httpResponseCode>0){
        String response = http.getString();   
   
        Serial.println(httpResponseCode);
        Serial.println(response);          
      }
      else {
        Serial.print("Error on sending Request: ");
        Serial.println(httpResponseCode);
      }
      http.end();
    }
  }
  else {
    Serial.println("Error in WiFi connection, attempting to reconnect...");
    recon();
  }
  
  Serial.println(switchState);
  delay(100);
}

void recon() {

  WiFi.begin(ssid, password); 
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Reconnecting to WiFi..");
  }
 
  Serial.println("Reconnected to the WiFi network");

}
