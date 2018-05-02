#include <SFML/Graphics.hpp>

#include "../include/game_state_towers.hpp"

void GameStateTowers::draw(const float dt) {
  this->game->window.setView(this->gameView);
  this->game->window.clear(sf::Color::Black);
  this->game->window.draw(this->game->background);

  return;
}

void GameStateTowers::update(const float dt) { return; }

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
      this->game->background.setPosition(this->game->window.mapPixelToCoords(
          sf::Vector2i(0, 0), this->gameView));
      this->game->background.setScale(
          static_cast<float>(event.size.width) /
              static_cast<float>(
                  this->game->background.getTexture()->getSize().x),
          static_cast<float>(event.size.height) /
              static_cast<float>(
                  this->game->background.getTexture()->getSize().y));
      break;
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
}
