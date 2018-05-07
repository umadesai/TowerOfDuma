#include <iostream>
#include <SFML/Graphics.hpp>

#include "../include/game_state_towers.hpp"


void GameStateTowers::draw(const float dt) {
  this->game->window.setView(this->gameView);
  this->game->window.clear(sf::Color::Black);
  this->game->window.draw(this->game->grass);
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
      this->game->grass.setPosition(this->game->window.mapPixelToCoords(
          sf::Vector2i(0, 0), this->gameView));
      this->game->grass.setScale(
          static_cast<float>(event.size.width) /
              static_cast<float>(
                  this->game->grass.getTexture()->getSize().x),
          static_cast<float>(event.size.height) /
              static_cast<float>(
                  this->game->grass.getTexture()->getSize().y));
      break;
    }
    case sf::Event::KeyPressed: {
      if (event.key.code == sf::Keyboard::Escape)
        this->game->window.close();
      break;
    }
    case sf::Event::MouseButtonPressed: {
      if (event.mouseButton.button == sf::Mouse::Left) {
        // print mouse click positions in pixels, absolute
        std::cout << "mouse x: " << event.mouseButton.x << std::endl;
        std::cout << "mouse y: " << event.mouseButton.y << std::endl;
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
  this->game->grass.setPosition(this->game->window.mapPixelToCoords(
        sf::Vector2i(0, 0)));
  this->game->grass.setScale(
      static_cast<float>(pos.x) / static_cast<float>(
        this->game->grass.getTexture()->getSize().x),
      static_cast<float>(pos.y) / static_cast<float>(
        this->game->grass.getTexture()->getSize().y));
  pos *= 0.5f;
  this->gameView.setCenter(pos);
  std::vector<Tower*> towers;
  std::vector<Enemy*> enemies;
  Waypoint *start = new Waypoint(0, 50);
  this->map = new Map(towers, enemies, start);
}
