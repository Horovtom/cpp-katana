//
// Created by lactosis on 24.7.18.
//

#include "Grid.h"

Grid::Grid(unsigned int sizeX, unsigned int sizeY) {
    this->sizeX = sizeX;
    this->sizeY = sizeY;

    for (int i = 0; i < sizeY; ++i) {
        std::vector<GridCell> row;
        for (int j = 0; j < sizeX; ++j) {
             row.emplace_back(BLANK);
        }
        grid.emplace_back(row);
    }
}

void Grid::setCell(unsigned int x, unsigned int y, GridCell val) {
    grid.at(y).at(x) = val;
}

GridCell Grid::getCell(unsigned int x, unsigned int y) {
    return grid.at(y).at(x);
}


