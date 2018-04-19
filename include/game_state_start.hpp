<<<<<<< HEAD
#ifndef GAME_STATE_START_HPP
#define GAME_STATE_START_HPP
=======
#ifndef INCLUDE_GAME_STATE_START_HPP_
#define INCLUDE_GAME_STATE_START_HPP_
>>>>>>> lint_errors

#include <SFML/Graphics.hpp>

#include "game_state.hpp"
#include "game_state_editor.hpp"

<<<<<<< HEAD
class GameStateStart : public GameState
{
    private:

    sf::View view;

    void loadgame();

    public:

=======
class GameStateStart : public GameState {
 private:
  sf::View view;

    void loadgame();

 public:
>>>>>>> lint_errors
    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

<<<<<<< HEAD
    GameStateStart(Game* game);
};

#endif /* GAME_STATE_START_HPP */
=======
    explicit GameStateStart(Game* game);
};

#endif  // INCLUDE_GAME_STATE_START_HPP_
>>>>>>> lint_errors
