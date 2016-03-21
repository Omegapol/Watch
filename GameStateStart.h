//
// Created by Łukasz on 2016-03-20.
//

#ifndef WATCH_GAMESTATESTART_H
#define WATCH_GAMESTATESTART_H

#include "SFML/Graphics.hpp"

#include "GameState.h"

class GameStateStart : public GameState {
public:

    virtual void draw(const float dt);

    virtual void update(const float dt);

    virtual void handleInput();

    GameStateStart(Game *game);

private:
    sf::View view;

    void loadGame();
};


#endif //WATCH_GAMESTATESTART_H
