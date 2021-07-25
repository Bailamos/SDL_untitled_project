#include "textureLoader.hpp"

TextureLoader::TextureLoader(SDL_Renderer *renderer)
{
    this->renderer = renderer;
}

TextureLoader::~TextureLoader()
{
    for (auto const &entry : this->textures)
    {
        SDL_DestroyTexture(entry.second);
    }
}

SDL_Texture *TextureLoader::getTexture(TextureType textureType)
{
    if (this->textures.find(textureType) == this->textures.end())
    {
        return this->loadTexture(textureType);
    }
    else
    {
        return this->textures[textureType];
    }
}

SDL_Texture *TextureLoader::loadTexture(TextureType textureType)
{
    //TODO: more sophisticated loader
    if (textureType == Tree)
    {
        this->textures.insert_or_assign(textureType, IMG_LoadTexture(this->renderer, "assets/treeTile.png"));
        return this->textures[textureType];
    }
}