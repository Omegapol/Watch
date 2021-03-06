//
// Created by Łukasz on 2016-03-21.
//

#ifndef WATCH_PLAYER_H
#define WATCH_PLAYER_H

#include "SFML/Graphics.hpp"
#include "Map.h"

class Player {
public:
    void move();

    float getX() {
        return pos.x;
    }

    float getY() {
        return pos.y;
    }

    void update(float dt, Map * map);

    void draw(sf::RenderWindow &window);

    Player(sf::Vector2f pos);

private:
    sf::Vector2f pos;
    sf::Vector2f moveVec;
    float const playerSpeed = 20.0f;
    sf::Texture tex;
    sf::Sprite sprite;
};


#endif //WATCH_PLAYER_H
