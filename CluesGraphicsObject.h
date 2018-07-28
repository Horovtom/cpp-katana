//
// Created by lactosis on 26.7.18.
//

#ifndef KATANA_LEGENDGRAPHICSOBJECT_H
#define KATANA_LEGENDGRAPHICSOBJECT_H

#define CELL_SPRITE "sprites/square.png"
#define USED_FONT "fonts/Anonymous.ttf"


#include <SDL_ttf.h>
#include "LogicManager.h"
#include "Coordinate.h"
#include "Legend.h"
#include "LTexture.h"
#include "NumbersTextures.h"

class CluesGraphicsObject {
private:
    LogicManager *logicManager;
    int x, y;
    unsigned int topWidth, topHeight, leftWidth, leftHeight;

    //region Graphics

    //FIXME: Consider using pre-rendered texture for rendering
    SDL_Rect topViewPort, leftViewPort;

    std::vector<std::vector<SDL_Rect>> topCells;
    std::vector<std::vector<SDL_Rect>> leftCells;

    SDL_Texture *cellTexture = nullptr;
    SDL_Renderer *renderer = nullptr;
    NumbersTextures *numbersTextures;

    //endregion

    /**
     * CellSize in pixels
     */
    const unsigned int cellSize = 34;
public:
    CluesGraphicsObject(int x, int y, LogicManager *l, SDL_Renderer *renderer);

    void freeResources();

    ~CluesGraphicsObject();

    Coordinate getInnerPoint();

    /**
     * Handle the user input and send it over to logic
     */
    void updateInput();

    /**
     * Read changes from logic and display them
     */
    void updateOutput();

    void calculateDimensions();

    void calculateViewPortSize();

    [[deprecated]]
    void loadSprites();

    void drawCell(int x, int y, int number, bool strikeThrough = false);

    void drawTopClues(Legend *l);

    void createCells();
};


#endif //KATANA_LEGENDGRAPHICSOBJECT_H
