//
// Created by Łukasz on 2016-03-20.
//

#include "SFML/Graphics.hpp"
#include "GameStatePlay.h"
	#include "DMemoryLeaks.h"

void GameStatePlay::draw(const float dt) {
    this->game->window.clear(sf::Color::Black);

    // DEBUG: SHOW X Y PLAYER POS
    sf::Text textX;
    textX.setFont(this->game->font);
    textX.setCharacterSize(24);
    textX.setColor(sf::Color::White);
    textX.setString(std::to_string(this->player.getX()) + ", tile X: " +
                    std::to_string(int(this->player.getX()) / Storage::tileSize));
    this->game->window.draw(textX);
    sf::Text textY;
    textY.setFont(this->game->font);
    textY.setCharacterSize(24);
    textY.setColor(sf::Color::White);
    textY.setPosition(sf::Vector2f(0, 30));
    textY.setString(std::to_string(this->player.getY()) + ", tile Y: " +
                    std::to_string(int(this->player.getY()) / Storage::tileSize));
    this->game->window.draw(textY);
    // DEBUG END

    this->player.draw(this->game->window);
    this->map->draw(this->game->window);

    return;
}

void GameStatePlay::update(const float dt) {
    player.update(dt, this->map);

    return;
}

void GameStatePlay::handleInput() {
    sf::Event event;

    player.move();

    while (this->game->window.pollEvent(event)) {
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
//            case sf::Event::KeyPressed: {
//                if (event.key.code == sf::Keyboard::Escape) this->game->popState();
//            }
            default:
                break;
        }
    }
}

GameStatePlay::GameStatePlay(Game *game) : player(sf::Vector2f(0, 0)) {
    this->game = game;
    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
    this->guiView.setSize(pos);
    this->gameView.setSize(pos);
    pos *= 0.5f;
    this->guiView.setCenter(pos);
    this->gameView.setCenter(pos);

    this->loadMap();
}

GameStatePlay::~GameStatePlay()
{
	if (map != NULL) delete map;
}

void GameStatePlay::loadMap() {
    this->map = new Map(50, 50);

    this->map->createTile(5, 5, Tile::ROCK);
    this->map->createTile(6, 5, Tile::ROCK);
    this->map->createTile(7, 5, Tile::ROCK);
    this->map->createTile(8, 5, Tile::ROCK);
    this->map->createTile(9, 5, Tile::ROCK);
    this->map->createTile(10, 5, Tile::ROCK);
    this->map->createTile(11, 5, Tile::ROCK);
    this->map->createTile(12, 5, Tile::ROCK);
    this->map->createTile(13, 5, Tile::ROCK);
}
