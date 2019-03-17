#include "Arduino.h"
#include "StepperMotor.h"

#ifndef StepperSync_h
#define StepperSync_h

class StepperSync {

public:
  Stepper *steppers[8];
  uint32_t clock = 0;

  void add(Stepper *);
  void remove(Stepper *);

  boolean run();
  void runAll();
};

#endif
