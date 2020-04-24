#include "Game.h"

//Create our Game object
Game* g_game = 0;

int main(int argc, char* args[])
{
	g_game = new Game();

	g_game->init("Example 10-05: Collision", 100,100,800,600,false);

	g_game->prepare();

	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
		g_game->waitForNextFrame();
	}

	g_game->cleanup();

	return 0;
}






