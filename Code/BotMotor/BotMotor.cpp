//
//  BotMotor.cpp
//  FinalProject
//
//  Created by Deeksha Yogish on 4/19/15.
//  Copyright (c) 2015 Deeksha Yogish. All rights reserved.
//

#include "BotMotor.h"

BotMotor::BotMotor(PinName lmouta, PinName lmoutb, PinName lmoute, PinName rmouta, PinName rmoutb,PinName rmoute):left(lmouta, lmoutb, lmoute),right(rmouta, rmoutb, rmoute){
}

void BotMotor::moveForward(float BotSpeed) {
    left.forward(BotSpeed);
    right.forward(BotSpeed);
    return;
}

void BotMotor::moveBackward(float BotSpeed) {
    left.backward(BotSpeed);
    right.backward(BotSpeed);
    return;
}

void BotMotor::turnRight(float BotSpeed) {
    left.forward(BotSpeed);
    right.backward(BotSpeed);
    wait(0.6);
    moveForward(BotSpeed);
    return;
}

void BotMotor::turnLeft(float BotSpeed) {
    right.forward(BotSpeed);
    left.backward(BotSpeed);
    wait(0.6);
    moveForward(BotSpeed);
    return;
}


void BotMotor::stopBot(){
    left.stop();
    right.stop();
    return;
}

void BotMotor::turnAround(float BotSpeed){
    left.forward(BotSpeed);
    right.backward(BotSpeed);    
    wait(1.2);
    stopBot();
    return;
}





