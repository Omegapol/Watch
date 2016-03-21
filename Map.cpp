//
// Created by Łukasz on 2016-03-21.
//

#include "Map.h"

Map::Map(int width, int height, int tileSize) : width(width), height(height), tileSize(tileSize) {
    arr = new Tile *[height];
    for (int i = 0; i < height; ++i) {
        arr[i] = new Tile[width];
    }
}

Map::~Map() {
    for (int i = 0; i < this->height; ++i) {
        delete this->arr[i];
    }
    delete arr;
}

bool Map::isCollideable(float x, float y) {
    // TODO: Napisać to lepiej xD
    if (int(y) / this->tileSize > 10) return true;
    return false;
}
