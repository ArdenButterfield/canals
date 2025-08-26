//
// Created by arden on 2025-08-25.
//

#include "CellInterface.h"

#include "../dsp/Cell.h"
#include <string>

using namespace interface;

 CellInterface::CellInterface() : isActive (false)
{
     setInterceptsMouseClicks (false, false);

}

CellInterface::~CellInterface() {
}

void CellInterface::paint (juce::Graphics& g)
{
    auto c = isValid ? juce::Colours::lightblue : juce::Colours::pink;
    auto back = isActive ? c : juce::Colours::white;
    g.fillAll(back);
    g.setColour (c);
    g.drawRect (getLocalBounds(), 2);
     auto textcolor = isActive ? juce::Colours::white : c;
     g.setColour (textcolor);
     g.drawText (text, 0,0,getWidth(),getHeight(),juce::Justification::centred,false);
}

void CellInterface::resized()
{

}

