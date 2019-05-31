/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//==============================================================================
/**
*/
class GraphicEq2AudioProcessorEditor  : public AudioProcessorEditor
{
public:
    GraphicEq2AudioProcessorEditor (GraphicEq2AudioProcessor&);
    ~GraphicEq2AudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    GraphicEq2AudioProcessor& processor;
    Slider gain1Slider;
    Slider gain2Slider;
    Slider gain3Slider;
    Slider gain4Slider;
    Slider gain5Slider;
    Slider gain6Slider;
    Slider gain7Slider;
    Slider gain8Slider;
    Slider gain9Slider;
    Slider gain10Slider;
public:
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> gain1SliderValue;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> gain2SliderValue;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> gain3SliderValue;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> gain4SliderValue;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> gain5SliderValue;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> gain6SliderValue;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> gain7SliderValue;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> gain8SliderValue;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> gain9SliderValue;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> gain10SliderValue;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GraphicEq2AudioProcessorEditor)
};
