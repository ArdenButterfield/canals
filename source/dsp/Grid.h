//
// Created by arden on 2025-08-25.
//

#ifndef CANALS_GRID_H
#define CANALS_GRID_H

#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_graphics/juce_graphics.h>
#include <vector>
#include <memory>
#include "Cell.h"

namespace dsp
{

class Grid
{
public:
    Grid(unsigned _width, unsigned _height);
    ~Grid();
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate);
    void processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages);
    [[nodiscard]] unsigned getWidth() const;
    [[nodiscard]] unsigned getHeight() const;
    void setCellAt(unsigned x, unsigned y, const juce::Identifier& id);
    void setAtActiveCell(const juce::Identifier& id);
    juce::Point<unsigned> getActiveCell();
    void setActiveCell(juce::Point<unsigned>);
    std::vector<std::unique_ptr<Cell>> cells;
private:
    unsigned width, height;
    juce::Point<unsigned> activeCell;
};

}
#endif //CANALS_GRID_H
