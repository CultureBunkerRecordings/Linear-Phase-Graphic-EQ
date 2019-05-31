/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GraphicEq2AudioProcessor::GraphicEq2AudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ), treeState(*this, nullptr, "PARAMETERS", createParameterLayout()),write(0), read(0)
#endif
{

}

AudioProcessorValueTreeState::ParameterLayout GraphicEq2AudioProcessor::createParameterLayout()
{
    std::vector <std::unique_ptr<RangedAudioParameter>> params;
    
    NormalisableRange<float> range(-48.0f, 12.0f);
    
    auto gainParam1 = std::make_unique<AudioParameterFloat>(GAIN_ID1, GAIN_NAME1, range, 0.0f);
    auto gainParam2 = std::make_unique<AudioParameterFloat>(GAIN_ID2, GAIN_NAME2, range, 0.0f);
    auto gainParam3 = std::make_unique<AudioParameterFloat>(GAIN_ID3, GAIN_NAME3, range, 0.0f);
    auto gainParam4 = std::make_unique<AudioParameterFloat>(GAIN_ID4, GAIN_NAME4, range, 0.0f);
    auto gainParam5 = std::make_unique<AudioParameterFloat>(GAIN_ID5, GAIN_NAME5, range, 0.0f);
    auto gainParam6 = std::make_unique<AudioParameterFloat>(GAIN_ID6, GAIN_NAME6, range, 0.0f);
    auto gainParam7 = std::make_unique<AudioParameterFloat>(GAIN_ID7, GAIN_NAME7, range, 0.0f);
    auto gainParam8 = std::make_unique<AudioParameterFloat>(GAIN_ID8, GAIN_NAME8, range, 0.0f);
    auto gainParam9 = std::make_unique<AudioParameterFloat>(GAIN_ID9, GAIN_NAME9, range, 0.0f);
    auto gainParam10 = std::make_unique<AudioParameterFloat>(GAIN_ID10, GAIN_NAME10, range, 0.0f);
    
    params.push_back(std::move(gainParam1));
    params.push_back(std::move(gainParam2));
    params.push_back(std::move(gainParam3));
    params.push_back(std::move(gainParam4));
    params.push_back(std::move(gainParam5));
    params.push_back(std::move(gainParam6));
    params.push_back(std::move(gainParam7));
    params.push_back(std::move(gainParam8));
    params.push_back(std::move(gainParam9));
    params.push_back(std::move(gainParam10));
    
    return { params.begin(), params.end() };
}

GraphicEq2AudioProcessor::~GraphicEq2AudioProcessor()
{
}

//==============================================================================
const String GraphicEq2AudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool GraphicEq2AudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool GraphicEq2AudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool GraphicEq2AudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double GraphicEq2AudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int GraphicEq2AudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int GraphicEq2AudioProcessor::getCurrentProgram()
{
    return 0;
}

void GraphicEq2AudioProcessor::setCurrentProgram (int index)
{
}

const String GraphicEq2AudioProcessor::getProgramName (int index)
{
    return {};
}

