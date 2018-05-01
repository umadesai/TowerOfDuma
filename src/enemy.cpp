#include "../include/enemy.hpp"


Enemy::Enemy(int health, int speed, std::string spriteName, Waypoint *next,
    int x, int y) : health(health), speed(speed), spriteName(spriteName),
  next(next), x(x), y(y)
{}


Enemy::~Enemy()
{}
