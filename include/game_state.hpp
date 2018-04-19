<<<<<<< HEAD
#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "game.hpp"

class GameState
{
    public:

=======
#ifndef INCLUDE_GAME_STATE_HPP_
#define INCLUDE_GAME_STATE_HPP_

#include "game.hpp"

class GameState {
 public:
>>>>>>> lint_errors
    Game* game;

    virtual void draw(const float dt) = 0;
    virtual void update(const float dt) = 0;
    virtual void handleInput() = 0;
};

<<<<<<< HEAD
#endif /* GAME_STATE_HPP */
=======
#endif  // INCLUDE_GAME_STATE_HPP_
>>>>>>> lint_errors
