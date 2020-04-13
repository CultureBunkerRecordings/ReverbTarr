/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AlgoReverbAudioProcessorEditor::AlgoReverbAudioProcessorEditor (AlgoReverbAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    //reverb Time
    reverbTimeSlider.addListener(this);
    reverbTimeSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    reverbTimeSlider.setBounds(50, 30, 100, 100);
    reverbTimeSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    reverbTimeSlider.setRange(0.4f, 0.7f, 0.1f);
    reverbTimeSlider.setValue(0.5f);
    addAndMakeVisible(reverbTimeSlider);
    
    reverbTimeLabel.setText("Time", dontSendNotification);
    reverbTimeLabel.attachToComponent(&reverbTimeSlider, false);
    reverbTimeLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(reverbTimeLabel);
    
    //Modulation
    modulationSlider.addListener(this);
    modulationSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    modulationSlider.setBounds(150, 30, 100, 100);
    modulationSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    modulationSlider.setRange(1., 10.f, 0.1f);
    modulationSlider.setValue(1.0f);
    addAndMakeVisible(modulationSlider);
    
    modulationLabel.setText("Mod", dontSendNotification);
    modulationLabel.attachToComponent(&modulationSlider, false);
    modulationLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(modulationLabel);
    
    
    //wetDry
    wetDrySlider.addListener(this);
    wetDrySlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    wetDrySlider.setBounds(250, 30, 100, 100);
    wetDrySlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    wetDrySlider.setRange(0., 1.f, 0.1f);
    wetDrySlider.setValue(0.5f);
    addAndMakeVisible(wetDrySlider);
    
    wetDryLabel.setText("Wet/Dry", dontSendNotification);
    wetDryLabel.attachToComponent(&wetDrySlider, false);
    wetDryLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(wetDryLabel);
    
    //predelay Time
    predelaySlider.addListener(this);
    predelaySlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    predelaySlider.setBounds(50, 175, 100, 100);
    predelaySlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    predelaySlider.setRange(0.0f, 200.f, 0.1f);
    predelaySlider.setValue(0.0f);
    addAndMakeVisible(predelaySlider);
    
    predelayLabel.setText("Predelay", dontSendNotification);
    predelayLabel.attachToComponent(&predelaySlider, false);
    predelayLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(predelayLabel);
    
    //diffusion
    diffusionSlider.addListener(this);
    diffusionSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    diffusionSlider.setBounds(150, 175, 100, 100);
    diffusionSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    diffusionSlider.setRange(0.2, 1.8f, 0.1f);
    diffusionSlider.setValue(0.5f);
    addAndMakeVisible(diffusionSlider);
    
    diffusionLabel.setText("Diffusion", dontSendNotification);
    diffusionLabel.attachToComponent(&diffusionSlider, false);
    diffusionLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(diffusionLabel);
    
    
    //lpf
    lpfSlider.addListener(this);
    lpfSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    lpfSlider.setBounds(250, 175, 100, 100);
    lpfSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    lpfSlider.setRange(1000., 20000.f, 1.f);
    lpfSlider.setValue(10000.f);
    addAndMakeVisible(lpfSlider);
    
    lpfLabel.setText("LPF", dontSendNotification);
    lpfLabel.attachToComponent(&lpfSlider, false);
    lpfLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(lpfLabel);
}

AlgoReverbAudioProcessorEditor::~AlgoReverbAudioProcessorEditor()
{
}

//==============================================================================
void AlgoReverbAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

//    g.setColour (Colours::white);
//    g.setFont (15.0f);
//    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void AlgoReverbAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void AlgoReverbAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    if(slider == &predelaySlider)
    {
        processor.predelayMilli = predelaySlider.getValue();
    }
    
}
