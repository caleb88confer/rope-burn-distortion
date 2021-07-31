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
    setSize (400, 300);
    
    driveControl.setValue(0);
    driveControl.setRange(0.0, 1.0);
    driveControl.setSliderStyle(juce::Slider::LinearBarVertical);
    
    rangeControl.setValue(0);
    rangeControl.setRange(0.0, 1.0);
    rangeControl.setSliderStyle(juce::Slider::LinearBarVertical);
    
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
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
//    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void RopeburndistortionAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    driveControl.setBounds (40, 30, 20, getHeight() -60);
    rangeControl.setBounds (140, 30, 20, getHeight() -60);
}
