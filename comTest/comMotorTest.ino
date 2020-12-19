#include "ESP8266WiFi.h"
#include <Stepper.h>

const char* ssid = "Dietterle-guest";
const char* password = "97ca22f7ce";
const int stepsPerRevolution = 200; 

WiFiServer wifiServer(80);
Stepper myStepper1 = Stepper(200, D0, D1, D2, D3);
Stepper myStepper2 = Stepper(200, D5, D6, D7, D8);

void setup() {
  myStepper1.setSpeed(45);
  myStepper2.setSpeed(45);

  //WIFI STUFF
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
  
  myStepper1.step(-20);
  delay(1000)
  myStepper1.step(20);

}
