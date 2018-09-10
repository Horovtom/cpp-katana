//
// Created by lactosis on 26.7.18.
//

#ifndef KATANA_UIGRAPHICSOBJECT_H
#define KATANA_UIGRAPHICSOBJECT_H


#include <SDL2/SDL_render.h>
#include "LogicManager.h"
#include <SDL2/SDL2_gfxPrimitives.h>
#include "Vector2.h"

class UIGraphicsObject {
private:
    SDL_Renderer *renderer = nullptr;
    LogicManager *logicManager = nullptr;
    int x, y, width, height;
    SDL_Texture *targetTexture = nullptr;
    SDL_Rect uiViewPort;

    /**
     * Buttons locations array
     */
    Vector2 buttons[2];

    /**
     * Size of rectangles for the buttons in pixels
     */
    int buttonSize = 25;

public:
    UIGraphicsObject(int x, int y, LogicManager *l, SDL_Renderer *renderer, int width = 200, int height = 50);

    void freeResources();

    ~UIGraphicsObject();

    void updateInput();

    void updateOuptut();

    bool mouseDown(int x, int y);


    void createMenu();


    void drawMenu();
};


#endif //KATANA_UIGRAPHICSOBJECT_H
