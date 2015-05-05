//
//  Motor.h
//  FinalProject
//
//  Created by Deeksha Yogish on 4/19/15.
//  Copyright (c) 2015 Deeksha Yogish. All rights reserved.
//

#ifndef MBED_MOTOR_H
#define MBED_MOTOR_H

#include "mbed.h"

class Motor {
public:
    Motor(PinName mouta, PinName moutb, PinName moute);
    void forward(float botSpeed);
    void backward(float botSpeed);
    void stop();

    private:
    DigitalOut _mouta;
    DigitalOut _moutb;
    PwmOut _moute;
};

#endif