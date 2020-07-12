//
//  FractionalDelay.cpp
//
//  Created by Eric Tarr on 2/6/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//

#include "Schroeder.hpp"


Schroeder::Schroeder(){
}


// Destructor
Schroeder::~Schroeder(){
}


float Schroeder::processSample(float x, int channel){
    
    float y;
    
    float outFCF1 = fcf1.processSample(x, channel);
    float outFCF2 = fcf2.processSample(x, channel);
    float outFCF3 = fcf3.processSample(x, channel);
    float outFCF4 = fcf4.processSample(x, channel);
    
    float inAPF1 = (outFCF1 + outFCF2 + outFCF3 + outFCF4)/4;

    float outAPF1 = apf1.processSample(inAPF1, channel);
  
    y = apf2.processSample(outAPF1, channel);
    
    return y;
}

void Schroeder::setFs(float Fs){
    this->Fs = Fs;
    fcf1.setFs(Fs);
    fcf2.setFs(Fs);
    fcf3.setFs(Fs);
    fcf4.setFs(Fs);
    
    apf1.setFs(Fs);
    apf2.setFs(Fs);
}

void Schroeder::setFeedbackGain(float feeedbackGain){
    
    this->feedbackGain = feedbackGain;
    fcf1.setFeedbackGain(feedbackGain);
    fcf2.setFeedbackGain(feedbackGain);
    fcf3.setFeedbackGain(feedbackGain);
    fcf4.setFeedbackGain(feedbackGain);

}

void Schroeder::setDiffusionGain(float diffusionGain){
    
    this->diffusionGain = diffusionGain;
    
    apf1.setFeedbackGain(diffusionGain);
    apf2.setFeedbackGain(diffusionGain);
}


void Schroeder::setDepth(float depth){

    this->depth = depth;
    fcf1.setDepth(depth);
    fcf2.setDepth(depth);
    fcf3.setDepth(depth);
    fcf4.setDepth(depth);
    
    apf1.setDepth(depth);
    apf2.setDepth(depth);
    
}
