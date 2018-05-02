
#ifndef INCLUDE_MAP_HPP_
#define INCLUDE_MAP_HPP_

#include "../include/tower.hpp"
#include "../include/enemy.hpp"
#include "../include/waypoint.hpp"

class Map {
 private:
    Tower *towers;
    Enemy *enemies;
    Waypoint *start;
 public:
    Map(Tower towers[], Enemy enemies[], Waypoint *start);
    ~Map();
};

#endif  // INCLUDE_MAP_HPP_
