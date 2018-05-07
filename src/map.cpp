
#include <iostream>
#include <algorithm>

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
  // draw lines between waypoints and circles on waypoints
  for (int i = 0; i < numWaypoints - 1; i++) {
    sfLine line(sf::Vector2f(curr->x, curr->y), sf::Vector2f(curr->next->x,
      curr->next->y), sf::Color::White, 40);
    int radius = 20;
    sf::CircleShape shape(radius);
    shape.setFillColor(sf::Color::White);
    shape.setPosition(curr->next->x - radius, curr->next->y - radius);
    window->draw(line);
    window->draw(shape);
    curr = curr->next;
  }

  for (auto tower : this->towers) {
    int radius = 25;
    sf::CircleShape shape(radius);
    shape.setFillColor(sf::Color(255, 0, 50));  // red
    shape.setPosition(tower->x - radius, tower->y - radius);
    sf::CircleShape outline(tower->range);
    outline.setFillColor(sf::Color(250, 150, 100, 50));  // orange
    outline.setPosition(tower->x - tower->range, tower->y - tower->range);
    window->draw(shape);
    window->draw(outline);
  }
  for (auto enemy : this->enemies) {
    int radius = 8 * (enemy->health / 100.0) + 7;
    sf::CircleShape shape(radius);
    shape.setFillColor(sf::Color(0, 0, 200));  // blue
    shape.setPosition(enemy->x - radius, enemy->y - radius);
    window->draw(shape);
  }
  for (auto shot : this->shots) {
    sfLine line(sf::Vector2f(shot.x1, shot.y1), sf::Vector2f(shot.x2, shot.y2),
        sf::Color::Red, 5.0f);
    window->draw(line);
  }
}

void Map::addTower(int x, int y) {
  Tower *t = new Tower(2, 30, 100, x, y);
  Waypoint *w1 = start;
  Waypoint *w2 = start->next;
  while (w2) {
    if (!t->isLegal(w1, w2)) {
      std::cout << "ILLEGAL TOWER" << std::endl;
      return;
    }
    w1 = w2;
    w2 = w2->next;
  }
  this->towers.push_back(t);
}

void Map::update(const float dt) {
  totalTime+=dt;
  // spawn a new enemy randomly
  float spawnRate = 2;  // enemy per second
  float r = static_cast<double>(rand()) / RAND_MAX;
  if (r < dt * spawnRate) {
    Enemy* e = new Enemy(100, 100, "", this->start->next,
        this->start->x, this->start->y);
    this->enemies.push_back(e);
  }
  // advance all enemies, and remove ones that have reached the end
  std::vector<Enemy*>::iterator it = enemies.begin();
  while (it != enemies.end()) {
    Enemy *enemy = *it;
    // check for enemies in range of a tower
    for (auto tower : this->towers) {
      double a = enemy->x - tower->x;
      double b = enemy->y - tower->y;
      double dist =  sqrt((a * a) + (b * b));
      if (dist <= tower->range) {
          float et = totalTime - tower->lastShot;
          if (et >= 1/tower->firerate && enemy->health > 0) {
            enemy->health = std::max(0, enemy->health - tower->damage);
            tower->lastShot = totalTime;
            // create a new shot object
            Shot s(tower->x, tower->y, enemy->x, enemy->y, totalTime);
            this->shots.push_back(s);
          }
      }
    }
    if (enemy->health == 0 || enemy->move(dt)) {
      delete enemy;
      it = this->enemies.erase(it);
    } else {
      ++it;
    }
  }
  for (std::vector<Shot>::iterator it = shots.begin();
      it != shots.end();) {
    Shot s = *it;
    if (totalTime - s.timecreated >= s.lifespan) {
      it = shots.erase(it);
    } else {
      ++it;
    }
  }
}

Map::Map(std::vector<Tower*> towers, std::vector<Enemy*> enemies,
    Waypoint *start) : towers(towers), enemies(enemies), start(start),
    totalTime(0) {
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
