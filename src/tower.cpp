#include <math.h>
#include <limits>
#include "../include/tower.hpp"

double dist(double x1, double y1, double x2, double y2) {
  double a = x2 - x1;
  double b = y2 - y1;
  return sqrt((a * a) + (b * b));
}

Tower::Tower(float firerate, int damage, int range, int x, int y)
      : firerate(firerate), damage(damage), range(range), x(x), y(y),
      lastShot(-INFINITY)
{}


Tower::~Tower()
{}


bool Tower::isLegal(Waypoint *w1, Waypoint *w2) {
  int radius = 20;
  int dx = w2->x - w1->x;
  int dy = w2->y - w1->y;
  double distance = sqrt((dx*dx) + (dy*dy));
  double unitDx = dx / distance;
  double unitDy = dy / distance;
  double step = 5;
  int loopiters = ceil(distance / step);
  double x = w1->x;
  double y = w1->y;
  for (int i = 0; i < loopiters; i++) {
    if (dist(x, y, this->x, this->y) <= radius) return false;
    x += unitDx * step;
    y += unitDy * step;
  }
  if (dist(w2->x, w2->y, this->x, this->y) <= radius) return false;
  return true;
}
