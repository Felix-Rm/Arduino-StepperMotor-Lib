#include "Arduino.h"

#ifndef Stepper_h
#define Stepper_h


class Stepper {

private:
uint8_t pin1;
uint8_t pin2;
uint8_t pin3;
uint8_t pin4;

public:
void attach(uint8_t,uint8_t,uint8_t,uint8_t);
void stepCW(uint16_t,uint16_t);
void stepCCW(uint16_t,uint16_t);


};

#endif
