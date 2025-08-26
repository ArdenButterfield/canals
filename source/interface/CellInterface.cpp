//
// Created by arden on 2025-08-25.
//

#include "CellInterface.h"

#include "../dsp/Cell.h"
#include <string>
#include "GridInterface.h"
using namespace interface;

CellInterface::CellInterface(GridInterface* p, unsigned _x, unsigned _y) : isActive (false), parent(p), x(_x), y(_y)
{
     // setInterceptsMouseClicks (false, false);

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
void CellInterface::mouseUp (const juce::MouseEvent& event)
{
     if (event.mouseWasClicked()) {
         parent->cellClicked(x, y);
     }
}
