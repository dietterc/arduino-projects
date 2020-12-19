#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library:
Stepper myStepper1(200, D0, D1, D2, D3);
Stepper myStepper2(200, D5, D6, D7, D8);

void setup() {
  // set the speed
  myStepper1.setSpeed(65);
  myStepper2.setSpeed(65);
  // initialize the serial port:
  Serial.begin(9600);
 
}

void loop() {

  //Positive is Clockwise
  //Negative is Counter Clockwise
  //Stepper1 is top
  //Stepper2 is bottom
  for(int i=0;i<50;i++){
    myStepper1.step(-1);
    myStepper2.step(-1);
  }
  delay(1000);
  for(int i=0;i<50;i++){
    myStepper1.step(1);
    myStepper2.step(1);
  }
  delay(1000);
}
