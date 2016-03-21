#include "Game.h"
#include "GameStateStart.h"

int main(void) {
    Game game;

    game.pushState(new GameStateStart(&game));
    game.gameLoop();

    return 0;
}