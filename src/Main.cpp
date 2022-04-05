#include "Game/Game.hpp"
#include "Platform/Platform.hpp"
#include "utils/logger/logger.hpp"

int main()
{
	util::Platform platform;

#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	Game game;

	while (game.running())
	{
		game.update();
		game.render();
	}

	return 0;
}
