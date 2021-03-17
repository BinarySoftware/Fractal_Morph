/*
 * Fractal Explorer
 *
 * Program do obserwowania afinicznej transformacji jednego rodzaju fraktala w drugi.
 * C2021 Jan Paluch, Wiktoria Szewczyk, Maciej Mikołajek.
 */


#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


 /**
   * Poczatek programu.
   */
int main() {
	int screenWidth = sf::VideoMode::getDesktopMode().width;
	int screenHeight = sf::VideoMode::getDesktopMode().height;

	sf::RenderWindow window(sf::VideoMode(screenWidth / 2, screenHeight / 2), "Fractal Explorer", sf::Style::Titlebar | sf::Style::Close);
	sf::Event event;

	sf::VertexArray points(sf::Points, 1);

	window.setFramerateLimit(240);

	bool isPressedLmb = false;
	sf::Color currentColor = sf::Color::Black;

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				isPressedLmb = true;
			}

			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::G) { currentColor = sf::Color::Green; }
				if (event.key.code == sf::Keyboard::R) { currentColor = sf::Color::Red; }
				if (event.key.code == sf::Keyboard::B) { currentColor = sf::Color::Blue; }
				if (event.key.code == sf::Keyboard::Space) { currentColor = sf::Color::Black; }
			}

			if (event.type == sf::Event::MouseMoved && isPressedLmb) {
				for (int i = 0; i <= 3; i++) {
					for (int j = 0; j <= 3; j++) {
						sf::Vertex v(sf::Vector2f((float)event.mouseMove.x + i, (float)event.mouseMove.y + j), currentColor);
						points.append(v);
					}
				}
			}

			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
				isPressedLmb = false;
			}
		}

		window.clear(sf::Color(250, 250, 250));

		window.draw(points);

		window.display();
	}

	return 0;
}
