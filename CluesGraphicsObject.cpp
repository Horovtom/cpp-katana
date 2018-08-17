//
// Created by lactosis on 26.7.18.
//

#include "CluesGraphicsObject.h"
#include "Legend.h"


CluesGraphicsObject::CluesGraphicsObject(int x, int y, LogicManager *l, SDL_Renderer *renderer, int cellSize) {
    //loadSprites();
    this->renderer = renderer;
    numbersTextures = new NumbersTextures(USED_FONT, renderer);
    logicManager = l;
    this->x = x;
    this->y = y;
    this->cellSize = cellSize;

    calculateDimensions();
    calculateViewPortSize();
    createCells();
}

void CluesGraphicsObject::calculateDimensions() {
    Legend *l = logicManager->getCluesRef();
    topHeight = l->getTopHeight() * cellSize;
    topWidth = l->getTopWidth() * cellSize;
    leftHeight = l->getLeftHeight() * cellSize;
    leftWidth = l->getLeftWidth() * cellSize;
}

void CluesGraphicsObject::calculateViewPortSize() {
    topViewPort.x = x + leftWidth;
    topViewPort.y = y;
    topViewPort.h = leftHeight;
    topViewPort.w = topWidth;

    leftViewPort.x = x;
    leftViewPort.y = y + topHeight;
    leftViewPort.w = leftWidth;
    leftViewPort.h = leftHeight;
}

void CluesGraphicsObject::createCells() {
    SDL_Rect r{};
    for (int x = 0; x < topViewPort.w; x += cellSize) {
        std::vector<SDL_Rect> n;
        for (int y = topViewPort.h - cellSize; y >= 0; y -= cellSize) {
            r = {x, y, cellSize, cellSize};
            n.emplace_back(r);
        }
        topCells.emplace_back(n);
    }

    for (int y = 0; y < leftViewPort.h; y += cellSize) {
        std::vector<SDL_Rect> n;
        for (int x = leftViewPort.w - cellSize; x >= 0; x -= cellSize) {
            r = {x, y, cellSize, cellSize};
            n.emplace_back(r);
        }
        leftCells.emplace_back(n);
    }
}

void CluesGraphicsObject::updateInput() {
//TODO: IMPLEMENT
}

void CluesGraphicsObject::updateOutput() {
    Legend *l = logicManager->getCluesRef();
    drawTopClues(l);
    drawLeftClues(l);
}

void CluesGraphicsObject::freeResources() {
    delete numbersTextures;
    if (cellTexture != nullptr) {
        SDL_DestroyTexture(cellTexture);
        cellTexture = nullptr;
    }
    renderer = nullptr;
}

CluesGraphicsObject::~CluesGraphicsObject() {
    freeResources();
}

Coordinate CluesGraphicsObject::getInnerPoint() {
    return {x + static_cast<int>(leftWidth), y + static_cast<int>(topHeight)};
}

[[deprecated]]
void CluesGraphicsObject::loadSprites() {

}

void CluesGraphicsObject::drawCell(unsigned long x, unsigned long y, int number, bool top, bool strikeThrough) {
    SDL_Rect *r = &(top ? topCells : leftCells).at(x).at(y);

    SDL_SetRenderDrawColor(renderer, 0xAA, 0x70, 0x00, 0x40);
    SDL_RenderFillRect(renderer, r);
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderDrawRect(renderer, r);
    SDL_Texture *texture = numbersTextures->getTexture(static_cast<unsigned char>(number));
    SDL_Rect *size = numbersTextures->getTextureSize(static_cast<unsigned char>(number));

    SDL_Rect a = {static_cast<int>(r->x + (r->w / 2.0) - (size->w / 2.0)),
                  static_cast<int>(r->y + (r->h / 2.0) - (size->h / 2.0)), size->w, size->h};

    SDL_RenderCopy(renderer, texture, size, &a);

    //TODO: IMPLEMENT StrikeThrough
}

void CluesGraphicsObject::drawTopClues(Legend *l) {
    SDL_RenderSetViewport(renderer, &topViewPort);

    for (unsigned int x = 0; x < l->getTopWidth(); ++x) {
        std::vector<bool> colDone = l->getTopCluesDone(x);
        std::vector<unsigned int> col = l->getTopClues(x);
        for (auto y = static_cast<int>(col.size() - 1); y >= 0; --y) {
            drawCell(x, static_cast<unsigned long>(y), col.at(static_cast<unsigned long>(y)), true, colDone.at(y));
        }
    }
}

void CluesGraphicsObject::drawLeftClues(Legend *l) {
    SDL_RenderSetViewport(renderer, &leftViewPort);

    for (unsigned int y = 0; y < l->getLeftHeight(); ++y) {
        std::vector<bool> rowDone = l->getLeftCluesDone(y);
        std::vector<unsigned int> row = l->getLeftClues(y);

        unsigned long size = row.size();
        for (unsigned int x = 0; x < size; ++x) {
            drawCell(y, x, row.at(size - x - 1), false, rowDone.at(size - x - 1));
        }
    }
}

bool CluesGraphicsObject::mouseDown(int x, int y) {
    //These are cell coordinates of where the hell we clicked
    int cellX, cellY;

    //Top left corner check
    if (x < this->x || y < this->y) return false;
    //In between check
    if (x < this->x + leftWidth && y < this->y + topHeight) return false;

    //Inner Check
    if (x < this->x + leftWidth && y < this->y + leftHeight + topHeight) {
        //It was in the left clues:
        cellX = x - this->x;
        cellY = y - this->y - topHeight;
        cellX /= cellSize;
        cellY /= cellSize;

        leftCluesClick(cellX, cellY);
        //TODO: IMPLEMENT
    } else if (x < this->x + topWidth + leftWidth && y < this->y + topHeight) {
        //It was in the top clues:

        cellX = x - this->x - leftWidth;
        cellY = y - this->y;
        cellX /= cellSize;
        cellY /= cellSize;

        topCluesClick(cellX, cellY);
    } else {
        //It has to be outside!
        return false;
    }

    return true;
}

/**
 * Starting from top left corner of clues
 */
void CluesGraphicsObject::topCluesClick(int x, int y) {
    std::cout << "Captured click on top clues: " << x << ", " << y << std::endl;
    //TODO: IMPLEMENT
}

/**
 * Starting from top left corner of clues
 * @param x
 * @param y
 */
void CluesGraphicsObject::leftCluesClick(int x, int y) {
    std::cout << "Captured click on left clues: " << x << ", " << y << std::endl;
    //TODO: IMPLEMENT
}

