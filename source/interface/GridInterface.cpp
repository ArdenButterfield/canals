//
// Created by arden on 2025-08-25.
//

#include "GridInterface.h"

using namespace interface;

 GridInterface::GridInterface(dsp::Grid& g) : grid(g)
{
    startTimerHz (60);
    cellInterfaces.resize (grid.getHeight() * grid.getWidth());
     for (auto& cell : cellInterfaces)
     {
         cell = std::make_unique<CellInterface> ();
         addAndMakeVisible (cell.get());
     }
}
GridInterface::~GridInterface()
{
}
void GridInterface::paint (juce::Graphics& g)
{
     g.fillAll(juce::Colours::tan);
}
void GridInterface::resized()
{
     for (int y = 0; y < grid.getHeight(); ++y) {
         for (int x = 0; x < grid.getWidth(); ++x) {
             cellInterfaces[y * grid.getHeight() + x]->setBounds(y * 10, x * 10, 9, 9);
         }
     }
}

void GridInterface::timerCallback()
{
     repaint();
}




