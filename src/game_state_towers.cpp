#include <SFML/Graphics.hpp>

#include "../include/game_state_towers.hpp"


void GameStateTowers::draw(const float dt) {
  this->game->window.setView(this->gameView);
  this->game->window.clear(sf::Color::Black);
  map->draw(&this->game->window, map->start);

  return;
}

void GameStateTowers::update(const float dt) {
  this->map->update(dt);
  return;
}

void GameStateTowers::handleInput() {
  sf::Event event;

  while (this->game->window.pollEvent(event)) {
    switch (event.type) {
    /* Close the window */
    case sf::Event::Closed: {
      this->game->window.close();
      break;
    }
    /* Resize the window */
    case sf::Event::Resized: {
      this->gameView.setSize(event.size.width, event.size.height);
      break;
    }
    case sf::Event::KeyPressed: {
      if (event.key.code == sf::Keyboard::Escape)
        this->game->window.close();
      break;
    }
    case sf::Event::MouseButtonPressed: {
      if (event.mouseButton.button == sf::Mouse::Left) {
        int x = event.mouseButton.x;
        int y = event.mouseButton.y;
        this->map->addTower(x, y);
      }
    }
    default:
      break;
    }
  }

  return;
}

GameStateTowers::GameStateTowers(Game *game) {
  this->game = game;
  sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
  this->gameView.setSize(pos);
  pos *= 0.5f;
  this->gameView.setCenter(pos);
  std::vector<Tower*> towers;
  std::vector<Enemy*> enemies;
  Waypoint *start = new Waypoint(0, 50);
  this->map = new Map(towers, enemies, start, this->game);
}
