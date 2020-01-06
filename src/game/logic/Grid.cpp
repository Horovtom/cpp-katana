//
// Created by lactosis on 6.1.20.
//

#include <game/logic/Grid.h>

Grid::Grid(int width, int height) {
    this->width = width;
    this->height = height;

    grid.resize(width);
    for (int i = 0; i < width; ++i) {
        grid.at(i).resize(height);
        for (int j = 0; j < height; ++j) {
            grid.at(i).at(j) = BLANK;
        }
    }
}

void Grid::setFieldAt(int x, int y, GridField type) {
    grid.at(x).at(y) = type;
}

GridField Grid::getFieldAt(int x, int y) {
    return grid.at(x).at(y);
}

int Grid::getWidth() {
    return width;
}

int Grid::getHeight() {
    return height;
}

const std::vector<std::vector<GridField>> &Grid::getRef() {
    return grid;
}
