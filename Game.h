//
// Created by Łukasz on 2016-03-20.
//

#ifndef WATCH_GAME_H
#define WATCH_GAME_H

#include <stack>
#include "SFML/Graphics.hpp"
#include "TextureManager.h"

class GameState;

class Game {
public:
    std::stack<GameState *> states;
    sf::RenderWindow window;
    TextureManager texMgr;
    sf::Sprite background;

    void pushState(GameState *state);

    void popState();

    void changeState(GameState *state);

    GameState *peekState();

    void gameLoop();

    Game();

    ~Game();

private:
    void loadTextures();
};


#endif //WATCH_GAME_H
