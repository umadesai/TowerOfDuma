#include <SFML/Graphics.hpp>

#include "../include/game_state_editor.hpp"

void GameStateEditor::draw(const float dt) {
  this->game->window.clear(sf::Color::Black);
  this->game->window.draw(this->game->grass);

  return;
}

void GameStateEditor::update(const float dt) { return; }

void GameStateEditor::handleInput() {
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
      gameView.setSize(event.size.width, event.size.height);
      guiView.setSize(event.size.width, event.size.height);
      this->game->grass.setPosition(this->game->window.mapPixelToCoords(
          sf::Vector2i(0, 0), this->guiView));
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
    default:
      break;
    }
  }

  return;
}

GameStateEditor::GameStateEditor(Game *game) {
  this->game = game;
  sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
  this->guiView.setSize(pos);
  this->gameView.setSize(pos);
  this->game->grass.setPosition(this->game->window.mapPixelToCoords(
        sf::Vector2i(0, 0)));
  this->game->grass.setScale(
      static_cast<float>(pos.x) / static_cast<float>(
        this->game->grass.getTexture()->getSize().x),
      static_cast<float>(pos.y) / static_cast<float>(
        this->game->grass.getTexture()->getSize().y));
  pos *= 0.5f;
  this->guiView.setCenter(pos);
  this->gameView.setCenter(pos);
}
