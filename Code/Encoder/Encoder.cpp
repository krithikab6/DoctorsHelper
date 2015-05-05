#include "Encoder.h"
 
Encoder::Encoder(PinName eouta, PinName eoutb) : _eouta(eouta),_eoutb(eoutb){
//    _eouta = 0;
//    _eoutb = 0;
}
 
void Encoder::forward(int lidarReading) {
    encoderCount = (int)((float)lidarReading*0.3789+0.5);
    printf("Count = %d\n\r",encoderCount);
    startEncoding();
    return;
}

void Encoder::startEncoding(){
    Serial pc(USBTX, USBRX); //Initalise PC serial comms
    int currenta = 0, currentb = 0;
    while(encoderCount>0){
           currenta = _eouta;
           currentb = _eoutb;
            if(currenta && currentb){
                encoderCount--;
                printf("Count in encoding = %d\n\r",encoderCount);
                fflush(stdout);
            }
    }
    pc.printf("Stopping bot");
    return;
}


int Encoder::read(){
    return(_eouta && _eoutb);   
}




