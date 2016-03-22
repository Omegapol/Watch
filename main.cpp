
//Set _DEBUG if you want to detect memory leaks.
#ifdef _DEBUG   
	#define _CRTDBG_MAP_ALLOC
	#include <stdlib.h>
	#include <crtdbg.h>
	#include "DMemoryLeaks.h"
#endif  // _DEBUG

#include "Game.h"
#include "GameStateStart.h"

int main(void) {

#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    Game game;
    game.pushState(new GameStateStart(&game));
    game.gameLoop();

    return 0;
}