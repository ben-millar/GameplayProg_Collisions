#define TINYC2_IMPL
#include "Game.h"

/// <summary>
/// Default Constructor
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "2D Collisions", sf::Style::Close },
	m_exitGame{ false }
{
	p_objArray = { &m_aabbObject, &m_capsuleObject, &m_circleObject, &m_polyObject, &m_rayObject };

	for (auto p : p_objArray)
	{
		p->init();
	}
}

/////////////////////////////////////////////////////////////

/// <summary>
/// Default Destructor
/// </summary>
Game::~Game()
{
}

/////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////

void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}

	for (auto p : p_objArray)
	{
		p->update(t_deltaTime);
	}

	collisionHandler();
}

/////////////////////////////////////////////////////////////

void Game::collisionHandler()
{
	// Unfortunately, this library does not provide a generic object type, and so true polymorphism isn't possible :(

	// AABB/Capsule
	if (c2AABBtoCapsule(*m_aabbObject.getBounds(), *m_capsuleObject.getBounds()))
	{
		std::cout << "AABB to Capsule collision!" << std::endl;
	}

	// AABB/Circle
	if (c2CircletoAABB(*m_circleObject.getBounds(), *m_aabbObject.getBounds()))
	{
		std::cout << "AABB to Circle collision!" << std::endl;
	}

	// AABB/Poly
	if (c2AABBtoPoly(*m_aabbObject.getBounds(), m_polyObject.getBounds(), nullptr))
	{
		std::cout << "AABB to Poly collision!" << std::endl;
	}

	// AABB/Ray
	if (c2RaytoAABB(*m_rayObject.getBounds(), *m_aabbObject.getBounds(), nullptr))
	{
		std::cout << "AABB to Ray collision!" << std::endl;
	}

	// Capsule/Circle
	if (c2CircletoCapsule(*m_circleObject.getBounds(), *m_capsuleObject.getBounds()))
	{
		std::cout << "Circle to Capsule collision!" << std::endl;
	}

	// Capsule/Poly
	if (c2CapsuletoPoly(*m_capsuleObject.getBounds(), m_polyObject.getBounds(), nullptr))
	{
		std::cout << "Capsule to Poly collision!" << std::endl;
	}

	// Capsule/Ray
	if (c2RaytoCapsule(*m_rayObject.getBounds(), *m_capsuleObject.getBounds(), nullptr))
	{
		std::cout << "Capsule to Ray collision!" << std::endl;
	}

	// Circle/Poly
	if (c2CircletoPoly(*m_circleObject.getBounds(), m_polyObject.getBounds(), nullptr))
	{
		std::cout << "Circle to Poly collision!" << std::endl;
	}

	// Circle/Ray
	if (c2RaytoCircle(*m_rayObject.getBounds(), *m_circleObject.getBounds(), nullptr))
	{
		std::cout << "Circle to Ray collision!" << std::endl;
	}

	// Poly/Ray
	if (c2RaytoPoly(*m_rayObject.getBounds(), m_polyObject.getBounds(), nullptr, nullptr))
	{
		std::cout << "Poly to Ray collision!" << std::endl;
	}
	
}

/////////////////////////////////////////////////////////////

void Game::render()
{
	m_window.clear(sf::Color::Black);

	for (auto p : p_objArray)
	{
		p->draw(m_window);
	}

	m_window.display();
}