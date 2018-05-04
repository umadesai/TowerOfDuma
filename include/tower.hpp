#include "./waypoint.hpp"

#ifndef INCLUDE_TOWER_HPP_
#define INCLUDE_TOWER_HPP_

class Tower {
 private:
    int firerate;
    int damage;
    int range;
 public:
    // constructor and destructor
    Tower(int firerate, int damage, int range, int x, int y);
    ~Tower();
    int x;
    int y;
    bool isLegal(Waypoint *w1, Waypoint *w2);
};

#endif  // INCLUDE_TOWER_HPP_