void GraphicEq2AudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void GraphicEq2AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    write = 0;
    read = 0;
    
    auto channels = static_cast<uint32> (jmin (getMainBusNumInputChannels(), getMainBusNumOutputChannels()));
    
    scratchBuffer1.setSize(getTotalNumInputChannels(), samplesPerBlock);
    scratchBuffer2.setSize(getTotalNumInputChannels(), samplesPerBlock);
    scratchBuffer3.setSize(getTotalNumInputChannels(), samplesPerBlock);
    scratchBuffer4.setSize(getTotalNumInputChannels(), samplesPerBlock);
    scratchBuffer5.setSize(getTotalNumInputChannels(), samplesPerBlock);
    scratchBuffer6.setSize(getTotalNumInputChannels(), samplesPerBlock);
    scratchBuffer7.setSize(getTotalNumInputChannels(), samplesPerBlock);
    scratchBuffer8.setSize(getTotalNumInputChannels(), samplesPerBlock);
    scratchBuffer9.setSize(getTotalNumInputChannels(), samplesPerBlock);

    //
    delayLine10.setSize(getTotalNumInputChannels(), delayLength);
    delayLine10.clear();
    
    delayLine9.setSize(getTotalNumInputChannels(), delayLength);
    delayLine9.clear();
    
    delayLine8.setSize(getTotalNumInputChannels(), delayLength);
    delayLine8.clear();
    
    delayLine7.setSize(getTotalNumInputChannels(), delayLength);
    delayLine7.clear();
    
    delayLine6.setSize(getTotalNumInputChannels(), delayLength);
    delayLine6.clear();
   
    delayLine5.setSize(getTotalNumInputChannels(), delayLength);
    delayLine5.clear();
    
    delayLine4.setSize(getTotalNumInputChannels(), delayLength);
    delayLine4.clear();
    
    delayLine3.setSize(getTotalNumInputChannels(), delayLength);
    delayLine3.clear();
 
    delayLine2.setSize(getTotalNumInputChannels(), delayLength);
    delayLine2.clear();
   
    delayLine1.setSize(getTotalNumInputChannels(), delayLength);
    delayLine1.clear();
    
    dsp::ProcessSpec spec { sampleRate, static_cast<uint32> (samplesPerBlock), channels };
    
    convolution10.prepare (spec);
    convolution10.reset();
    
    convolution9.prepare (spec);
    convolution9.reset();
    
    convolution8.prepare (spec);
    convolution8.reset();
    
    convolution7.prepare (spec);
    convolution7.reset();
    
    convolution6.prepare (spec);
    convolution6.reset();
    
    convolution5.prepare (spec);
    convolution5.reset();
   
    convolution4.prepare (spec);
    convolution4.reset();
   
    convolution3.prepare (spec);
    convolution3.reset();

    convolution2.prepare (spec);
    convolution2.reset();
  
    convolution1.prepare (spec);
    convolution1.reset();
    
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void GraphicEq2AudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool GraphicEq2AudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void GraphicEq2AudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();
 
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
        
    int writestart = write;
    int readstart = read;
    
    AudioSampleBuffer tmpBuffer1 (scratchBuffer1.getArrayOfWritePointers(), buffer.getNumChannels(), buffer.getNumSamples());
     AudioSampleBuffer tmpBuffer2 (scratchBuffer2.getArrayOfWritePointers(), buffer.getNumChannels(), buffer.getNumSamples());
    AudioSampleBuffer tmpBuffer3 (scratchBuffer3.getArrayOfWritePointers(), buffer.getNumChannels(), buffer.getNumSamples());
    AudioSampleBuffer tmpBuffer4 (scratchBuffer4.getArrayOfWritePointers(), buffer.getNumChannels(), buffer.getNumSamples());
    AudioSampleBuffer tmpBuffer5 (scratchBuffer5.getArrayOfWritePointers(), buffer.getNumChannels(), buffer.getNumSamples());
    AudioSampleBuffer tmpBuffer6 (scratchBuffer6.getArrayOfWritePointers(), buffer.getNumChannels(), buffer.getNumSamples());
    AudioSampleBuffer tmpBuffer7 (scratchBuffer7.getArrayOfWritePointers(), buffer.getNumChannels(), buffer.getNumSamples());
    AudioSampleBuffer tmpBuffer8 (scratchBuffer8.getArrayOfWritePointers(), buffer.getNumChannels(), buffer.getNumSamples());
    AudioSampleBuffer tmpBuffer9 (scratchBuffer9.getArrayOfWritePointers(), buffer.getNumChannels(), buffer.getNumSamples());
    
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        write = writestart;
        read = readstart;
        
        float* delayLineData10 = delayLine10.getWritePointer(channel);
        float* delayLineData9 = delayLine9.getWritePointer(channel);
        float* delayLineData8 = delayLine8.getWritePointer(channel);
        float* delayLineData7 = delayLine7.getWritePointer(channel);
        float* delayLineData6 = delayLine6.getWritePointer(channel);
        float* delayLineData5 = delayLine5.getWritePointer(channel);
        float* delayLineData4 = delayLine4.getWritePointer(channel);
        float* delayLineData3 = delayLine3.getWritePointer(channel);
        float* delayLineData2 = delayLine2.getWritePointer(channel);
        float* delayLineData1 = delayLine1.getWritePointer(channel);

        
        auto gain1 = treeState.getRawParameterValue(GAIN_ID1);
        auto gain2 = treeState.getRawParameterValue(GAIN_ID2);
        auto gain3 = treeState.getRawParameterValue(GAIN_ID3);
        auto gain4 = treeState.getRawParameterValue(GAIN_ID4);
        auto gain5 = treeState.getRawParameterValue(GAIN_ID5);
        auto gain6 = treeState.getRawParameterValue(GAIN_ID6);
        auto gain7 = treeState.getRawParameterValue(GAIN_ID7);
        auto gain8 = treeState.getRawParameterValue(GAIN_ID8);
        auto gain9 = treeState.getRawParameterValue(GAIN_ID9);
        auto gain10 = treeState.getRawParameterValue(GAIN_ID10);
        
        // updateParameters();
        
        for (int sample = 0; sample < buffer.getNumSamples(); sample++)
        { // for each sample
            delayLineData10[write] = filterCoefs10[read]* Decibels::decibelsToGain(*gain10);
            delayLineData9[write] = filterCoefs9[read]* Decibels::decibelsToGain(*gain9);
            delayLineData8[write] = filterCoefs8[read]* Decibels::decibelsToGain(*gain8);
            delayLineData7[write] = filterCoefs7[read]* Decibels::decibelsToGain(*gain7);
            delayLineData6[write] = filterCoefs6[read]* Decibels::decibelsToGain(*gain6);
            delayLineData5[write] = filterCoefs5[read]* Decibels::decibelsToGain(*gain5);
            delayLineData4[write] = filterCoefs4[read]* Decibels::decibelsToGain(*gain4);
            delayLineData3[write] = filterCoefs3[read]* Decibels::decibelsToGain(*gain3);
            delayLineData2[write] = filterCoefs2[read]* Decibels::decibelsToGain(*gain2);
            delayLineData1[write] = filterCoefs1[read] * Decibels::decibelsToGain(*gain1);

            ++write;
            write %= delayLength;
            
            ++read;
            read %= delayLength;
        }
        tmpBuffer1.copyFrom(channel, 0, buffer, channel, 0, buffer.getNumSamples());
        tmpBuffer2.copyFrom(channel, 0, buffer, channel, 0, buffer.getNumSamples());
        tmpBuffer3.copyFrom(channel, 0, buffer, channel, 0, buffer.getNumSamples());
        tmpBuffer4.copyFrom(channel, 0, buffer, channel, 0, buffer.getNumSamples());
        tmpBuffer5.copyFrom(channel, 0, buffer, channel, 0, buffer.getNumSamples());
        tmpBuffer6.copyFrom(channel, 0, buffer, channel, 0, buffer.getNumSamples());
        tmpBuffer7.copyFrom(channel, 0, buffer, channel, 0, buffer.getNumSamples());
        tmpBuffer8.copyFrom(channel, 0, buffer, channel, 0, buffer.getNumSamples());
        tmpBuffer9.copyFrom(channel, 0, buffer, channel, 0, buffer.getNumSamples());

    }
   
    dsp::AudioBlock<float> block10(buffer);
    dsp::AudioBlock<float> block9(tmpBuffer1);
    dsp::AudioBlock<float> block8(tmpBuffer2);
    dsp::AudioBlock<float> block7(tmpBuffer3);
    dsp::AudioBlock<float> block6(tmpBuffer4);
    dsp::AudioBlock<float> block5(tmpBuffer5);
    dsp::AudioBlock<float> block4(tmpBuffer6);
    dsp::AudioBlock<float> block3(tmpBuffer7);
    dsp::AudioBlock<float> block2(tmpBuffer8);
    dsp::AudioBlock<float> block1(tmpBuffer9);

    convolution10.copyAndLoadImpulseResponseFromBuffer(delayLine10, getSampleRate(), true, false, false, 0);
    convolution9.copyAndLoadImpulseResponseFromBuffer(delayLine9, getSampleRate(), true, false, false, 0);
    convolution8.copyAndLoadImpulseResponseFromBuffer(delayLine8, getSampleRate(), true, false, false, 0);
    convolution7.copyAndLoadImpulseResponseFromBuffer(delayLine7, getSampleRate(), true, false, false, 0);
    convolution6.copyAndLoadImpulseResponseFromBuffer(delayLine6, getSampleRate(), true, false, false, 0);
    convolution5.copyAndLoadImpulseResponseFromBuffer(delayLine5, getSampleRate(), true, false, false, 0);
    convolution4.copyAndLoadImpulseResponseFromBuffer(delayLine4, getSampleRate(), true, false, false, 0);
    convolution3.copyAndLoadImpulseResponseFromBuffer(delayLine3, getSampleRate(), true, false, false, 0);
    convolution2.copyAndLoadImpulseResponseFromBuffer(delayLine2, getSampleRate(), true, false, false, 0);
    convolution1.copyAndLoadImpulseResponseFromBuffer(delayLine1, getSampleRate(), true, false, false, 0);

    dsp::AudioBlock<float>& block10back = block10;
    dsp::AudioBlock<float>& block9back = block9;
    dsp::AudioBlock<float>& block8back = block8;
    dsp::AudioBlock<float>& block7back = block7;
    dsp::AudioBlock<float>& block6back = block6;
    dsp::AudioBlock<float>& block5back = block5;
    dsp::AudioBlock<float>& block4back = block4;
    dsp::AudioBlock<float>& block3back = block3;
    dsp::AudioBlock<float>& block2back = block2;
    dsp::AudioBlock<float>& block1back = block1;

    convolution10.process(dsp::ProcessContextReplacing<float>(block10));
    block10back = dsp::ProcessContextReplacing<float> (block10).getOutputBlock();
    convolution9.process(dsp::ProcessContextReplacing<float>(block9));
    block9back = dsp::ProcessContextReplacing<float> (block9).getOutputBlock();
    convolution8.process(dsp::ProcessContextReplacing<float>(block8));
    block8back = dsp::ProcessContextReplacing<float> (block8).getOutputBlock();
    convolution7.process(dsp::ProcessContextReplacing<float>(block7));
    block7back = dsp::ProcessContextReplacing<float> (block7).getOutputBlock();
    convolution6.process(dsp::ProcessContextReplacing<float>(block6));
    block6back = dsp::ProcessContextReplacing<float> (block6).getOutputBlock();
    convolution5.process(dsp::ProcessContextReplacing<float>(block5));
    block5back = dsp::ProcessContextReplacing<float> (block5).getOutputBlock();
    convolution4.process(dsp::ProcessContextReplacing<float>(block4));
    block4back = dsp::ProcessContextReplacing<float> (block4).getOutputBlock();
    convolution3.process(dsp::ProcessContextReplacing<float>(block3));
    block3back = dsp::ProcessContextReplacing<float> (block3).getOutputBlock();
    convolution2.process(dsp::ProcessContextReplacing<float>(block2));
    block2back = dsp::ProcessContextReplacing<float> (block2).getOutputBlock();
    convolution1.process(dsp::ProcessContextReplacing<float>(block1));
    block1back = dsp::ProcessContextReplacing<float> (block1).getOutputBlock();
    
    dsp::AudioBlock<float> block(block10);
    block = block.add(block9);
    block = block.add(block8);
    block = block.add(block7);
    block = block.add(block6);
    block = block.add(block5);
    block = block.add(block4);
    block = block.add(block3);
    block = block.add(block2);
    block = block.add(block1);

                // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
        // ..do something to the data...
    
}

void GraphicEq2AudioProcessor::updateParameters()
{
    
}
//==============================================================================
bool GraphicEq2AudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* GraphicEq2AudioProcessor::createEditor()
{
    return new GraphicEq2AudioProcessorEditor (*this);
}

//==============================================================================
void GraphicEq2AudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void GraphicEq2AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}



//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new GraphicEq2AudioProcessor();
}
