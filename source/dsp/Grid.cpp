//
// Created by arden on 2025-08-25.
//

#include "Grid.h"

using namespace dsp;

Grid::Grid (unsigned _width, unsigned _height) : width(_width), height(_height)
{
    activeCell.x = 0; activeCell.y = 0;
    cells.resize (height * width);
    for (auto & cell : cells) {
        cell = std::make_unique<BlankCell> ();
    }
}

Grid::~Grid()
= default;

void Grid::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{

}

void Grid::processBlock (juce::AudioBuffer<float>& buffer,
                                              juce::MidiBuffer& midiMessages)
{

}
unsigned Grid::getWidth() const
{
    return width;
}

unsigned Grid::getHeight() const
{
    return height;
}

void Grid::setCellAt (unsigned x, unsigned y, const juce::Identifier& id)
{
    if (id == CELL_BLANK) {
        cells[y * width + x] = std::make_unique<BlankCell>();
    } else if (id == CELL_INPUT) {
        cells[y * width + x] = std::make_unique<InputCell>();
    } else {
        cells[y * width + x] = std::make_unique<InvalidCell>(id);
    }
}
void Grid::setAtActiveCell (const juce::Identifier& id)
{
    setCellAt (activeCell.x, activeCell.y, id);
}

juce::Point<unsigned> Grid::getActiveCell()
{
    return activeCell;
}

void Grid::setActiveCell (juce::Point<unsigned> p)
{
    if (p.x < width && p.y < height) {
        activeCell = p;
    }
}