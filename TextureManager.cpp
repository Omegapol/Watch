//
// Created by Łukasz on 2016-03-20.
//

#include "TextureManager.h"

void TextureManager::loadTexture(const std::string name, const std::string filename) {
    sf::Texture tex;
    tex.loadFromFile(filename);

    this->textures[name] = tex;

    return;
}

sf::Texture &TextureManager::getRef(const std::string textureName) {
    return this->textures.at(textureName);
}
