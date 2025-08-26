//
// Created by arden on 2025-08-25.
//

#ifndef CANALS_CELL_H
#define CANALS_CELL_H

#include <utility>

#include "CellIdentifiers.h"
#include "juce_core/juce_core.h"

#include <fontconfig/fontconfig.h>

namespace dsp
{

class Cell
{
public:
    Cell();
    virtual ~Cell();
    [[nodiscard]] virtual juce::Identifier getIdentifier() const = 0;
    [[nodiscard]] virtual bool isValid();

private:
};

class BlankCell : public Cell
{
public:
    BlankCell() : Cell () {}
    [[nodiscard]] juce::Identifier getIdentifier() const override;
};

class InputCell : public Cell
{
public:
    InputCell() : Cell() {}
    [[nodiscard]] juce::Identifier getIdentifier() const override;
};
class OutputCell : public Cell
{
public:
    OutputCell() : Cell() {}
    [[nodiscard]] juce::Identifier getIdentifier() const override;
};
class HorizontalPipeCell : public Cell
{
public:
    HorizontalPipeCell() : Cell() {}
    [[nodiscard]] juce::Identifier getIdentifier() const override;
};
class VerticalPipeCell : public Cell
{
public:
    VerticalPipeCell() : Cell() {}
    [[nodiscard]] juce::Identifier getIdentifier() const override;
};

class InvalidCell : public Cell
{
public:
    explicit InvalidCell(juce::Identifier id) : Cell (), identifier (std::move(id)) {}
    bool isValid() override;
    [[nodiscard]] juce::Identifier getIdentifier() const override;
private:
    juce::Identifier identifier;
};

}
#endif //CANALS_CELL_H
