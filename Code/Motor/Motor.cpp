//
//  Motor.cpp
//  FinalProject
//
//  Created by Deeksha Yogish on 4/19/15.
//  Copyright (c) 2015 Deeksha Yogish. All rights reserved.
//

#include "Motor.h"

Motor::Motor(PinName mouta, PinName moutb, PinName moute) : _mouta(mouta),_moutb(moutb),_moute(moute){
    _mouta = 1;
    _moutb = 1;
    _moute.period(0.01);
//    printf("In motor constructor");
}

void Motor::forward(float botSpeed){
    _mouta = 1;
    _moutb = 0;
    _moute.write(botSpeed);
//    _moute.write(0.5);
//        printf("In motor forward");
}

void Motor::backward(float botSpeed){
    _mouta = 0;
    _moutb = 1;
    _moute.write(botSpeed);
}

void Motor::stop(){
    _mouta = 0;
    _moutb = 0;
    _moute.write(0);
}