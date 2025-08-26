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
    setInterceptsMouseClicks (true, true);
    setWantsKeyboardFocus(true);
}
GridInterface::~GridInterface()
{
}
void GridInterface::paint (juce::Graphics& g)
{
     g.fillAll(juce::Colours::white);
}
void GridInterface::resized()
{
     auto gridsize = 40;
     for (int y = 0; y < grid.getHeight(); ++y) {
         for (int x = 0; x < grid.getWidth(); ++x) {
             cellInterfaces[y * grid.getHeight() + x]->setBounds(x * gridsize, y * gridsize, gridsize - 3, gridsize - 3);
         }
     }
}

void GridInterface::timerCallback()
{
    for (int i = 0; i < grid.cells.size(); ++i) {
         cellInterfaces[i]->isActive = (i == grid.getActiveCell().y * grid.getWidth() + grid.getActiveCell().x);
         cellInterfaces[i]->text = grid.cells[i]->getIdentifier().toString();
         cellInterfaces[i]->isValid = grid.cells[i]->isValid();
    }
    repaint();
}

bool GridInterface::keyPressed (const juce::KeyPress& key)
{
     auto desc = key.getTextDescription();

     auto activecell = grid.getActiveCell();
     if (key == juce::KeyPress::upKey && activecell.y > 0) {
         grid.setActiveCell(activecell.translated (0,-1));
     } else if (key == juce::KeyPress::downKey && activecell.y < grid.getHeight() - 1) {
         grid.setActiveCell (activecell.translated (0, 1));
     } else if (key == juce::KeyPress::leftKey && activecell.x > 0) {
         grid.setActiveCell (activecell.translated (-1, 0));
     } else if (key == juce::KeyPress::rightKey && activecell.x < grid.getWidth() - 1) {
         grid.setActiveCell (activecell.translated (1, 0));
     } else if (key == juce::KeyPress::backspaceKey) {
         grid.setAtActiveCell (dsp::CELL_BLANK);
         if (activecell.x < grid.getWidth() - 1) {
             grid.setActiveCell (activecell.translated (-1, 0));
         }
     }
     std::cout << desc << "\n";
     if (desc.length() == 1) {
         grid.setAtActiveCell (juce::Identifier(desc));
         return true;
     }
     return false;
}