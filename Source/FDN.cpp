//
//  FractionalDelay.cpp
//
//  Created by Eric Tarr on 2/6/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//

#include "FDN.hpp"


FDN::FDN(){
}

// Destructor
FDN::~FDN(){
}


float FDN::processSample(float x, int channel){
    
    float y;
    
    float inDL1 = x + fB1[channel];
    float inDL2 = x + fB2[channel];
    float inDL3 = x + fB3[channel];
    float inDL4 = x + fB4[channel];

    
    float outDL1 = fractionalDelay1.processSample(inDL1, channel);
    float outDL2 = fractionalDelay2.processSample(inDL2, channel);
    float outDL3 = fractionalDelay3.processSample(inDL3, channel);
    float outDL4 = fractionalDelay4.processSample(inDL4, channel);
    
    y = (outDL1 + outDL2 + outDL3 + outDL4) * 0.25;
    
    fB1[channel] = (-outDL2 + outDL3) * feedbackGain;
    fB2[channel] = (outDL1 + outDL4) * feedbackGain;
    fB3[channel] = (outDL1 + -outDL4) * feedbackGain;
    fB4[channel] = (-outDL2 + -outDL3) * feedbackGain;
    
    return y;
}

void FDN::setFs(float Fs){
    this->Fs = Fs;
    fractionalDelay1.setFs(Fs);
    fractionalDelay2.setFs(Fs);
}

void FDN::setTime(float timeValue){
    
    this->feedbackGain = timeValue;
}

void FDN::setDepth(float depth){

    this->depth = depth;
    fractionalDelay1.setDepth(depth);
    fractionalDelay2.setDepth(depth);
    fractionalDelay3.setDepth(depth);
    fractionalDelay4.setDepth(depth);
    
}
