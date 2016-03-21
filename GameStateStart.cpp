//
// Created by Łukasz on 2016-03-20.
//

#include "GameStateStart.h"
#include "GameStatePlay.h"

void GameStateStart::draw(const float dt) {
    this->game->window.setView(this->view);
    this->game->window.draw(this->game->background);

    return;
}

void GameStateStart::update(const float dt) {
    return;
}

void GameStateStart::handleInput() {
    sf::Event event;

    while (this->game->window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed: {
                game->window.close();
                break;
            }
            case sf::Event::Resized: {
                this->view.setSize(event.size.width, event.size.height);
                break;
                // TODO: Uzupełnić resztę
            }
            case sf::Event::KeyPressed: {
                if (event.key.code == sf::Keyboard::Escape) game->window.close();
                if (event.key.code == sf::Keyboard::Space) this->loadGame();
                break;
            }
            default:
                break;
        }
    }

    return;
}

GameStateStart::GameStateStart(Game *game) {
    this->game = game;
    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
    this->view.setSize(pos);
    pos *= 0.5f;
    this->view.setCenter(pos);
}

void GameStateStart::loadGame() {
    this->game->pushState(new GameStatePlay(this->game));
}
