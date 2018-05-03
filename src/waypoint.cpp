
#include "../include/waypoint.hpp"

Waypoint::Waypoint(int x, int y, Waypoint *next)
         : x(x), y(y), next(next)
{}

Waypoint::Waypoint(int x, int y)
         : x(x), y(y), next(nullptr)
{}


Waypoint::~Waypoint()
{}
