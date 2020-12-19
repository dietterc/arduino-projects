int greenpin = 11; //select the pin for the red LED
int bluepin = 10; // select the pin for the  blue LED
int redpin = 9;// select the pin for the green LED

int val;

void setup() {
  pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  Serial.begin(9600);

  analogWrite(redpin, 255); 
  analogWrite(greenpin, 150);  
  analogWrite(bluepin, 200);  
  
}

void loop() 
{
  
}
