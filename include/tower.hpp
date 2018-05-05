
#include <iostream>
#include <SFML/System.hpp>
#include "./waypoint.hpp"

#ifndef INCLUDE_TOWER_HPP_
#define INCLUDE_TOWER_HPP_

class Tower {
 private:
    int damage;
 public:
    // constructor and destructor
    Tower(float firerate, int damage, int range, int x, int y);
    ~Tower();
    int x;
    int y;
    int range;
    float firerate;
    bool isLegal(Waypoint *w1, Waypoint *w2);
};

#endif  // INCLUDE_TOWER_HPP_
