
#include <iostream>

#include "../include/map.hpp"

void Map::draw(sf::RenderWindow *window, Waypoint *start) {
  for (auto tower : this->towers) {
    int radius = 20;
    sf::CircleShape shape(radius);
    shape.setFillColor(sf::Color(255, 0, 50));  // red
    shape.setPosition(tower.x - radius, tower.y - radius);
    window->draw(shape);
  }
}

void Map::addTower(int x, int y) {
  Tower t(1, 1, 50, x, y);
  this->towers.push_back(t);
  std::cout << "new tower!" << std::endl;
}

Map::Map(std::vector<Tower> towers, std::vector<Enemy> enemies, Waypoint *start)
      : towers(towers), enemies(enemies), start(start) {
  Waypoint *curr = start;
  for (int i = 0; i <= 750; i+=50) {
    Waypoint *next = new Waypoint(i, i);
    curr->next = next;
    curr = curr->next;
  }
}


Map::~Map()
{}
