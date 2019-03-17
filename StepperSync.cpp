#include <StepperSync.h>

void StepperSync::add(Stepper* stepper){
    for(uint8_t i = 0; i < 8; i++){
        if(this->steppers[i] == nullptr){
            this->steppers[i] = stepper;
            stepper->sync = true;
            return;
        }
    }
}

void StepperSync::remove(Stepper* stepper){
    for(uint8_t i = 0; i < 8; i++){
        if(this->steppers[i] == stepper){
            this->steppers[i] = nullptr;
            stepper->sync = false;
            return;
        }
    }
}

void StepperSync::runAll(){
    while(!this->run());
}

boolean StepperSync::run(){
    boolean done = true;

    for(uint8_t i = 0; i < 8; i++){
        if(this->steppers[i] != nullptr && this->steppers[i]->todo != 0){
            if(this->clock % this->steppers[i]->speed == 0)
                this->steppers[i]->step(this->steppers[i]->todo < 0);
            done = false;
        }
    }

    
    /*
    for(uint8_t i = 0; i < 8; i++){
        if(this->steppers[i] != nullptr && this->steppers[i]->todo != 0){
            if(this->clock % this->steppers[i]->speed == 0){
                    this->steppers[i]->step(this->steppers[i]->todo < 0);
                    if(this->steppers[i]->todo == 0 && !this->steppers[i]->hold)
                        this->steppers[i]->torqueOff();
            }
            done = false;
        }
    }*/
    
    delay(1);
    this->clock++;

    if(done){ 
        this->clock = 0;
        for(uint8_t i = 0; i < 8; i++){
            if(this->steppers[i] != nullptr && !this->steppers[i]->hold){
            this->steppers[i]->torqueOff();
            }
        }
    }
    return done;
}