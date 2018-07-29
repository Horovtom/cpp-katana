//
// Created by lactosis on 26.7.18.
//

#include <iostream>
#include "GridGraphicsObject.h"
#include "LogicManager.h"
#include "Grid.h"

GridGraphicsObject::GridGraphicsObject(int x, int y, LogicManager *l, SDL_Renderer *renderer, int cellSize) {
    this->renderer = renderer;
    this->logicManager = l;
    this->x = x;
    this->y = y;
    this->cellSize = cellSize;

    calculateDimensions();
    calculateViewPortSize();
    createCells();

}

void GridGraphicsObject::calculateDimensions() {
    Grid *grid = logicManager->getGridRef();
    this->widthCells = grid->getWidth();
    this->heightCells = grid->getHeight();

}

void GridGraphicsObject::calculateViewPortSize() {
    this->gridViewPort = {x, y, widthCells * cellSize, heightCells * cellSize};
}

void GridGraphicsObject::createCells() {
    SDL_Rect r{};

    for (int x = 0; x < gridViewPort.w; x += cellSize) {
        std::vector<SDL_Rect> a;

        for (int y = 0; y < gridViewPort.h; y += cellSize) {
            r = {x, y, cellSize, cellSize};
            a.emplace_back(r);
        }
        cells.emplace_back(a);
    }
}

void GridGraphicsObject::updateInput() {
//TODO: IMPLEMENT
}

void GridGraphicsObject::updateOutput() {

    Grid *g = logicManager->getGridRef();
    drawGrid(g);
//TODO: IMPLEMENT
}

void GridGraphicsObject::drawGrid(Grid *pGrid) {
    SDL_RenderSetViewport(renderer, &gridViewPort);

    for (int x = 0; x < widthCells; ++x) {
        for (int y = 0; y < heightCells; ++y) {
            drawCell(x, y, pGrid->getCell(x, y));

        }
    }
}

void GridGraphicsObject::drawCell(int x, int y, GridCell type) {
    switch (type) {
        case BLANK:
            SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
            break;
        case BLACK:
            SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
            break;
        case CROSS:
            //TODO: IMPLEMENT ACTUAL CROSS
            SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
            break;
        case DOT:
            //TODO: IMPLEMENT ACTUAL DOT
            SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
            break;
        default:
            std::cerr << "GridGraphicsObject::drawCell() Unknown celltype: " << type << std::endl;
    }

    SDL_Rect *r = &cells.at(x).at(y);

    SDL_RenderFillRect(renderer, r);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xB0);
    SDL_RenderDrawRect(renderer, r);


}

void GridGraphicsObject::freeResources() {
    renderer = nullptr;
}

GridGraphicsObject::~GridGraphicsObject() {
    freeResources();
}
