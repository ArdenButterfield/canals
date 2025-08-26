//
// Created by arden on 2025-08-25.
//

#include "CellInterface.h"

#include "../dsp/Cell.h"

using namespace interface;

 CellInterface::CellInterface()
{

}

CellInterface::~CellInterface() {
}

void CellInterface::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::lavender);
    g.setColour (juce::Colours::darkblue);
    g.drawRect (getLocalBounds());
}

void CellInterface::resized()
{

}

