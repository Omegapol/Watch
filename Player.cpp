//
// Created by Łukasz on 2016-03-21.
//

#include "Player.h"

void Player::move() {
    sf::Vector2f offsetVec;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        offsetVec += sf::Vector2f(0, -10);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        offsetVec += sf::Vector2f(0, 10);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        offsetVec += sf::Vector2f(-10, 0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        offsetVec += sf::Vector2f(10, 0);

    this->moveVec += offsetVec;
}

void Player::update(float dt, Map *map) {
    int repeats = 0;
    sf::Vector2f offset = sf::Vector2f(this->moveVec.x * this->playerSpeed * dt,
                                       this->moveVec.y * this->playerSpeed * dt);
    sf::Sprite futurePos = this->sprite;
    while (map->isCollideable(this->pos.x, this->pos.y, futurePos, offset)) {
        offset = 0.7f * offset;
        repeats++;
        if (repeats > 5) {
            this->moveVec = sf::Vector2f(0, 0);
            return;
        }
    }
    this->sprite.move(offset);
    this->pos += offset;
    this->moveVec = sf::Vector2f(0, 0);
    return;
}

Player::Player(sf::Vector2f pos) : pos(pos) {
    this->tex = Storage::texMgr.getRef("player");
    this->sprite.setTexture(this->tex, true);
    this->sprite.setPosition(pos);
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(this->sprite);
}
