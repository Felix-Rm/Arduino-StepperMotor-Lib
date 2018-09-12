#include <StepperMotor.h>

Stepper myStepper;

void setup(){
  Serial.begin(9600);
  myStepper.attach(8,9,10,11);  //pins from StepperMotor
}

void loop(){
  Serial.println("Turning clockwise!");
  myStepper.stepCW(100,10);   // step 100 steps 'C'lock'W'ise with a speed of 10 (10 = High Speed / 100 = Low Speed)
  
  delay(2000);
  
  Serial.println("Turning counterclockwise!");
  myStepper.stepCCW(100,10);   // step 100 steps 'C'ounter'C'lock'W'ise with a speed of 10 (10 = High Speed / 100 = Low Speed)
  
  delay(2000);
}


