#include <string>

#ifndef INCLUDE_ENEMY_HPP_
#define INCLUDE_ENEMY_HPP_

#include "./waypoint.hpp"

class Enemy {
 private:
    int health;
    int speed;
    std::string spriteName;
    Waypoint *next;  // waypoint enemy is currently navigating toward
    int x;  // store center of enemy in x, y coordinates
    int y;
 public:
    Enemy(int health, int speed, std::string spriteName, Waypoint *next, int x,
        int y);
    ~Enemy();
};

#endif  // INCLUDE_ENEMY_HPP_
