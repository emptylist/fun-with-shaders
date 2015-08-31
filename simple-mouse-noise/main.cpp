#include <SFML/Graphics.hpp>
#include <stdexcept>

int main() {
  sf::RenderWindow window(sf::VideoMode(640, 640), "Fun with Shaders");
  window.setFramerateLimit(60);

  sf::Shader shader;
  sf::RectangleShape shape;
  
  shape.setSize(sf::Vector2f(640.f, 640.f));
  shape.setPosition(0.f, 0.f);
  shape.setFillColor(sf::Color::White);

  if (!shader.loadFromFile("shader.frag", sf::Shader::Fragment))
    throw std::runtime_error("Can't find file 'shader.frag'");

  float time = 0.f;
  while(window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    shader.setParameter("mousePosition", sf::Vector2f(sf::Mouse::getPosition()));
    window.clear();
    window.draw(shape, &shader);
    window.display();
    time += 1.f / 60.f;
    if (time >= 60.f)
      time -= 60.f;
  }

  return 0;
}
