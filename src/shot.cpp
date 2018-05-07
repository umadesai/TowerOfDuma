#include "../include/shot.hpp"

Shot::Shot(int x1, int y1, int x2, int y2, float timecreated)
      : x1(x1), x2(x2), y1(y1), y2(y2), lifespan(0.05), timecreated(timecreated)
{}


Shot::~Shot()
{}
