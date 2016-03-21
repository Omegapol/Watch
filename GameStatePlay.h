//
// Created by Łukasz on 2016-03-20.
//

#ifndef WATCH_GAMESTATEPLAY_H
#define WATCH_GAMESTATEPLAY_H

#include "SFML/Graphics.hpp"

#include "GameState.h"
#include "Player.h"
#include "Map.h"

class GameStatePlay : public GameState {
public:
    virtual void draw(const float dt);

    virtual void update(const float dt);

    virtual void handleInput();

    GameStatePlay(Game *game);

private:
    sf::View gameView;
    sf::View guiView;
    Player player;
    Map * map;

    void loadMap();
};


#endif //WATCH_GAMESTATEPLAY_H
