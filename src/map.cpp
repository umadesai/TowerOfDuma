
#include <iostream>

#include "../include/map.hpp"

void Map::draw(sf::RenderWindow *window, Waypoint *start) {
  Waypoint *curr = start;
  sf::VertexArray lines(sf::LinesStrip, 9);
  lines[0].position = sf::Vector2f(curr->x, curr->y);
  curr = curr->next;
  lines[1].position = sf::Vector2f(curr->x, curr->y);
  curr = curr->next;
  lines[2].position = sf::Vector2f(curr->x, curr->y);
  curr = curr->next;
  lines[3].position = sf::Vector2f(curr->x, curr->y);
  curr = curr->next;
  lines[4].position = sf::Vector2f(curr->x, curr->y);
  curr = curr->next;
  lines[5].position = sf::Vector2f(curr->x, curr->y);
  curr = curr->next;
  lines[6].position = sf::Vector2f(curr->x, curr->y);
  curr = curr->next;
  lines[7].position = sf::Vector2f(curr->x, curr->y);
  curr = curr->next;
  lines[8].position = sf::Vector2f(curr->x, curr->y);
  window->draw(lines);

  for (auto tower : this->towers) {
    int radius = 20;
    sf::CircleShape shape(radius);
    shape.setFillColor(sf::Color(255, 0, 50));  // red
    shape.setPosition(tower.x - radius, tower.y - radius);
    window->draw(shape);
  }
  for (auto enemy : this->enemies) {
    int radius = 10;
    sf::CircleShape shape(radius);
    shape.setFillColor(sf::Color(0, 0, 200));  // blue
    shape.setPosition(enemy->x - radius, enemy->y - radius);
    window->draw(shape);
  }
}

void Map::addTower(int x, int y) {
  Tower t(1, 1, 50, x, y);
  this->towers.push_back(t);
  std::cout << "new tower!" << std::endl;
}

void Map::update(const float dt) {
  // spawn a new enemy randomly
  float spawnRate = 1;  // enemy per second
  float r = static_cast<double>(rand()) / RAND_MAX;
  if (r < dt / spawnRate) {
    Enemy* e = new Enemy(100, 300, "", this->start->next,
        this->start->x, this->start->y);
    this->enemies.push_back(e);
  }
  // advance all enemies, and remove ones that have reached the end
  std::vector<Enemy*>::iterator it = enemies.begin();
  while (it != enemies.end()) {
    Enemy *enemy = *it;
    if (enemy->move(dt)) {
      delete enemy;
      it = this->enemies.erase(it);
    } else {
      ++it;
    }
  }
}

Map::Map(std::vector<Tower> towers, std::vector<Enemy*> enemies,
    Waypoint *start) : towers(towers), enemies(enemies), start(start) {
  Waypoint *curr = start;
  Waypoint *next = new Waypoint(650, 50);
  curr->next = next;
  curr = curr->next;
  Waypoint *next1 = new Waypoint(650, 200);
  curr->next = next1;
  curr = curr->next;
  Waypoint *next2 = new Waypoint(50, 200);
  curr->next = next2;
  curr = curr->next;
  Waypoint *next3 = new Waypoint(50, 350);
  curr->next = next3;
  curr = curr->next;
  Waypoint *next4 = new Waypoint(650, 350);
  curr->next = next4;
  curr = curr->next;
  Waypoint *next5 = new Waypoint(650, 500);
  curr->next = next5;
  curr = curr->next;
  Waypoint *next6 = new Waypoint(150, 500);
  curr->next = next6;
  curr = curr->next;
  Waypoint *next7 = new Waypoint(150, 600);
  curr->next = next7;
  curr = curr->next;
}


Map::~Map()
{}
