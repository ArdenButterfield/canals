//
// Created by arden on 2025-08-25.
//

#ifndef CANALS_GRID_H
#define CANALS_GRID_H

#include <juce_audio_processors/juce_audio_processors.h>
#include <vector>
#include <memory>

#include "Cell.h"

namespace dsp
{

class Grid
{
public:
    Grid(int width, int _height);
    ~Grid();
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate);
    void processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages);
    int getWidth() const;
    int getHeight() const;
private:
    std::vector<std::unique_ptr<Cell>> cells;
    int width, height;
};

}
#endif //CANALS_GRID_H
