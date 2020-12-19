
#include <Stepper.h>

Stepper myStepper1 = Stepper(200, D1, D2, D3, D4);

void setup() {
  myStepper1.setSpeed(45);

}

void loop() {
  
  myStepper1.step(-100);
  delay(1000);
  myStepper1.step(100);
  delay(1000);
}
