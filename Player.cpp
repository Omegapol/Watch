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
    sf::Vector2f offset = sf::Vector2f(this->moveVec.x * this->playerSpeed * dt,
                                       this->moveVec.y * this->playerSpeed * dt);
    if (map->isCollideable(0, this->pos.y + offset.y)) {
        this->moveVec = sf::Vector2f(0, 0);
        return;
    }
    this->sprite.move(offset);
    this->pos += offset;
    this->moveVec = sf::Vector2f(0, 0);
    return;
}

Player::Player(sf::Vector2f pos, sf::Texture &texture) : pos(pos), tex(texture) {
    this->sprite.setTexture(this->tex);
    this->sprite.setPosition(pos);
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(this->sprite);
}
