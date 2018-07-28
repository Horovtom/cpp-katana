//
// Created by lactosis on 28.7.18.
//

#ifndef KATANA_NUMBERSTEXTURES_H
#define KATANA_NUMBERSTEXTURES_H

#define MAX_NUMBER 50

#include <SDL.h>
#include <SDL_ttf.h>
#include <vector>
#include <stdexcept>
#include <map>
#include "LTexture.h"
#include "Coordinate.h"


class NumbersTextures {
private:
    std::vector<SDL_Texture *> numbers;
    TTF_Font *fontUsed;
    unsigned char minNumber, maxNumber;
    std::vector<SDL_Rect> numberDimensions;
    const SDL_Color textColor = {0, 0, 0, 0xFF};

    SDL_Texture *createTexture(SDL_Renderer *pRenderer, int i);

public:
    NumbersTextures(const std::string &fontPath, SDL_Renderer *renderer, unsigned char fontSize = 12,
                    unsigned char minNumber = 0, unsigned char maxNumber = 50);

    SDL_Texture *getTexture(unsigned char i);

    SDL_Rect *getTextureSize(unsigned char i);

    void freeResources();

    ~NumbersTextures();
};


#endif //KATANA_NUMBERSTEXTURES_H
