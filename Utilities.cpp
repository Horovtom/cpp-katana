//
// Created by lactosis on 10.9.18.
//

#include "Utilities.h"

void drawThickRectangle(SDL_Renderer *renderer, int x, int y, int width, int height, Uint8 stroke, Uint32 color) {
    int marg = stroke / 2;
    int add = stroke % 2 == 0 ? 0 : 1;
    thickLineColor(renderer, x, y, x + width + marg + add, y, stroke, color);
    thickLineColor(renderer, x + width, y, x + width, y + height + marg + add, stroke, color);
    thickLineColor(renderer, x + width, y + height, x - marg - add, y + height, stroke, color);
    thickLineColor(renderer, x, y + height, x, y - marg - add, stroke, color);
}
