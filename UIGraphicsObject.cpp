//
// Created by lactosis on 26.7.18.
//

#include "UIGraphicsObject.h"
#include <iostream>
#include "LogicManager.h"
#include "Utilities.h"

UIGraphicsObject::UIGraphicsObject(int x, int y, LogicManager *l, SDL_Renderer *renderer, int width,
                                   int height) {
    this->renderer = renderer;
    this->logicManager = l;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;

    //TODO: IMPLEMENT
    //Initialize buttons positions:
    this->buttons[0].x = 5;
    this->buttons[0].y = 5;
    this->buttons[1].x = this->buttons[0].x + this->buttonSize + 3;
    this->buttons[1].y = 5;

    createMenu();
}

void UIGraphicsObject::updateInput() {
//TODO: IMPLEMENT
}

void UIGraphicsObject::updateOuptut() {
    drawMenu();
}

void UIGraphicsObject::freeResources() {
    if (targetTexture != nullptr) SDL_DestroyTexture(targetTexture);
    targetTexture = nullptr;
}

UIGraphicsObject::~UIGraphicsObject() {
    freeResources();

}

bool UIGraphicsObject::mouseDown(int x, int y) {
    if (x < this->x || x > this->x + this->width || y < this->y || y > this->y + this->height) return false;

    int localX = x - this->x;
    int localY = y - this->y;

    if (localX >= buttons[0].x && localY >= buttons[0].y && localX < buttons[0].x + buttonSize &&
        localY < buttons[0].y + buttonSize) {
        //Clicked on button 0:
        std::cout << "Clicked on button 0: " << std::endl;

    }

    if (localX >= buttons[1].x && localY >= buttons[1].y && localX < buttons[1].x + buttonSize &&
        localY < buttons[1].y + buttonSize) {
        //Clicked on button 1:
        std::cout << "Clicked on button 1: " << std::endl;
    }
    return true;
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

    //Draw outline
    drawThickRectangle(renderer, 0, 0, this->width, this->height, 3, COLOR_BLACK);

    //Draw buttons
    //Set the color to semi-transparent black
    SDL_SetRenderDrawColor(renderer, 0x20, 0x20, 0x20, 0xFF);

    SDL_Rect butt1 = {buttons[0].x, buttons[0].y, this->buttonSize, this->buttonSize};
    SDL_RenderFillRect(renderer, &butt1);
    SDL_Rect butt2 = {buttons[1].x, buttons[1].y, this->buttonSize, this->buttonSize};
    SDL_RenderDrawRect(renderer, &butt2);

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
