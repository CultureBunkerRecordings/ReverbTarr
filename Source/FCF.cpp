//
//  FractionalDelay.cpp
//
//  Created by Eric Tarr on 2/6/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//

#include "FCF.hpp"


FCF::FCF(){
}

FCF::FCF(float delay, float speed){
    fractionalDelay.setDelaySamples(delay);
    fractionalDelay.setSpeed(speed);
}

// Destructor
FCF::~FCF(){
}


float FCF::processSample(float x, int channel){
    
    float y;
    
    float inDL1 = x + (-feedbackGain) * fB1[channel]; 
    
    float outDL1 = fractionalDelay.processSample(inDL1, channel);
  
    y = outDL1;
    
    fB1[channel] = lpf.processSample(outDL1, channel);
    
    return y;
}

void FCF::setFs(float Fs){
    this->Fs = Fs;
    fractionalDelay.setFs(Fs);
}

void FCF::setFeedbackGain(float feeedbackGain){
    
    this->feedbackGain = feedbackGain;
}

void FCF::setDepth(float depth){

    this->depth = depth;
    fractionalDelay.setDepth(depth);
    
}
