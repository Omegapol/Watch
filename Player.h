//
// Created by Łukasz on 2016-03-21.
//

#ifndef WATCH_PLAYER_H
#define WATCH_PLAYER_H

#include "SFML/Graphics.hpp"

class Player {
public:
    void move();

    float getX() {
        return pos.x;
    }

    float getY() {
        return pos.y;
    }

    void update(float dt);

    void draw(sf::RenderWindow &window);

    Player(sf::Vector2f pos, sf::Texture &texture);

private:
    sf::Vector2f pos;
    sf::Vector2f moveVec;
    float const playerSpeed = 20.0f;
    sf::Texture tex;
    sf::Sprite sprite;
};


#endif //WATCH_PLAYER_H
