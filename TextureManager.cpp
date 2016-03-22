//
// Created by Łukasz on 2016-03-20.
//

#include "TextureManager.h"
#include "DMemoryLeaks.h"
std::map<std::string, sf::Texture>* TextureManager::textures = NULL;

void TextureManager::loadTexture(const std::string name, const std::string filename) {
    sf::Texture tex;
    tex.loadFromFile(filename);

    (*textures)[name] = tex;

    return;
}

sf::Texture &TextureManager::getRef(const std::string textureName) {
    return (*textures).at(textureName);
}

void TextureManager::setTexStorage(std::map<std::string, sf::Texture>* tex)
{
	textures = tex;
}

void TextureManager::destroyTexStorage()
{
	delete textures;
}
