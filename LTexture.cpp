//
// Created by lactosis on 26.7.18.
//

#include "LTexture.h"


LTexture::LTexture(SDL_Renderer *renderer) {
    this->renderer = renderer;
}

LTexture::~LTexture() {
    //Deallocate
    free();
}

bool LTexture::loadFromFile(std::string path) {
    free();

    //The final texture
    SDL_Texture *newTexture = nullptr;

    //Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        std::cerr << "Unable to load image " << path.c_str() << "! SDL_image Error: " << IMG_GetError() << std::endl;
        return false;
    }

    //Color key image
    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

    //Create texture from surface pixels
    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (newTexture == nullptr) {
        std::cerr << "Unable to create texture from " << path.c_str() << "! SDL Error: " << SDL_GetError() << std::endl;
    } else {
        //Get image dimensions
        width = loadedSurface->w;
        height = loadedSurface->h;
    }

    //Get rid of old loaded surface
    SDL_FreeSurface(loadedSurface);


    //Return success
    mTexture = newTexture;
    return mTexture != nullptr;
}

bool LTexture::loadFromRenderedText(const std::string &textureText, SDL_Color textColor, TTF_Font *font) {
    //Render text surface
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, textureText.c_str(), textColor);

    if (textSurface == nullptr) {
        std::cerr << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << std::endl;
        return false;
    }

    mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (mTexture == nullptr) {
        std::cerr << "Unable to create texture from rendered text! SDL Error: " << SDL_GetError() << std::endl;
    } else {
        //Get image dimensions
        width = textSurface->w;
        height = textSurface->h;
    }

    SDL_FreeSurface(textSurface);


    //Return success
    return mTexture != nullptr;
}

void LTexture::free() {
    //Free texture if it exists
    if (mTexture != nullptr) {
        SDL_DestroyTexture(mTexture);
        mTexture = nullptr;
        width = 0;
        height = 0;
    }
}

void LTexture::setColor(Uint8 red, Uint8 green, Uint8 blue) {
    //Modulate texture rgb
    SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void LTexture::setBlendMode(SDL_BlendMode blending) {
    //Set blending function
    SDL_SetTextureBlendMode(mTexture, blending);
}

void LTexture::setAlpha(Uint8 alpha) {
    //Modulate texture alpha
    SDL_SetTextureAlphaMod(mTexture, alpha);
}

void LTexture::render(int x, int y, SDL_Rect *clip, double angle, SDL_Point *center, SDL_RendererFlip flip) {
    //Set rendering space and render to screen
    SDL_Rect renderQuad = {x, y, width, height};

    //Set clip rendering dimensions
    if (clip != nullptr) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //Render to screen
    SDL_RenderCopyEx(renderer, mTexture, clip, &renderQuad, angle, center, flip);
}

int LTexture::getWidth() {
    return width;
}

int LTexture::getHeight() {
    return height;
}