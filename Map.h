//
// Created by Łukasz on 2016-03-21.
//

#ifndef WATCH_MAP_H
#define WATCH_MAP_H

#include "Tile.h"

class Map {
public:
    bool isCollideable(float x, float y);

    Map(int width, int height, int tileSize);

    ~Map();
private:
    int width;
    int height;
    int tileSize;
    Tile **arr = nullptr;
};


#endif //WATCH_MAP_H
