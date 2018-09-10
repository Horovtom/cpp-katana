//
// Created by lactosis on 26.7.18.
//

#include "UIGraphicsObject.h"
#include <iostream>
#include "LogicManager.h"

UIGraphicsObject::UIGraphicsObject(int x, int y, LogicManager *l, SDL_Renderer *renderer, int width = 100,
                                   int height = 50) {
    this->renderer = renderer;
    this->logicManager = l;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;

    createMenu();
    //TODO: IMPLEMENT
}

void UIGraphicsObject::updateInput() {
//TODO: IMPLEMENT
}

void UIGraphicsObject::updateOuptut() {
    drawMenu();
//TODO: IMPLEMENT
}

void UIGraphicsObject::freeResources() {
    if (targetTexture != nullptr) SDL_DestroyTexture(targetTexture);
    targetTexture = nullptr;
}

UIGraphicsObject::~UIGraphicsObject() {
    freeResources();

}

bool UIGraphicsObject::mouseDown(int x, int y) {
    //TODO: IMPLEMENT
    return false;
}

void UIGraphicsObject::createMenu() {
    //Create the viewport first
    uiViewPort.x = this->x;
    uiViewPort.y = this->y;
    uiViewPort.w = this->width;
    uiViewPort.h = this->height;

    //This will create the menu and cache the result.

    targetTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);

    //Switch render target to the texture
    SDL_SetRenderTarget(renderer, targetTexture);
    //Clear the texture with white color
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);

    //Set the color to semi-transparent black
    SDL_SetRenderDrawColor(renderer, 0x20, 0x20, 0x20, 0xA0);

    //Draw stuff
    SDL_Rect rect = {12, 0, 25, 25};
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderDrawLine(renderer, 112, 160, 10, 50);

    //Switch render target back to the default canvas
    SDL_SetRenderTarget(renderer, nullptr);

    drawMenu();

    //TODO: IMPLEMENT
}

void UIGraphicsObject::drawMenu() {
    if (targetTexture == nullptr) createMenu();
    if (targetTexture != nullptr) {
        SDL_RenderSetViewport(renderer, &uiViewPort);

        SDL_Rect r = {0, 0, this->width, this->height};

        SDL_RenderCopy(renderer, targetTexture, nullptr, &r);
    }
}
