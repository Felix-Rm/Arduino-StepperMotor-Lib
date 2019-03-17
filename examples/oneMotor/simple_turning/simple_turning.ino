// include stepper library
#include <StepperMotor.h>

// motor instance
Stepper motor;

void setup() {
  // open serial port
  Serial.begin(9600);

  // specify the pins of the motor
  motor.attach(8, 9, 10, 11);

  // motor should run at speed 2
  motor.setSpeed(2);
  // motor does 512 steps per revolution
  motor.setStepsPerRevolution(512);
  // holding torque off
  motor.setHoldingTorque(false);

  // turns the motor 45° clockwise and prints stepcount afterwards
  motor.rotateByAngle(45, CW);
  Serial.println(motor.getAngle());
  delay(2000);

  // turns the motor 200 steps counterclockwise and prints the angle of the motorshaft afterwards
  motor.rotateBySteps(200, CCW);
  Serial.println(motor.getAngle());
  delay(2000);

  // turns the motor to the starting position (0steps) and prints the stepcount (should equal 0)
  motor.rotateToSteps(0);
  Serial.println(motor.getSteps());
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
}
