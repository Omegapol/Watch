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

void Player::update(float dt) {
    sf::Vector2f offset = sf::Vector2f(moveVec.x * playerSpeed * dt, moveVec.y * playerSpeed * dt);
    sprite.move(offset);
    this->pos += offset;
    moveVec = sf::Vector2f(0, 0);
}

Player::Player(sf::Vector2f pos, sf::Texture &texture) : pos(pos), tex(texture) {
    sprite.setTexture(tex);
    sprite.setPosition(pos);
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}
