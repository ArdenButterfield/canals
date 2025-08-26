//
// Created by arden on 2025-08-25.
//

#include "Grid.h"

using namespace dsp;

Grid::Grid (int _width, int _height) : width(_width), height(_height)
{
    cells.resize (width * height);
}

Grid::~Grid()
{

}

void Grid::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{

}

void Grid::processBlock (juce::AudioBuffer<float>& buffer,
                                              juce::MidiBuffer& midiMessages)
{

}
int Grid::getWidth() const
{
    return width;
}

int Grid::getHeight() const
{
    return height;
}

