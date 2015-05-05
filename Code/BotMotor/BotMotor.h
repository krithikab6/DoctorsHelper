//
//  BotMotor.h
//  FinalProject
//
//  Created by Deeksha Yogish on 4/19/15.
//  Copyright (c) 2015 Deeksha Yogish. All rights reserved.
//

#ifndef MBED_BOTMOTOR_H
#define MBED_BOTMOTOR_H

#include "mbed.h"
#include "Motor.h"

class BotMotor {
public:
    BotMotor(PinName lmouta, PinName lmoutb, PinName lmoute, PinName rmouta, PinName rmoutb,PinName rmoute);
    void moveForward(float BotSpeed);
    void moveBackward(float BotSpeed);
    void turnRight(float BotSpeed);
    void turnLeft(float BotSpeed);
    void turnAround(float BotSpeed);
    void stopBot();
private:
    Motor left;
    Motor right;
};

#endif