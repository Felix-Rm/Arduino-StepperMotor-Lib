#include "Arduino.h"

#ifndef Stepper_h
#define Stepper_h

#define CCW 1
#define CW 0


class Stepper {


public:
    uint8_t pin1;
    uint8_t pin2;
    uint8_t pin3;
    uint8_t pin4;

    int16_t steps = 0;
    uint16_t full = 512;
    uint8_t clock = 0;
    

    uint8_t speed = 4;
    boolean sync = false;
    boolean hold = false;
    int16_t todo = 0;

    void attach(uint8_t,uint8_t,uint8_t,uint8_t);
    
    void setSpeed(uint8_t);
    void setStepsPerRevolution(uint16_t);
    void setHoldingTorque(boolean);

    uint16_t getSteps();
    uint16_t getAngle();
    
    void rotateBySteps(uint16_t,uint8_t);
    void rotateByAngle(uint16_t,uint8_t);

    void rotateToSteps(uint16_t);
    void rotateToAngle(uint16_t);

    void move();
    void step(uint8_t);
    void torqueOff();
};

#endif
