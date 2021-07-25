#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include <SDL.H>
#include <SDL_image.h>
#include <map>
#include "engine/objects/textureType.hpp"

class TextureLoader
{
public:
    TextureLoader(SDL_Renderer *renderer);
    ~TextureLoader();
    SDL_Texture *getTexture(TextureType textureType);

private:
    std::map<TextureType, SDL_Texture *> textures;
    SDL_Texture *loadTexture(TextureType textureType);
    SDL_Renderer *renderer;
};

#endif