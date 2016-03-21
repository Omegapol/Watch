//
// Created by Łukasz on 2016-03-21.
//

#ifndef WATCH_MAP_H
#define WATCH_MAP_H

#include "Tile.h"

class Map {
public:
    bool isCollideable(float x, float y);

    Tile * getTile(int x, int y);

    void createTile(int x, int y, Tile::tileType type);

    Map(int width, int height, int tileSize);

    ~Map();
private:
    int width;
    int height;
    int tileSize;
    Tile ***arr = nullptr;
};


#endif //WATCH_MAP_H
