#include <math.h>
#include "../include/enemy.hpp"


Enemy::Enemy(int health, int speed, std::string spriteName, Waypoint *next,
    float x, float y) : health(health), speed(speed), spriteName(spriteName),
  next(next), x(x), y(y)
{}


Enemy::~Enemy()
{}

bool Enemy::move(const float dt) {
  float dx = this->next->x - this->x;
  float dy = this->next->y - this->y;
  float distanceToTravel = dt * speed;
  float wayPointDist = sqrt(dx * dx + dy * dy);
  if (distanceToTravel >= wayPointDist) {
    // if we are close enough to the next waypoint, set our current location to
    // the next waypoint's location, and move our waypoint pointer forward
    this->x = next->x;
    this->y = next->y;
    this->next = next->next;
  } else {
    float unitDx = dx / wayPointDist;
    float unitDy = dy / wayPointDist;
    this->x = this->x + (unitDx * distanceToTravel);
    this->y = this->y + (unitDy * distanceToTravel);
  }
  if (this->next) {
    // if we have not reached our goal
    return false;
  }
  return true;
}
