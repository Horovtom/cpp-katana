//
// Created by lactosis on 26.7.18.
//

#ifndef KATANA_GRIDGRAPHICSOBJECT_H
#define KATANA_GRIDGRAPHICSOBJECT_H

#include <SDL_system.h>
#include "LogicManager.h"

class GridGraphicsObject {
private:
    /**
     * Position of the top left corner of this grid object
     */
    int x, y;

    /**
     * Number of cells in respective directions
     */
    unsigned int widthCells, heightCells;

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

    bool mouseDown(int x, int y);

    void clickedOnCell(int x, int y);
};


#endif //KATANA_GRIDGRAPHICSOBJECT_H
