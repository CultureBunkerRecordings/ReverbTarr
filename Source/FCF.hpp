//
//  FractionalDelay.hpp
//
//  Created by Eric Tarr on 2/6/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//

#ifndef FCF_hpp
#define FCF_hpp

#include "FractionalDelay.hpp"

using namespace std;

class FCF {
    
public:
    
    // Constructor function (special function - no return type, name = Class name)
    FCF();
    
    FCF(float delay, float speed);
    
    // Destructor
    ~FCF();
    
    float processSample(float x,int channel);

    void setFs(float Fs);

    void setFeedbackGain(float feedbackGain);
    
    void setDepth(float depth);
    
    
    
private:
    
    float Fs = 48000.f;
    
    FractionalDelay fractionalDelay{240.f, 0.7};

    float feedbackGain = 0.5f;
    
    float fB1[2] = {0.f}; // feedback array for stereo channels;
    
    float depth = 10.0f; // percentage of intensity, control amp of LFO
    
    class Lpf
    {
    public:
        float processSample(float x, int channel)
        {
            float y = x * 0.5f + ff[channel] * 0.5f;
            ff[channel] = x;
            return y;
        }
    private:
        float ff[2] = {0.f};
    };
    
    Lpf lpf;
};



#endif /* FCF_hpp */
