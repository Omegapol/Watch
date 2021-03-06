//
// Created by Łukasz on 2016-03-20.
//
#include "Game.h"
#include "GameState.h"

#include "DMemoryLeaks.h"

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
	TextureManager::setTexStorage(new std::map<std::string, sf::Texture>);
    this->loadTextures();

    this->window.create(sf::VideoMode(1280, 720), "Watch");
    this->window.setFramerateLimit(60);

    this->background.setTexture(TextureManager::getRef("background"));

    this->font.loadFromFile("assets/fonts/OpenSans-Light.ttf");
}

Game::~Game() {
    while (!this->states.empty())
        popState();
	TextureManager::destroyTexStorage();
}

void Game::loadTextures() {
    TextureManager::loadTexture("background", "assets/textures/background.png");
	TextureManager::loadTexture("player", "assets/textures/player.png");
	TextureManager::loadTexture("rock-texture", "assets/textures/rock-texture.png");
}
