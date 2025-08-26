//
// Created by arden on 2025-08-25.
//

#ifndef CANALS_CELL_H
#define CANALS_CELL_H

#include "CellIdentifiers.h"
#include "juce_core/juce_core.h"


namespace dsp
{

class Cell
{
public:
    Cell();
    ~Cell();
    [[nodiscard]] virtual juce::Identifier getIdentifier() const;

private:
};

}
#endif //CANALS_CELL_H
