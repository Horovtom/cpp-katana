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
    drawTopClues(nullptr);

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
    //TODO: IMPLEMENT
    return Coordinate();
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
    leftViewPort.y = topHeight;
    leftViewPort.w = leftWidth;
    leftViewPort.h = leftHeight;
}

[[deprecated]]
void CluesGraphicsObject::loadSprites() {

}

void CluesGraphicsObject::drawCell(int x, int y, int number, bool strikeThrough = false) {
    SDL_Rect *r = &topCells.at(x).at(y);

    SDL_SetRenderDrawColor(renderer, 0x22, 0x22, 0x00, 0x40);
    SDL_RenderFillRect(renderer, r);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderDrawRect(renderer, r);
    SDL_Texture *texture = numbersTextures->getTexture(static_cast<unsigned char>(number));
    SDL_Rect *size = numbersTextures->getTextureSize(static_cast<unsigned char>(number));

    SDL_Rect a = {static_cast<int>(r->x + r->w - size->w / 2.0), static_cast<int>(r->y + r->h - size->h / 2.0), size->w,
                  size->h};
    SDL_RenderCopy(renderer, texture, size, &a);

    //TODO: IMPLEMENT StrikeThrough
}

void CluesGraphicsObject::drawTopClues(Legend *l) {
    SDL_RenderSetViewport(renderer, &topViewPort);


    for (unsigned int x = 0; x < l->getTopWidth(); ++x) {
        std::vector<bool> colDone = l->getTopCluesDone(x);
        std::vector<unsigned int> col = l->getTopClues(x);
        for (auto y = col.size() - 1; y >= 0; --y) {
            drawCell(x, y, col.at(y), colDone.at(y));
        }
    }

}

void CluesGraphicsObject::createCells() {
    for (int x = 0; x < topViewPort.w; x += cellSize) {
        std::vector<SDL_Rect> n;
        for (int y = topViewPort.h; y > 0; y -= cellSize) {
            n.emplace_back({x, y, cellSize, cellSize});
        }
        topCells.emplace_back(n);
    }

    for (int x = 0; x < leftViewPort.w; x += cellSize) {
        std::vector<SDL_Rect> n;
        for (int y = leftViewPort.h; y > 0; y -= cellSize) {
            n.emplace_back({y, x, cellSize, cellSize});
        }
        leftCells.emplace_back(n);
    }
}

