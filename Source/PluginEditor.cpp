/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GraphicEq2AudioProcessorEditor::GraphicEq2AudioProcessorEditor (GraphicEq2AudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    gain1SliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, GAIN_ID1, gain1Slider);
    gain2SliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, GAIN_ID2, gain2Slider);
    gain3SliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, GAIN_ID3, gain3Slider);
    gain4SliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, GAIN_ID4, gain4Slider);
    gain5SliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, GAIN_ID5, gain5Slider);
    gain6SliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, GAIN_ID6, gain6Slider);
    gain7SliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, GAIN_ID7, gain7Slider);
    gain8SliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, GAIN_ID8, gain8Slider);
    gain9SliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, GAIN_ID9, gain9Slider);
    gain10SliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, GAIN_ID10, gain10Slider);
    
    gain1Slider.setRange(-48.0f, 12.0f);
    gain1Slider.setValue(0.0f);
    gain1Slider.setNumDecimalPlacesToDisplay(1);
    gain1Slider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    gain1Slider.setTextBoxStyle(Slider::TextBoxBelow, true, 40, 25);
    addAndMakeVisible(gain1Slider);
    
    gain2Slider.setRange(-48.0f, 12.0f);
    gain2Slider.setValue(0.0f);
    gain2Slider.setNumDecimalPlacesToDisplay(1);
    gain2Slider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    gain2Slider.setTextBoxStyle(Slider::TextBoxBelow, true, 40, 25);
    addAndMakeVisible(gain2Slider);
    
    gain3Slider.setRange(-48.0f, 12.0f);
    gain3Slider.setValue(0.0f);
    gain3Slider.setNumDecimalPlacesToDisplay(1);
    gain3Slider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    gain3Slider.setTextBoxStyle(Slider::TextBoxBelow, true, 40, 25);
    addAndMakeVisible(gain3Slider);
    
    gain4Slider.setRange(-48.0f, 12.0f);
    gain4Slider.setValue(0.0f);
    gain4Slider.setNumDecimalPlacesToDisplay(1);
    gain4Slider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    gain4Slider.setTextBoxStyle(Slider::TextBoxBelow, true, 40, 25);
    addAndMakeVisible(gain4Slider);
    
    gain5Slider.setRange(-48.0f, 12.0f);
    gain5Slider.setValue(0.0f);
    gain5Slider.setNumDecimalPlacesToDisplay(1);
    gain5Slider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    gain5Slider.setTextBoxStyle(Slider::TextBoxBelow, true, 40, 25);
    addAndMakeVisible(gain5Slider);
    addAndMakeVisible(gain5Slider);
    
    gain6Slider.setRange(-48.0f, 12.0f);
    gain6Slider.setValue(0.0f);
    gain6Slider.setNumDecimalPlacesToDisplay(1);
    gain6Slider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    gain6Slider.setTextBoxStyle(Slider::TextBoxBelow, true, 40, 25);
    addAndMakeVisible(gain6Slider);
    
    gain7Slider.setRange(-48.0f, 12.0f);
    gain7Slider.setValue(0.0f);
    gain7Slider.setNumDecimalPlacesToDisplay(1);
    gain7Slider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    gain7Slider.setTextBoxStyle(Slider::TextBoxBelow, true, 40, 25);
    addAndMakeVisible(gain7Slider);
    
    gain8Slider.setRange(-48.0f, 12.0f);
    gain8Slider.setValue(0.0f);
    gain8Slider.setNumDecimalPlacesToDisplay(1);
    gain8Slider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    gain8Slider.setTextBoxStyle(Slider::TextBoxBelow, true, 40, 25);
    addAndMakeVisible(gain8Slider);
    
    gain9Slider.setRange(-48.0f, 12.0f);
    gain9Slider.setValue(0.0f);
    gain9Slider.setNumDecimalPlacesToDisplay(1);
    gain9Slider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    gain9Slider.setTextBoxStyle(Slider::TextBoxBelow, true,40,25);
    addAndMakeVisible(gain9Slider);
   
    
    gain10Slider.setRange(-48.0f, 12.0f);
    gain10Slider.setValue(0.0f);
    gain10Slider.setNumDecimalPlacesToDisplay(1);
    gain10Slider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    gain10Slider.setTextBoxStyle(Slider::TextBoxBelow, true, 40, 25);
    addAndMakeVisible(gain10Slider);
    
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
}

GraphicEq2AudioProcessorEditor::~GraphicEq2AudioProcessorEditor()
{
}

//==============================================================================
void GraphicEq2AudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colours::black);
    g.setColour(juce::Colours::white);
    g.drawFittedText("Linear Phase EQ", getWidth()/2, 10, 100, 25, 12, 1);
    

}

void GraphicEq2AudioProcessorEditor::resized()
{
    gain1Slider.setBounds(0, 20, getWidth()/10, getHeight()-20);
    gain2Slider.setBounds(getWidth()/10, 20, getWidth()/10, getHeight()-20);
    gain3Slider.setBounds(2*(getWidth()/10), 20, getWidth()/10, getHeight()-20);
    gain4Slider.setBounds(3*(getWidth()/10), 20, getWidth()/10, getHeight()-20);
    gain5Slider.setBounds(4*(getWidth()/10), 20, getWidth()/10, getHeight()-20);
    gain6Slider.setBounds(5*(getWidth()/10), 20, getWidth()/10, getHeight()-20);
    gain7Slider.setBounds(6*(getWidth()/10), 20, getWidth()/10, getHeight()-20);
    gain8Slider.setBounds(7*(getWidth()/10), 20, getWidth()/10, getHeight()-20);
    gain9Slider.setBounds(8*(getWidth()/10), 20, getWidth()/10, getHeight()-20);
    gain10Slider.setBounds(9*(getWidth()/10), 20, getWidth()/10, getHeight()-20);
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

