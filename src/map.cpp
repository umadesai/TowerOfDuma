
#include <iostream>

#include "../include/map.hpp"

void Map::draw(sf::RenderWindow *window, Waypoint *start) {
  // hardcoded path
  sf::RectangleShape rectangle(sf::Vector2f(700, 50));
  rectangle.setPosition(0, 50);
  rectangle.setFillColor(sf::Color::Black);
  window->draw(rectangle);
  sf::RectangleShape rectangle2(sf::Vector2f(50, 150));
  rectangle2.setPosition(650, 100);
  rectangle2.setFillColor(sf::Color::Black);
  window->draw(rectangle2);
  sf::RectangleShape rectangle3(sf::Vector2f(650, 50));
  rectangle3.setPosition(50, 200);
  rectangle3.setFillColor(sf::Color::Black);
  window->draw(rectangle3);
  sf::RectangleShape rectangle4(sf::Vector2f(50, 150));
  rectangle4.setPosition(50, 200);
  rectangle4.setFillColor(sf::Color::Black);
  window->draw(rectangle4);
  sf::RectangleShape rectangle5(sf::Vector2f(650, 50));
  rectangle5.setPosition(50, 350);
  rectangle5.setFillColor(sf::Color::Black);
  window->draw(rectangle5);
  sf::RectangleShape rectangle6(sf::Vector2f(50, 150));
  rectangle6.setPosition(650, 400);
  rectangle6.setFillColor(sf::Color::Black);
  window->draw(rectangle6);
  sf::RectangleShape rectangle7(sf::Vector2f(500, 50));
  rectangle7.setPosition(150, 500);
  rectangle7.setFillColor(sf::Color::Black);
  window->draw(rectangle7);
  sf::RectangleShape rectangle8(sf::Vector2f(50, 100));
  rectangle8.setPosition(150, 500);
  rectangle8.setFillColor(sf::Color::Black);
  window->draw(rectangle8);

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
  Waypoint *next2 = new Waypoint(50, 200);
  curr->next = next2;
  curr = curr->next;
  Waypoint *next3 = new Waypoint(50, 350);
  curr->next = next3;
  curr = curr->next;
  Waypoint *next4 = new Waypoint(650, 350);
  curr->next = next4;
  curr = curr->next;
  Waypoint *next5 = new Waypoint(150, 500);
  curr->next = next5;
  curr = curr->next;
  Waypoint *next6 = new Waypoint(650, 500);
  curr->next = next6;
  curr = curr->next;
}


Map::~Map()
{}
