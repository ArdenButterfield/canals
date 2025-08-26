//
// Created by arden on 2025-08-25.
//

#ifndef CANALS_CELLINTERFACE_H
#define CANALS_CELLINTERFACE_H

#include "juce_gui_basics/juce_gui_basics.h"

namespace interface
{
class CellInterface : public juce::Component
{
public:
    CellInterface();
    ~CellInterface() override;
private:
    void paint(juce::Graphics& g) override;
    void resized() override;
};
}

#endif //CANALS_CELLINTERFACE_H
