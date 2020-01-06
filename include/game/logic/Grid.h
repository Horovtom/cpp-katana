//
// Created by lactosis on 6.1.20.
//

#ifndef KATANA_GRID_H
#define KATANA_GRID_H

#include <vector>
#include <game/GridField.h>


class Grid {
public:
    Grid(int width, int height);

    void setFieldAt(int x, int y, GridField type);

    GridField getFieldAt(int x, int y);

    int getWidth();

    int getHeight();

    const std::vector<std::vector<GridField>> &getRef();

private:
    int width, height;
    std::vector<std::vector<GridField>> grid;

};

#endif //KATANA_GRID_H
