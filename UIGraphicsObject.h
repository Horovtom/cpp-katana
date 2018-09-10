//
// Created by lactosis on 26.7.18.
//

#ifndef KATANA_UIGRAPHICSOBJECT_H
#define KATANA_UIGRAPHICSOBJECT_H


#include <SDL2/SDL_render.h>
#include "LogicManager.h"

class UIGraphicsObject {
private:
    SDL_Renderer *renderer = nullptr;
    LogicManager *logicManager = nullptr;
    int x, y, width, height;
    SDL_Texture *targetTexture = nullptr;
    SDL_Rect uiViewPort;

public:
    UIGraphicsObject(int x, int y, LogicManager *l, SDL_Renderer *renderer, int width, int height);

    void freeResources();

    ~UIGraphicsObject();

    void updateInput();

    void updateOuptut();

    bool mouseDown(int x, int y);


    void createMenu();


    void drawMenu();
};


#endif //KATANA_UIGRAPHICSOBJECT_H
