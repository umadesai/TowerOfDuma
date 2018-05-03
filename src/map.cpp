
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
}

void Map::addTower(int x, int y) {
  Tower t(1, 1, 50, x, y);
  this->towers.push_back(t);
  std::cout << "new tower!" << std::endl;
}

Map::Map(std::vector<Tower> towers, std::vector<Enemy> enemies, Waypoint *start)
: towers(towers), enemies(enemies), start(start) {
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
