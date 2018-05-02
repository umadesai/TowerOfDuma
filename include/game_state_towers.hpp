#ifndef INCLUDE_GAME_STATE_TOWERS_HPP_
#define INCLUDE_GAME_STATE_TOWERS_HPP_

#include <SFML/Graphics.hpp>

#include "game_state.hpp"

class GameStateTowers : public GameState {
 private:
  sf::View gameView;

 public:
  virtual void draw(const float dt);
  virtual void update(const float dt);
  virtual void handleInput();

  explicit GameStateTowers(Game* game);
};

#endif  // INCLUDE_GAME_STATE_TOWERS_HPP_
