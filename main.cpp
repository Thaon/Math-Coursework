#include <windows.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <string>
#include <sstream>
#include <math.h>

int CALLBACK WinMain(
	HINSTANCE   hInstance,
	HINSTANCE   hPrevInstance,
	LPSTR       lpCmdLine,
	int         nCmdShow
	)
{
	//position of the circle that represents the projectile
	float x, y, time, tau;

	//mouse coordinates
	float mouse_x, mouse_y;

	sf::RenderWindow window(sf::VideoMode(200, 200), "Math coursework");
	sf::CircleShape shape(10.f);

	//load in a font to draw text on screen
	sf::Font font;
	if (!font.loadFromFile("Prototype.ttf"))
		return -1;

	sf::Text coordinates;

	x = 100;
	y = 100;
	time = 0;
	tau = 0.1;

	coordinates.setFont(font);
	coordinates.setPosition(10, 180);
	coordinates.setCharacterSize(20);
	coordinates.setColor(sf::Color::White);

	shape.setPosition(x, y);
	shape.setFillColor(sf::Color::Blue);

	while (window.isOpen())
	{
		//we handle events and keypresses here
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}

				if (event.key.code == sf::Keyboard::Space)
				{
					time += tau;
				}
			}

			//mouse events are handled here, we will use these to check if a button is pressed
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					mouse_x = event.mouseButton.x;
					mouse_y = event.mouseButton.y;
				}
			}
			
			//updating x and y

		}

		//update x, y and time
		x += 1931.85 - 1931.85* std::exp(-0.01*time);

		y -= 98627.74 - 98617.64*std::exp(-0.01*time) - 981 * time;

		//time += tau;
		
		//display coordinates on screen, need to convert them to string first, using a string stream
		std::stringstream ss(std::stringstream::in | std::stringstream::out);
		ss << x;
		std::string strX = ss.str();

		std::stringstream ss2(std::stringstream::in | std::stringstream::out);
		ss2 << y;
		std::string strY = ss2.str();

		coordinates.setString("x = " + strX + "; y = " + strY);

		//reset time after a while
		if (time > 2)
			time = 0;

		//move the projectile
		shape.move(x, y);

		window.clear();

		//draw our canvas and the circle
		window.draw(coordinates);
		window.draw(shape);
		
		window.display();
	}

	return 0;
}