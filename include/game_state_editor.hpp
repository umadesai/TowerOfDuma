#ifndef INCLUDE_GAME_STATE_EDITOR_HPP_
#define INCLUDE_GAME_STATE_EDITOR_HPP_

#include <SFML/Graphics.hpp>

#include "game_state.hpp"

class GameStateEditor : public GameState {
 private:
  sf::View gameView;
  sf::View guiView;

 public:
  virtual void draw(const float dt);
  virtual void update(const float dt);
  virtual void handleInput();

  explicit GameStateEditor(Game* game);
};

#endif  // INCLUDE_GAME_STATE_EDITOR_HPP_
