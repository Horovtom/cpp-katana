//
// Created by lactosis on 24.7.18.
//

#ifndef KATANA_GRID_H
#define KATANA_GRID_H

#include <vector>

enum GridCell {
    BLANK, BLACK, CROSS, DOT
};

class Grid {
private:
    unsigned int sizeX, sizeY;
    std::vector<std::vector<GridCell>> grid;

public:
    Grid(unsigned int, unsigned int);
    void setCell(unsigned int, unsigned int, GridCell);
    GridCell getCell(unsigned int, unsigned int);

    unsigned int getWidth() { return sizeX; }

    unsigned int getHeight() { return sizeY; }

    /**
     * This will change the cell type to next type in enum GridCell
     */
    void cycleCell(int x, int y);
};


#endif //KATANA_GRID_H
