//
// Created by Łukasz on 2016-03-21.
//

#include "Tile.h"

Tile::Tile(int x, int y, Tile::tileType type) : type(type), x(x), y(y) {
    switch(type) {
        case ROCK: {
            this->tex = Storage::texMgr.getRef("rock-texture");
            break;
        }
        case GRASS: {
            break;
        }
    }
    this->sprite.setTexture(this->tex, true);
    this->sprite.setPosition(this->x * Storage::tileSize, this->y * Storage::tileSize);
}

void Tile::draw(sf::RenderWindow &window) {
    window.draw(this->sprite);
}

sf::FloatRect Tile::getGlobalBounds() {
    return this->sprite.getGlobalBounds();
}
