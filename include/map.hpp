
#ifndef INCLUDE_MAP_HPP_
#define INCLUDE_MAP_HPP_

#include<vector>
#include "../include/tower.hpp"
#include "../include/enemy.hpp"
#include "../include/waypoint.hpp"

class Map {
 private:
    std::vector<Tower> towers;
    std::vector<Enemy> enemies;
    Waypoint *start;
 public:
    Map(std::vector<Tower> towers, std::vector<Enemy> enemies, Waypoint *start);
    ~Map();
};

#endif  // INCLUDE_MAP_HPP_
