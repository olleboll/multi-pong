#pragma once

/*
	Game base class
*/
class Game
{
private:

	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	void initVariables();
	void initWindow();

public:
	Game();
	virtual ~Game();

	void run();
	bool running() const;
	void pollEvents();
	void update();
	void render();
};
