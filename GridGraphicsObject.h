//
// Created by lactosis on 26.7.18.
//

#ifndef KATANA_GRIDGRAPHICSOBJECT_H
#define KATANA_GRIDGRAPHICSOBJECT_H

#include <SDL_system.h>
#include "LogicManager.h"

class GridGraphicsObject {
private:
    int x, y;

    unsigned int widthCells;
    unsigned int heightCells;

    std::vector<std::vector<SDL_Rect>> cells;

    SDL_Renderer *renderer;
    SDL_Rect gridViewPort;

    LogicManager *logicManager;

    void calculateDimensions();

    void calculateViewPortSize();

    void createCells();

    int cellSize;

public:


    GridGraphicsObject(int x, int y, LogicManager *l, SDL_Renderer *renderer, int cellSize = 34);

    void freeResources();

    ~GridGraphicsObject();

    void updateInput();

    void updateOutput();

    void drawGrid(Grid *pGrid);

    void drawCell(int x, int y, GridCell type);
};


#endif //KATANA_GRIDGRAPHICSOBJECT_H
