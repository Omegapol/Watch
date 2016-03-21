//
// Created by Łukasz on 2016-03-21.
//

#include "Map.h"

Map::Map(int width, int height, int tileSize) : width(width), height(height), tileSize(tileSize) {
    arr = new Tile **[height];
    for (int i = 0; i < height; ++i) {
        arr[i] = new Tile*[width];
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            arr[i][j] = nullptr;
        }
    }
}

Map::~Map() {
    for (int i = 0; i < this->height; ++i) {
        delete [] this->arr[i];
    }
    delete [] arr;
}

Tile *Map::getTile(int x, int y) {
    return arr[x][y];
}

bool Map::isCollideable(float x, float y) {
    return getTile(int(x) / this->tileSize, int(y) / this->tileSize) != nullptr;
}

void Map::createTile(int x, int y, Tile::tileType type) {
    if (getTile(x, y) != nullptr) return;

    this->arr[x][y] = new Tile();
    return;
}
