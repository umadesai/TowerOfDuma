#ifndef INCLUDE_GAME_HPP_
#define INCLUDE_GAME_HPP_

#include <stack>
#include <SFML/Graphics.hpp>

class GameState;

class Game {
 public:
    std::stack<GameState*> states;

    sf::RenderWindow window;

    void pushState(GameState* state);
    void popState();
    void changeState(GameState* state);
    GameState* peekState();

    void gameLoop();

    Game();
    ~Game();
};

#endif  // INCLUDE_GAME_HPP_
