//
// Created by Łukasz on 2016-03-21.
//

#ifndef WATCH_TILE_H
#define WATCH_TILE_H

#include "SFML/Graphics.hpp"
#include "Storage.h"

class Tile {
public:
    enum tileType {
        GRASS,
        ROCK,
    };

    void draw(sf::RenderWindow &window);

    sf::FloatRect getGlobalBounds();

    Tile(int x, int y, Tile::tileType type);

private:
    tileType type;
    sf::Texture tex;
    sf::Sprite sprite;
    int x;
    int y;
};


#endif //WATCH_TILE_H
