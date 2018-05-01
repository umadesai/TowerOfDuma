
#ifndef INCLUDE_WAYPOINT_HPP_
#define INCLUDE_WAYPOINT_HPP_

class Waypoint {
 private:
    int x;
    int y;
    Waypoint *next;
 public:
    Waypoint(int x, int y, Waypoint *next);
    ~Waypoint();
};

#endif  // INCLUDE_WAYPOINT_HPP_
