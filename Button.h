//
// Created by lactosis on 10.9.18.
//

#ifndef KATANA_BUTTON_H
#define KATANA_BUTTON_H


#include <functional>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <vector>

class Button {
private:
    std::vector<std::function<void(void)>> callbacks;
    int x, y, size;
    char text;
    SDL_Renderer *renderer = nullptr;

public:
    Button(SDL_Renderer *renderer, int x, int y, int size, char text) : x(x), y(y), size(size), text(text),
                                                                        renderer(renderer) {};

    void registerCallback(std::function<void(void)> cb);

    void draw();

    ~Button() { renderer = nullptr; }
};


#endif //KATANA_BUTTON_H
