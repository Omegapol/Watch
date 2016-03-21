//
// Created by Łukasz on 2016-03-20.
//

#include "GameStatePlay.h"

void GameStatePlay::draw(const float dt) {
    this->game->window.draw(this->game->background);

    return;
}

void GameStatePlay::update(const float dt) {
    return;
}

void GameStatePlay::handleInput() {
    sf::Event event;

    while(this->game->window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed: {
                this->game->window.close();
                break;
            }
            case sf::Event::Resized: {
                gameView.setSize(event.size.width, event.size.height);
                guiView.setSize(event.size.width, event.size.height);
                break;
                // TODO: Dokończyć później
            }
            case sf::Event::KeyPressed: {
                if (event.key.code == sf::Keyboard::Escape) this->game->popState();
            }
            default: break;
        }
    }
}

GameStatePlay::GameStatePlay(Game *game) {
    this->game = game;
    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
    this->guiView.setSize(pos);
    this->gameView.setSize(pos);
    pos *= 0.5f;
    this->guiView.setCenter(pos);
    this->gameView.setCenter(pos);
}
