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
    SDL_Rect *r = &cells.at(x).at(y);
    if (type == BLACK) {
        //Set color to black
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        //Draw filled square
        SDL_RenderFillRect(renderer, r);

    } else if (type == CROSS) {
        //Set color to black
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        Sint16 x1, x2, y1, y2;

        //Calculate first line coords:
        auto offset = static_cast<int>(cellSize / 5.0);
        //TODO: Cache the result somehow so we do not have to calculate this every frame
        x1 = static_cast<Sint16>(r->x + offset);
        y1 = static_cast<Sint16>(r->y + offset);
        x2 = static_cast<Sint16>(r->x + r->w - offset);
        y2 = static_cast<Sint16>(r->y + r->h - offset);

        thickLineRGBA(renderer, x1, y1, x2, y2, 2, 0x00, 0x00, 0x00, 0xFF);
        thickLineRGBA(renderer, x1, y2, x2, y1, 2, 0x00, 0x00, 0x00, 0xFF);

    } else if (type == DOT) {
        //Set color to black
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

        filledEllipseRGBA(renderer, static_cast<Sint16>(r->x + r->w / 2.0), static_cast<Sint16>(r->y + r->h / 2.0), 3,
                          4, 0x00, 0x00, 0x00, 0xFF);

    } else if (type == BLANK) {
        //Set color to white
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        //Draw filled rectangle with white color
        SDL_RenderFillRect(renderer, r);

    } else {
        std::cerr << "Unknown cell type: " << type << std::endl;
        return;
    }

    //Set color to transparent black
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xB0);
    //Draw square outline
    SDL_RenderDrawRect(renderer, r);
}

void GridGraphicsObject::freeResources() {
    renderer = nullptr;
}

GridGraphicsObject::~GridGraphicsObject() {
    freeResources();
}

bool GridGraphicsObject::mouseDown(int x, int y) {
    if (x < this->x || y < this->y || x > this->x + cellSize * widthCells ||
        y > this->y + cellSize * heightCells)
        return false;

    // These are the cell coordinates of the clicked cell:
    int cellX, cellY;

    cellX = x - this->x;
    cellX /= cellSize;
    cellY = y - this->y;
    cellY /= cellSize;
    clickedOnCell(cellX, cellY);

    return true;
}

void GridGraphicsObject::clickedOnCell(int x, int y) {
    std::cout << "User clicked on grid cell: " << x << "," << y << std::endl;
    this->logicManager->cycleCellType(x, y);
}
