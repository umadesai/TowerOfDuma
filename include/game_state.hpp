#ifndef INCLUDE_GAME_STATE_HPP_
#define INCLUDE_GAME_STATE_HPP_

#include "game.hpp"

class GameState{
 public:
    Game* game;

    virtual void draw(const float dt) = 0;
    virtual void update(const float dt) = 0;
    virtual void handleInput() = 0;
};

#endif  // INCLUDE_GAME_STATE_HPP_
