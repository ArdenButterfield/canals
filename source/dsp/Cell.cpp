//
// Created by arden on 2025-08-25.
//

#include "Cell.h"

using namespace dsp;

 Cell::Cell()
{

}

 Cell::~Cell()
{

}

bool Cell::isValid() { return true; }

juce::Identifier BlankCell::getIdentifier() const
{
    return CELL_BLANK;
}

juce::Identifier InputCell::getIdentifier() const
{
     return CELL_INPUT;
}
juce::Identifier OutputCell::getIdentifier() const
{
     return CELL_OUTPUT;
}
juce::Identifier VerticalPipeCell::getIdentifier() const
{
     return CELL_VERTICAL_PIPE;
}
juce::Identifier HorizontalPipeCell::getIdentifier() const
{
     return CELL_HORIZONTAL_PIPE;
}

bool InvalidCell::isValid()
{
    return false;
}

juce::Identifier InvalidCell::getIdentifier() const
{
     return identifier;
}



