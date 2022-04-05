#include "Game.hpp"
#include "../utils/logger/logger.hpp"

Game::Game()
{
	this->initVariables();
	this->initWindow();
}

void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.width = 800;
	this->videoMode.height = 600;
	this->window = new sf::RenderWindow(this->videoMode, "Game 1", sf::Style::Titlebar | sf::Style::Close);
}

bool Game::running() const
{
	return this->window->isOpen();
}

void  Game::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		if (
			this->event.type == sf::Event::Closed ||
				(
					this->event.type == sf::Event::KeyPressed &&
					this->event.key.code == sf::Keyboard::Escape
				)
			)
		{
			this->window->close();
		}
	}
}

void Game::update()
{
	slog("Updating");
	this->pollEvents();
}

void Game::render()
{
	slog("Rendering");
	this->window->clear(sf::Color(30,30,30, 255));
	this->window->display();
}

Game::~Game()
{
	delete this->window;
}