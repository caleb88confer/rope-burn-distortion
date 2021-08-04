/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
RopeburndistortionAudioProcessorEditor::RopeburndistortionAudioProcessorEditor (RopeburndistortionAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (500, 400);
    
//    driveControl.setValue(0);
    driveControl.setRange(0.0f, 1.0f, 0.001f);
    driveControl.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    driveControl.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 50);
    
//    rangeControl.setValue(0);
    rangeControl.setRange(0.0f, 1.0f, 0.001f);
    rangeControl.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    rangeControl.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 50);
    
    driveSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "drive", driveControl);
    rangeSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "range", rangeControl);
    
    addAndMakeVisible(driveControl);
    addAndMakeVisible(rangeControl);
    
}


RopeburndistortionAudioProcessorEditor::~RopeburndistortionAudioProcessorEditor()
{
}

//==============================================================================
void RopeburndistortionAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colour (255, 180, 95));
    
    
    g.setColour (juce::Colours::white);
    g.setFont (30.0f);
    g.drawFittedText ("Rope Burn", getLocalBounds(), juce::Justification::centredTop, 1);
    
    g.drawText("Drive", getWidth()/2 -161, getHeight()/2 -100, 100, 30, juce::Justification::centred);
    g.drawText("Range", getWidth()/2 +41, getHeight()/2 -100, 100, 30, juce::Justification::centred);
}

void RopeburndistortionAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    driveControl.setBounds (getWidth()/2 -200, getHeight()/2 -50, 180, 180);
    rangeControl.setBounds (getWidth()/2, getHeight()/2 -50, 180, 180);
}
