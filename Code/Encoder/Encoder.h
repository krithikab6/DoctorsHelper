#ifndef MBED_ENCODER_H
#define MBED_ENCODER_H
 
#include "mbed.h"

class Encoder {
public:
    Encoder(PinName eouta, PinName eoutb);
    void forward(int);
    void startEncoding();
    void stopBot();
    int read();
private:  
    DigitalIn _eouta;
    DigitalIn _eoutb;
    int encoderCount;
};
 
#endif