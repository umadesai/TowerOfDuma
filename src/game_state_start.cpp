#include <SFML/Graphics.hpp>

#include "../include/game_state_start.hpp"

void GameStateStart::draw(const float dt) {
  this->game->window.setView(this->view);

  this->game->window.clear(sf::Color::Black);
  sf::Font font;
  font.loadFromFile("fonts/arial.ttf");
  sf::Text text("Press Space to Begin Game", font, 30);
  text.setPosition(sf::Vector2f(200, 275));
  text.setColor(sf::Color::White);
  this->game->window.draw(text);

  return;
}

void GameStateStart::update(const float dt) {}

void GameStateStart::handleInput() {
  sf::Event event;

  while (this->game->window.pollEvent(event)) {
    switch (event.type) {
    /* Close the window */
    case sf::Event::Closed: {
      game->window.close();
      break;
    }
    /* Resize the window */
    case sf::Event::Resized: {
      this->view.setSize(event.size.width, event.size.height);
      break;
    }
    case sf::Event::KeyPressed: {
      if (event.key.code == sf::Keyboard::Escape)
        this->game->window.close();
      else if (event.key.code == sf::Keyboard::Space)
        this->loadgame();
      break;
    }
    default:
      break;
    }
  }

  return;
}

GameStateStart::GameStateStart(Game *game) {
  this->game = game;
  sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
  this->view.setSize(pos);
  pos *= 0.5f;
  this->view.setCenter(pos);
}

void GameStateStart::loadgame() {
  this->game->pushState(new GameStateTowers(this->game));

  return;
}
