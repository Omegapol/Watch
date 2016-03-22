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

    static void loadTexture(const std::string name, const std::string filename);

    static sf::Texture &getRef(const std::string textureName);

	static void setTexStorage(std::map<std::string, sf::Texture>* tex);
	static void destroyTexStorage();

    TextureManager() { }
	//~TextureManager();

private:
    static std::map<std::string, sf::Texture>* textures;
};


#endif //WATCH_TEXTUREMANAGER_H
