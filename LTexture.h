//
// Created by lactosis on 26.7.18.
//

#ifndef KATANA_LTEXTURE_H
#define KATANA_LTEXTURE_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

class LTexture {
public:
    //Initializes variables
    LTexture(SDL_Renderer* renderer);

    //Deallocates memory
    ~LTexture();

    //Loads image at specified path
    bool loadFromFile( std::string path );

#ifdef _SDL_TTF_H
    //Creates image from font string
		bool loadFromRenderedText( const std::string &textureText, SDL_Color textColor, TTF_Font *font);
#endif

    //Deallocates texture
    void free();

    //Set color modulation
    void setColor( Uint8 red, Uint8 green, Uint8 blue );

    //Set blending
    void setBlendMode( SDL_BlendMode blending );

    //Set alpha modulation
    void setAlpha( Uint8 alpha );

    //Renders texture at given point
    void render( int x, int y, SDL_Rect* clip = nullptr,
                 double angle = 0.0, SDL_Point* center = nullptr,
                 SDL_RendererFlip flip = SDL_FLIP_NONE );

    //Gets image dimensions
    int getWidth();
    int getHeight();

private:
    SDL_Renderer* renderer = nullptr;
    //The actual hardware texture
    SDL_Texture* mTexture  = nullptr    ;

    //Image dimensions
    int width = 0;
    int height = 0;
};


#endif //KATANA_LTEXTURE_H
