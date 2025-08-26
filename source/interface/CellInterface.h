//
// Created by arden on 2025-08-25.
//

#ifndef CANALS_CELLINTERFACE_H
#define CANALS_CELLINTERFACE_H

#include "juce_gui_basics/juce_gui_basics.h"

namespace interface
{
class GridInterface;


class CellInterface : public juce::Component
{
public:
    CellInterface(GridInterface* p, unsigned x, unsigned y);
    ~CellInterface() override;
    bool isActive;
    juce::String text;
    bool isValid;
private:
    GridInterface* parent;
    unsigned x, y;
    void paint(juce::Graphics& g) override;
    void resized() override;
    void mouseUp(const juce::MouseEvent& event) override;
};
}

#endif //CANALS_CELLINTERFACE_H
