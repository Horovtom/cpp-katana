//
// Created by lactosis on 10.9.18.
//

#ifndef KATANA_UTILITIES_H
#define KATANA_UTILITIES_H

#include <SDL2/SDL_render.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "statics.h"

void drawThickRectangle(SDL_Renderer *renderer, int x, int y, int width, int height, Uint8 stroke,
                        Uint32 color = COLOR_BLACK);

#endif //KATANA_UTILITIES_H
