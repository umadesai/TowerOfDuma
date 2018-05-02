
#ifndef INCLUDE_WAYPOINT_HPP_
#define INCLUDE_WAYPOINT_HPP_

class Waypoint {
 public:
    int x;
    int y;
    Waypoint *next;
    Waypoint(int x, int y, Waypoint *next);
    Waypoint(int x, int y);
    ~Waypoint();
};

#endif  // INCLUDE_WAYPOINT_HPP_
