//
// Created by Łukasz on 2016-03-21.
//

#include "Map.h"
#include "Game.h"

Map::Map(int width, int height) : width(width), height(height) {
    arr = new Tile **[height];
    for (int i = 0; i < height; ++i) {
        arr[i] = new Tile *[width];
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            this->arr[i][j] = nullptr;
        }
    }
}

Map::~Map() {
    for (int i = 0; i < this->height; ++i) {
        delete[] this->arr[i];
    }
    delete[] arr;
}

Tile *Map::getTile(int x, int y) {
    return arr[x][y];
}

bool Map::isCollideable(float x, float y, const sf::FloatRect &playerBounds) {
    int startX = int(x) / Storage::tileSize;
    int startY = int(y) / Storage::tileSize;
    Tile *tile;
    for (int i = startX - 10; i <= startX + 10; ++i) {
        for (int j = startY - 10; j <= startY + 10; ++j) {
            if (i >= 0 && j >= 0) {
                tile = getTile(i, j);
                if (tile != nullptr && playerBounds.intersects(tile->getGlobalBounds()))
                    return true;
            }
        }
    }
    return false;
}

void Map::createTile(int x, int y, Tile::tileType type) {
    if (this->arr[x][y] != nullptr) return;

    this->arr[x][y] = new Tile(x + 1, y + 1, type);
    return;
}

void Map::draw(sf::RenderWindow &window) {
    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            if (this->arr[i][j] != nullptr) this->arr[i][j]->draw(window);
        }
    }
}
