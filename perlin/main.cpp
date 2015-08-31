#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <iostream>

int main() {
  sf::RenderWindow window(sf::VideoMode(640, 640), "Fun with Shaders");
  sf::Shader shader;
  sf::RectangleShape shape;
  shape.setSize(sf::Vector2f(640.f, 640.f));
  shape.setPosition(0.f, 0.f);
  shape.setFillColor(sf::Color::White);

  if (!shader.loadFromFile("shader.vert", sf::Shader::Vertex))
    throw std::runtime_error("Can't find file 'shader.vert'");

  if (!shader.loadFromFile("shader.frag", sf::Shader::Fragment))
    throw std::runtime_error("Can't find file 'shader.frag'");

  shader.setParameter("resolution", sf::Vector2f(640.f, 640.f));

  while(window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    std::cout << sf::Mouse::getPosition(window).y << std::endl;
    sf::Vector2f mousePosition(sf::Mouse::getPosition(window));
    mousePosition.y = 640.f - mousePosition.y;
    shader.setParameter("mousePosition", mousePosition);
    window.clear();
    window.draw(shape, &shader);
    window.display();
  }

  return 0;
}
