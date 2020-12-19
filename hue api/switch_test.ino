const int  buttonPin = D6;    // the pin that the pushbutton is attached to

int buttonState = 0;         
 

void setup() {

  pinMode(buttonPin, INPUT_PULLUP);
  
  Serial.begin(115200);
}


void loop() {
  
  buttonState = digitalRead(buttonPin);

  Serial.println(buttonState);

  delay(50);

}
