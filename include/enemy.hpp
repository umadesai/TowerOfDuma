#include <string>

#ifndef INCLUDE_ENEMY_HPP_
#define INCLUDE_ENEMY_HPP_

#include "./waypoint.hpp"

class Enemy {
 private:
    int speed;
    std::string spriteName;
    Waypoint *next;  // waypoint enemy is currently navigating toward
 public:
    Enemy(int health, int speed, std::string spriteName, Waypoint *next,
        float x, float y);
    ~Enemy();
    float x;  // store center of enemy in x, y coordinates
    float y;
    int health;
    bool move(const float dt);  // returns true if the enemy has reached its
                                // goal
};

#endif  // INCLUDE_ENEMY_HPP_
