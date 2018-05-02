#ifndef INCLUDE_GAME_STATE_START_HPP_
#define INCLUDE_GAME_STATE_START_HPP_

#include <SFML/Graphics.hpp>

#include "game_state.hpp"
#include "game_state_towers.hpp"

class GameStateStart : public GameState {
 private:
  sf::View view;

    void loadgame();

 public:
    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

    explicit GameStateStart(Game* game);
};

#endif  // INCLUDE_GAME_STATE_START_HPP_
