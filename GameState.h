//
// Created by Łukasz on 2016-03-20.
//

#ifndef WATCH_GAMESTATE_H
#define WATCH_GAMESTATE_H

#include "Game.h"

class GameState {
public:
    Game *game;

    virtual void draw(const float dt) = 0;

    virtual void update(const float dt) = 0;

    virtual void handleInput() = 0;
};


#endif //WATCH_GAMESTATE_H
