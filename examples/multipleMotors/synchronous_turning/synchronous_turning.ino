#include <StepperSync.h>
#include <StepperMotor.h>

Stepper stepper1;
Stepper stepper2;
StepperSync sync;

void setup() {
  // attach steppers to pins
  stepper1.attach(8, 9, 10, 11);
  stepper2.attach(4, 5, 6, 7);

  // set properties of stepper, stepper1 runs twice as fast as stepper2
  stepper1.setStepsPerRevolution(512);
  stepper1.setHoldingTorque(false);
  stepper1.setSpeed(2);

  stepper2.setStepsPerRevolution(512);
  stepper2.setHoldingTorque(false);
  stepper2.setSpeed(4);

  // add steppers to sync
  sync.add(&stepper1);
  sync.add(&stepper2);
}

void loop() {
  // say where steppers need to rotate
  stepper1.rotateToAngle(90);
  stepper2.rotateToAngle(90);

  // run (stepper1 will be done faster because of the defined speed difrence)
  sync.runAll();

  // roatate back to 0
  stepper1.rotateToAngle(0);
  stepper2.rotateToAngle(0);

  sync.runAll();
}