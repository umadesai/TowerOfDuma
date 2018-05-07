
#ifndef INCLUDE_MAP_HPP_
#define INCLUDE_MAP_HPP_

#include<vector>
#include <SFML/Graphics.hpp>
#include "../include/tower.hpp"
#include "../include/enemy.hpp"
#include "../include/waypoint.hpp"
#include "../include/shot.hpp"
#include "../include/sf_line.hpp"
#include "../include/game.hpp"

class Map {
 private:
    std::vector<Tower*> towers;
    sf::Font font;
    int currency;
 public:
    Game* game;
    Waypoint *start;
    int lives;
    float totalTime;
    void draw(sf::RenderWindow *window, Waypoint *start);
    Map(std::vector<Tower*> towers, std::vector<Enemy*> enemies,
        Waypoint *start, Game* game);
    void addTower(int x, int y);
    std::vector<Enemy*> enemies;
    std::vector<Shot> shots;
    void update(const float dt);
    ~Map();
};

#endif  // INCLUDE_MAP_HPP_
