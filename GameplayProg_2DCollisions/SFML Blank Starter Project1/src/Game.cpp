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

	handleCollisions();
}

/////////////////////////////////////////////////////////////

void Game::handleCollisions()
{
	// Unfortunately, this library does not provide a generic object type, and so true polymorphism isn't possible :(
	// But, I have abstracted collision checking out to a CollisionHandler class

	// AABB/Capsule
	if (CollisionHandler::resolve(m_aabbObject, m_capsuleObject))
	{
		m_aabbObject.isColliding();
		m_capsuleObject.isColliding();
		
		if (!m_msg_controller[0]) std::cout << "AABB to Capsule collision!" << std::endl;
		m_msg_controller[0] = true;
	}
	else
	{
		m_msg_controller[0] = false;
	}
	

	// AABB/Circle
	if (CollisionHandler::resolve(m_aabbObject, m_circleObject))
	{
		m_aabbObject.isColliding();
		m_circleObject.isColliding();

		if (!m_msg_controller[1]) std::cout << "AABB to Circle collision!" << std::endl;
		m_msg_controller[1] = true;
	}
	else
	{
		m_msg_controller[1] = false;
	}

	// AABB/Poly
	if (CollisionHandler::resolve(m_aabbObject, m_polyObject))
	{
		m_aabbObject.isColliding();
		m_polyObject.isColliding();

		if (!m_msg_controller[2])std::cout << "AABB to Poly collision!" << std::endl;
		m_msg_controller[2] = true;
	}
	else
	{
		m_msg_controller[2] = false;
	}

	// AABB/Ray
	if (CollisionHandler::resolve(m_aabbObject, m_rayObject))
	{
		m_aabbObject.isColliding();
		m_rayObject.isColliding();

		if (!m_msg_controller[3])std::cout << "AABB to Ray collision!" << std::endl;
		m_msg_controller[3] = true;
	}
	else
	{
		m_msg_controller[3] = false;
	}

	// Capsule/Circle
	if (CollisionHandler::resolve(m_capsuleObject, m_circleObject))
	{
		m_capsuleObject.isColliding();
		m_circleObject.isColliding();

		if (!m_msg_controller[4])std::cout << "Circle to Capsule collision!" << std::endl;
		m_msg_controller[4] = true;
	}
	else
	{
		m_msg_controller[4] = false;
	}

	// Capsule/Poly
	if (CollisionHandler::resolve(m_capsuleObject, m_polyObject))
	{
		m_capsuleObject.isColliding();
		m_polyObject.isColliding();

		if (!m_msg_controller[5])std::cout << "Capsule to Poly collision!" << std::endl;
		m_msg_controller[5] = true;
	}
	else
	{
		m_msg_controller[5] = false;
	}

	// Capsule/Ray
	if (CollisionHandler::resolve(m_capsuleObject, m_rayObject))
	{
		m_capsuleObject.isColliding();
		m_rayObject.isColliding();

		if (!m_msg_controller[6])std::cout << "Capsule to Ray collision!" << std::endl;
		m_msg_controller[6] = true;
	}
	else
	{
		m_msg_controller[6] = false;
	}

	// Circle/Poly
	if (CollisionHandler::resolve(m_circleObject, m_polyObject))
	{
		m_circleObject.isColliding();
		m_polyObject.isColliding();

		if (!m_msg_controller[7])std::cout << "Circle to Poly collision!" << std::endl;
		m_msg_controller[7] = true;
	}
	else
	{
		m_msg_controller[7] = false;
	}

	// Circle/Ray
	if (CollisionHandler::resolve(m_circleObject, m_rayObject))
	{
		m_circleObject.isColliding();
		m_rayObject.isColliding();

		if (!m_msg_controller[8])std::cout << "Circle to Ray collision!" << std::endl;
		m_msg_controller[8] = true;
	}
	else
	{
		m_msg_controller[8] = false;
	}

	// Poly/Ray
	if (CollisionHandler::resolve(m_polyObject, m_rayObject))
	{
		m_polyObject.isColliding();
		m_rayObject.isColliding();

		if (!m_msg_controller[9])std::cout << "Poly to Ray collision!" << std::endl;
		m_msg_controller[9] = true;
	}
	else
	{
		m_msg_controller[9] = false;
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