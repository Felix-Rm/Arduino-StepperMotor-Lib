#include <StepperMotor.h>

void Stepper::attach(uint8_t p1,uint8_t p2,uint8_t p3,uint8_t p4){
        pinMode(pin1 = p1,OUTPUT);
        pinMode(pin2 = p2,OUTPUT);
        pinMode(pin3 = p3,OUTPUT);
        pinMode(pin4 = p4,OUTPUT);
}


void Stepper::setSpeed(uint8_t speed){
    this->speed = speed;
}

void Stepper::setStepsPerRevolution(uint16_t full){
    this->full = full;
}

void Stepper::setHoldingTorque(boolean hold){
    this->hold = hold;
}


uint16_t Stepper::getSteps(){
    return this->steps;
}

uint16_t Stepper::getAngle(){
    return map(this->steps,0,this->full,0,360);
}


void Stepper::move(){
    uint8_t dir = this->todo < 0;
    
    while(this->todo != 0){
        for(uint8_t i = 0; i < 4; i++){
            this->step(dir);
            delay(this->speed);
        }
    }

    if(!this->hold)
        torqueOff();
     
    
}

void Stepper::torqueOff(){
    digitalWrite(this->pin1,0);
    digitalWrite(this->pin4,0);
    digitalWrite(this->pin3,0);
    digitalWrite(this->pin2,0);
}

void Stepper::step(uint8_t dir){
    if(dir == CCW){
        digitalWrite(this->pin1,this->clock == 0 ? 1 : 0);
        digitalWrite(this->pin4,this->clock == 1 ? 1 : 0);
        digitalWrite(this->pin3,this->clock == 2 ? 1 : 0);
        digitalWrite(this->pin2,this->clock == 3 ? 1 : 0);
        
    }else{
        digitalWrite(this->pin2,this->clock == 0 ? 1 : 0);
        digitalWrite(this->pin3,this->clock == 1 ? 1 : 0);
        digitalWrite(this->pin4,this->clock == 2 ? 1 : 0);
        digitalWrite(this->pin1,this->clock == 3 ? 1 : 0);
    }  

    this->clock = (this->clock+1) % 4;
    if(this->clock == 0){
        this->steps += dir ? 1 : -1;
        this->steps < 0 ? this->steps += this->full : 0;
        this->steps >= this->full ? this->steps -= this->full : 0;
        if(this->todo > 0) this->todo--;
        if(this->todo < 0) this->todo++;
    }  
}


void Stepper::rotateBySteps(uint16_t steps, uint8_t dir){
    this->todo = steps;
    if (dir == CW) this->todo *= -1;
    if(!this->sync) this->move();
}

void Stepper::rotateByAngle(uint16_t angle, uint8_t dir){
    this->todo = map(angle,0,360,0,this->full);
    if (dir == CW) this->todo *= -1;
    if(!this->sync) this->move();
}


void Stepper::rotateToSteps(uint16_t steps){
    int16_t w1 = steps-this->steps;
    w1 < 0 ? w1 += this->full : 0;
    w1 > this->full ? w1 -= this->full : 0;

    int16_t w2 = this->full - (steps-this->steps);
    w2 < 0 ? w2 += this->full : 0;
    w2 > this->full ? w2 -= this->full : 0;

    if(w1 < w2) this->todo = w1 * -1;
    else this->todo = w2 * 1;
    if(!this->sync) this->move();
}

void Stepper::rotateToAngle(uint16_t angle){
    uint16_t s = map(this->steps,0,this->full,0,360);

    int16_t w1 = angle-s;
    w1 < 0 ? w1 += 360 : 0;
    w1 > 360 ? w1 -= 360 : 0;

    int16_t w2 = 360 - (angle-s);
    w2 < 0 ? w2 += 360 : 0;
    w2 > 360 ? w2 -= 360 : 0;

    if(w1 < w2) this->todo = map(w1,0,360,0,this->full) * -1;
    else this->todo = map(w2,0,360,0,this->full) * 1;
    if(!this->sync) this->move();
}
