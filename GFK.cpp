// GFK.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Fractal Animator");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::RectangleShape rectangle{ { 220.f, 160.f } };
	rectangle.setFillColor(sf::Color::White);
	rectangle.setPosition({ 150.f, 20.f });
	rectangle.rotate(20.f);

	window.setFramerateLimit(60);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(rectangle);
		window.display();
	}

	return 0;
}
