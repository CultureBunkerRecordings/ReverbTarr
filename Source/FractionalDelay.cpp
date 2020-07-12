//
//  FractionalDelay.cpp
//
//  Created by Eric Tarr on 2/6/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//

#include "FractionalDelay.hpp"


FractionalDelay::FractionalDelay(){
}

FractionalDelay::FractionalDelay(float delay,float speed){
    this->delay = delay;
    this->speed = speed;
}

// Destructor
FractionalDelay::~FractionalDelay(){
}


float FractionalDelay::processSample(float x, int channel){
    
    if (delay < 1.f){
        return x;
    }
    else{
        float lfo;
        
        lfo = depth * sin(currentAngle[channel]); //create lfo for modulation
        
        currentAngle[channel] += angleChange;
        
        // limit angle from 0 to 2 pi
        if (currentAngle[channel] > 2.f * M_PI){
            currentAngle[channel] -= 2.f * M_PI;
        }
        
        // Delay Buffer
        // "delay" can be fraction
        int d1 = floor(delay+lfo); //calculate integer index before fraction
        int d2 = d1 + 1; // calculate integer index after fraction
        float g2 = (delay + lfo) - (float)d1; //fraction used as weight for value at indexD1
        float g1 = 1.0f - g2; //fraction used as weight for value at indexD2
        
        int indexD1 = index[channel] - d1; //integer index
        // in the case that d1 is larger than the current index.
        if (indexD1 < 0){
            indexD1 += MAX_BUFFER_SIZE;
        }
        
        // in the case that d2 is larger than the current index
        int indexD2 = index[channel] - d2;
        if (indexD2 < 0){
            indexD2 += MAX_BUFFER_SIZE;
        }
        
        //linear interpolation
        float y = g1 * delayBuffer[indexD1][channel] + g2 * delayBuffer[indexD2][channel];
        
        delayBuffer[index[channel]][channel] = x;
        
        if (index[channel] < MAX_BUFFER_SIZE - 1){
            index[channel]++;
        }
        else{
            index[channel] = 0;
        }
        
        return y;
    }
}

void FractionalDelay::setFs(float Fs){
    this->Fs = Fs;
}


void FractionalDelay::setDelaySamples(float delay){
    if (delay >= 1.f){
        this->delay = delay;
    }
    else{
        this->delay = 0.f;
    }
}


void FractionalDelay::setSpeed(float speed){
    if (speed >= 0.1f && speed <= 10.0f){
        this->speed = speed;
        angleChange = speed * (1.f/Fs) * 2 * M_PI;
    }
}

void FractionalDelay::setDepth(float depth){

    this->depth = depth;
}
