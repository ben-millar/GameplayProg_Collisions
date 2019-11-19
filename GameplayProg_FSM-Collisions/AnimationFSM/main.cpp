// Session 1 Start: 11:30 End: 13:00
// Session 2 Start: 15:00 End: 16:30
// Session 3 Start: 22:30 End: 01:28
// Session 4 Start: 21:30 End: 23:50
// Total Time: 8:18

#define TINYC2_IMPL

#include <iostream>
#include <SFML/Graphics.hpp>
#include <AnimatedSprite.h>
#include <Player.h>
#include <Input.h>
#include <Debug.h>


using namespace std;

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("assets\\FSM_spritesheet_new.png")) {
		DEBUG_MSG("Failed to load file");
		return EXIT_FAILURE;
	}

	sf::RectangleShape m_box;
	m_box.setFillColor(sf::Color::Red);
	m_box.setSize({ 40.0f,120.0f });
	m_box.setPosition({ 400.0f, 160.0f });

	c2AABB m_boxBounds;
	m_boxBounds.min.x = m_box.getPosition().x;
	m_boxBounds.max.x = m_box.getPosition().x + m_box.getSize().x;

	m_boxBounds.min.y = m_box.getPosition().y;
	m_boxBounds.max.y = m_box.getPosition().y + m_box.getSize().y;

	bool msg_controller{ false };

	// Setup Players Default Animated Sprite
	AnimatedSprite animated_sprite(texture);
	animated_sprite.addFrame(sf::IntRect(0,0,200,200));
	animated_sprite.addFrame(sf::IntRect(200, 0, 200, 200));
	animated_sprite.setOrigin({ 100.0f,100.0f });
	animated_sprite.setPosition({ 200.0f,200.0f });

	// Setup the Player
	Player player(animated_sprite);
	Input input;
	
	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				// Close window : exit
				window.close();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					window.close();
					break;
				case sf::Keyboard::Up:
					input.setCurrent(Input::Action::UP);
					break;
				case sf::Keyboard::Down:
					input.setCurrent(Input::Action::DOWN);
					break;
				case sf::Keyboard::Left:
					input.setCurrent(Input::Action::LEFT);
					break;
				case sf::Keyboard::Right:
					input.setCurrent(Input::Action::RIGHT);
					break;
				case sf::Keyboard::Space:
					input.setCurrent(Input::Action::JUMP);
					break;
				} // end switch

				// if key pressed, send input to player
				player.setInput(input);
				break;
			default:
				input.setCurrent(Input::Action::DEFAULT);
				break;
			} // end switch
		}

		// Handle input to Player if key pressed
		player.handleInput();

		// Update the Player
		player.update();

		// Collision checking
		if (c2AABBtoAABB(m_boxBounds, player.m_boundingBox))
		{
			if (!msg_controller) std::cout << "Player collided with box!" << std::endl;

			m_box.setFillColor(sf::Color::Yellow);
			msg_controller = true;
		}
		else
		{
			m_box.setFillColor(sf::Color::Red);

			msg_controller = false;
		}

		// Clear screen
		window.clear();

		window.draw(m_box);

		// Draw the Players Current Animated Sprite
		window.draw(player.getAnimatedSprite());

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
};