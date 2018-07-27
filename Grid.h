//
// Created by lactosis on 24.7.18.
//

#ifndef KATANA_GRID_H
#define KATANA_GRID_H

#include <vector>

enum GridCell {
    DOT, CROSS, BLANK, BLACK
};

class Grid {
private:
    unsigned int sizeX, sizeY;
    std::vector<std::vector<GridCell>> grid;

public:
    Grid(unsigned int, unsigned int);
    void setCell(unsigned int, unsigned int, GridCell);
    GridCell getCell(unsigned int, unsigned int);
    unsigned int getSizeX() {return sizeX;}
    unsigned int getSizeY() {return sizeY;}
};


#endif //KATANA_GRID_H
