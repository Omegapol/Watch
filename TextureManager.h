//
// Created by Łukasz on 2016-03-20.
//

#ifndef WATCH_TEXTUREMANAGER_H
#define WATCH_TEXTUREMANAGER_H

#include "SFML/Graphics.hpp"
#include <string>
#include <map>

class TextureManager {
public:

    void loadTexture(const std::string name, const std::string filename);

    sf::Texture &getRef(const std::string textureName);

    TextureManager() { }

private:
    std::map<std::string, sf::Texture> textures;
};


#endif //WATCH_TEXTUREMANAGER_H
