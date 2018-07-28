//
// Created by lactosis on 26.7.18.
//

#include "CluesGraphicsObject.h"
#include "Legend.h"


void CluesGraphicsObject::updateInput() {
//TODO: IMPLEMENT
}

void CluesGraphicsObject::updateOutput() {
    Legend *l = logicManager->getCluesRef();
    drawTopClues(l);
    drawLeftClues(l);
//TODO: IMPLEMENT
}

CluesGraphicsObject::CluesGraphicsObject(int x, int y, LogicManager *l, SDL_Renderer *renderer) {
    //loadSprites();
    this->renderer = renderer;
    numbersTextures = new NumbersTextures(USED_FONT, renderer);
    logicManager = l;
    this->x = x;
    this->y = y;

    calculateDimensions();
//TODO: IMPLEMENT
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
//TODO: IMPLEMENT
}

Coordinate CluesGraphicsObject::getInnerPoint() {
    return {x + static_cast<int>(leftWidth), y + static_cast<int>(topHeight)};
}

void CluesGraphicsObject::calculateDimensions() {
    Legend *l = logicManager->getCluesRef();
    topHeight = l->getTopHeight() * cellSize;
    topWidth = l->getTopWidth() * cellSize;
    leftHeight = l->getLeftHeight() * cellSize;
    leftWidth = l->getLeftWidth() * cellSize;

    calculateViewPortSize();
    createCells();

//TODO: IMPLEMENT
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

[[deprecated]]
void CluesGraphicsObject::loadSprites() {

}

void CluesGraphicsObject::drawCell(unsigned long x, unsigned long y, int number, bool top, bool strikeThrough) {
    SDL_Rect *r = &(top ? topCells : leftCells).at(x).at(y);

    SDL_SetRenderDrawColor(renderer, 0xAA, 0xAF, 0x00, 0x40);
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
        for (unsigned long y = col.size() - 1; y >= 0; --y) {
            drawCell(x, y, col.at(y), true, colDone.at(y));
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

