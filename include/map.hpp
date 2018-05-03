
#ifndef INCLUDE_MAP_HPP_
#define INCLUDE_MAP_HPP_

#include<vector>
#include <SFML/Graphics.hpp>
#include "../include/tower.hpp"
#include "../include/enemy.hpp"
#include "../include/waypoint.hpp"

class Map {
 private:
    std::vector<Tower> towers;
 public:
    Waypoint *start;
    void draw(sf::RenderWindow *window, Waypoint *start);
    Map(std::vector<Tower> towers, std::vector<Enemy*> enemies,
        Waypoint *start);
    void addTower(int x, int y);
    std::vector<Enemy*> enemies;
    void update(const float dt);
    ~Map();
};

#endif  // INCLUDE_MAP_HPP_
