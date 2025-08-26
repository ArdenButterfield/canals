//
// Created by arden on 2025-08-25.
//

#ifndef CANALS_GRIDINTERFACE_H
#define CANALS_GRIDINTERFACE_H

#include "juce_gui_basics/juce_gui_basics.h"
#include "../dsp/Grid.h"
#include "CellInterface.h"
#include <memory>
#include <vector>

namespace interface
{
class GridInterface : public juce::Component, public juce::Timer
{
public:
    GridInterface(dsp::Grid&);
    ~GridInterface();
private:
    void paint (juce::Graphics& g) override;
    void resized() override;
    void timerCallback() override;
    bool keyPressed(const juce::KeyPress& key) override;
    dsp::Grid& grid;
    std::vector<std::unique_ptr<CellInterface>> cellInterfaces;
};

}
#endif //CANALS_GRIDINTERFACE_H
