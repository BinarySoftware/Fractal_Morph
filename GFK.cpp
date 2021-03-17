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
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Fractal Explorer", sf::Style::Titlebar | sf::Style::Close);
	sf::Event event;

	sf::VertexArray points(sf::Points, 1);

	window.setFramerateLimit(60);

	bool isPressedLmb = false;

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				isPressedLmb = true;
			}

			if (event.type == sf::Event::MouseMoved && isPressedLmb) {
				sf::Vertex v(sf::Vector2f(event.mouseMove.x, event.mouseMove.y), sf::Color(0, 0, 0));
				points.append(v);
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
