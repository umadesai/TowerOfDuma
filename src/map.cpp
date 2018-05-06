
#include <iostream>

#include "../include/map.hpp"

void Map::draw(sf::RenderWindow *window, Waypoint *start) {
  // count the number of waypoints
  Waypoint *curr = this->start;
  int numWaypoints = 0;
  while (curr) {
    curr = curr->next;
    numWaypoints++;
  }
  curr = this->start;
  // create VertexArray of correct size
  sf::VertexArray lines(sf::LinesStrip, numWaypoints);
  // draw all the waypoint lines
  for (int i = 0; i < numWaypoints; i++) {
    lines[i].position = sf::Vector2f(curr->x, curr->y);
    curr = curr->next;
  }
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
  Tower t(0.000003, 1, 50, x, y);
  Waypoint *w1 = start;
  Waypoint *w2 = start->next;
  while (w2) {
    if (!t.isLegal(w1, w2)) {
      std::cout << "ILLEGAL TOWER" << std::endl;
      return;
    }
    w1 = w2;
    w2 = w2->next;
  }
  this->towers.push_back(t);
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
  sf::Clock newClock;
  while (it != enemies.end()) {
    Enemy *enemy = *it;
    // check for enemies in range of a tower
    for (auto tower : this->towers) {
      double a = enemy->x - tower.x;
      double b = enemy->y - tower.y;
      double dist =  sqrt((a * a) + (b * b));
      if (dist <= tower.range) {
        if (enemy != NULL) {
          sf::Time elapsed = newClock.getElapsedTime();
          float et = elapsed.asSeconds();
          // std::cout << "firerate: " << tower.firerate << std::endl;
          // std::cout << "et: " << et << std::endl;

          // FIX THIS ---> check if enough time has elapsed since last shot
          if (et >= tower.firerate) {
            int health = enemy->health;
            std::cout << "SHOT! Health: " << enemy->health << std::endl;
            // check enemy health
            if (health < 101) {
              delete enemy;
              it = this->enemies.erase(it);
              std::cout << "Enemy destroyed!" << std::endl;
              newClock.restart();
            } else {
              enemy->health = health - 20;
              newClock.restart();
            }
          }
        }
      }
    }
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
