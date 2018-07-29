//
// Created by lactosis on 28.7.18.
//

#include "NumbersTextures.h"

NumbersTextures::NumbersTextures(const std::string &fontPath, SDL_Renderer *renderer, const unsigned char fontSize,
                                 const unsigned char minNumber, const unsigned char maxNumber) {
    this->minNumber = minNumber;
    this->maxNumber = maxNumber;
    this->fontUsed = TTF_OpenFont(fontPath.c_str(), fontSize);
    if (this->fontUsed == nullptr) {
        std::cerr << "Failed to load font: " << fontPath << " Error: " << TTF_GetError << std::endl;
        throw std::invalid_argument("Font loading error");
    }

    for (int i = minNumber; i < maxNumber; ++i) {
        createTexture(renderer, i);
    }
}

SDL_Texture *NumbersTextures::createTexture(SDL_Renderer *pRenderer, int i) {
    SDL_Surface *textSurface = TTF_RenderText_Solid(fontUsed, std::to_string(i).c_str(), textColor);
    if (textSurface == nullptr) {
        std::cerr << "Failed to load surface from font! Error: " << TTF_GetError << std::endl;
        throw std::invalid_argument("Font loading error");
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(pRenderer, textSurface);
    if (texture == nullptr) {
        std::cerr << "Unable to create texture from rendered text! SDL Error: " << SDL_GetError() << std::endl;
        throw std::invalid_argument("Font loading error");
    }

    numbers.emplace_back(texture);
    SDL_Rect r = {0, 0, textSurface->w, textSurface->h};
    numberDimensions.emplace_back(r);

    SDL_FreeSurface(textSurface);
    return texture;
}

NumbersTextures::~NumbersTextures() {
    freeResources();
}

void NumbersTextures::freeResources() {
    if (fontUsed != nullptr) TTF_CloseFont(fontUsed);
    fontUsed = nullptr;

    for (auto number : numbers) {
        SDL_DestroyTexture(number);
    }

    numbers.clear();
}

SDL_Texture *NumbersTextures::getTexture(unsigned char i) {
    if (i >= maxNumber || i < minNumber) {
        std::cerr << "Invalid argument. This NumbersTextures object does not have a texture for number " << i
                  << std::endl;
        return nullptr;
    }

    return numbers.at(i - minNumber);
}

SDL_Rect *NumbersTextures::getTextureSize(unsigned char i) {
    if (i >= maxNumber || i < minNumber) {
        std::cerr << "Invalid argument. This NumbersTextures object does not have a texture for number " << i
                  << std::endl;
        return nullptr;
    }

    return &numberDimensions.at(i - minNumber);
}
