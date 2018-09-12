#include <StepperMotor.h>

void Stepper::attach(uint8_t p1,uint8_t p2,uint8_t p3,uint8_t p4){
        pinMode(pin1 = p1,OUTPUT);
        pinMode(pin2 = p2,OUTPUT);
        pinMode(pin3 = p3,OUTPUT);
        pinMode(pin4 = p4,OUTPUT);
}

void Stepper::stepCW(uint16_t steps,uint16_t speed){
        for (int i = 0; i < steps*4; i++) {
                digitalWrite(pin1,i%4 == 0 ? 1 : 0);
                digitalWrite(pin4,i%4 == 1 ? 1 : 0);
                digitalWrite(pin3,i%4 == 2 ? 1 : 0);
                digitalWrite(pin2,i%4 == 3 ? 1 : 0);
                delay(speed);
        }

        digitalWrite(pin1,0);
        digitalWrite(pin4,0);
        digitalWrite(pin3,0);
        digitalWrite(pin2,0);
}

void Stepper::stepCCW(uint16_t steps,uint16_t speed){
        for (int i = 0; i < steps*4; i++) {
                digitalWrite(pin2,i%4 == 0 ? 1 : 0);
                digitalWrite(pin3,i%4 == 1 ? 1 : 0);
                digitalWrite(pin4,i%4 == 2 ? 1 : 0);
                digitalWrite(pin1,i%4 == 3 ? 1 : 0);
                delay(speed);
        }

        digitalWrite(pin1,0);
        digitalWrite(pin4,0);
        digitalWrite(pin3,0);
        digitalWrite(pin2,0);
}
