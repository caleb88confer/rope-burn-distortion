/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class RopeburndistortionAudioProcessorEditor  : public juce::AudioProcessorEditor
//private juce::Slider::Listener
{
public:
    RopeburndistortionAudioProcessorEditor (RopeburndistortionAudioProcessor&);
    ~RopeburndistortionAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    RopeburndistortionAudioProcessor& audioProcessor;
    
    juce::Slider driveControl;
    juce::Slider rangeControl;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> driveSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> rangeSliderAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RopeburndistortionAudioProcessorEditor)
};
