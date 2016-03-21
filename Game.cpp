//
// Created by Łukasz on 2016-03-20.
//

#include <stack>

#include "Game.h"
#include "GameState.h"

void Game::pushState(GameState *state) {
    this->states.push(state);

    return;
}

void Game::popState() {
    delete this->states.top();
    this->states.pop();

    return;
}

void Game::changeState(GameState *state) {
    if (!this->states.empty())
        popState();
    pushState(state);

    return;
}

GameState *Game::peekState() {
    if (this->states.empty())
        return nullptr;
    return this->states.top();
}

void Game::gameLoop() {
    sf::Clock clock;
    sf::Time elapsed;
    float dt;

    while (this->window.isOpen()) {
        elapsed = clock.restart();
        dt = elapsed.asSeconds();

        if (peekState() == nullptr) continue;
        peekState()->handleInput();
        peekState()->update(dt);
        this->window.clear(sf::Color::Black);
        peekState()->draw(dt);
        this->window.display();
    }
}

Game::Game() {
    this->loadTextures();

    this->window.create(sf::VideoMode(1280, 720), "Watch");
    this->window.setFramerateLimit(60);

    this->background.setTexture(this->texMgr.getRef("background"));
}

Game::~Game() {
    while (!this->states.empty())
        popState();
}

void Game::loadTextures() {
    texMgr.loadTexture("background", "assets/textures/background.png");
}
