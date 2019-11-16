#include "Game.h"

/// <summary>
/// Default Constructor
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "2D Collisions", sf::Style::Close },
	m_exitGame{ false }
{
}

/// <summary>
/// Default Destructor
/// </summary>
Game::~Game()
{
}

/// <summary>
/// Main run method
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f); // run at 60fps
	srand(static_cast<unsigned>(time(nullptr)));

	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timePerFrame);
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type)
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
		}
	}
}

void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
}

void Game::render()
{
	m_window.clear(sf::Color::White);
	m_window.display();
}
