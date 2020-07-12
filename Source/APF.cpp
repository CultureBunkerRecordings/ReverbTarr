//
//  FractionalDelay.cpp
//
//  Created by Eric Tarr on 2/6/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//

#include "APF.hpp"


APF::APF(){
}

APF::APF(float delay, float speed){
    fractionalDelay.setDelaySamples(delay);
    fractionalDelay.setSpeed(speed);
}

// Destructor
APF::~APF(){
}


float APF::processSample(float x, int channel){
    
    float y;
    
    float inDL1 = x +  (-feedbackGain) * fB1[channel]; // sum 1. add scaled feedback path to input
    
    float outDL1 = fractionalDelay.processSample(inDL1, channel); // delay the resulting signal
  
    y = (inDL1 * feedbackGain) + outDL1; //sum 2. add scaled feedforward path to output of delayline
    
    fB1[channel] = outDL1; // recursive feedback
    
    return y;
}

void APF::setFs(float Fs){
    this->Fs = Fs;
    fractionalDelay.setFs(Fs);
}

void APF::setFeedbackGain(float feeedbackGain){
    
    this->feedbackGain = feedbackGain;
}

void APF::setDepth(float depth){

    this->depth = depth;
    fractionalDelay.setDepth(depth);
    
}
