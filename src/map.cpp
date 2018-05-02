
#include "../include/map.hpp"
#include "../include/tower.hpp"
#include "../include/enemy.hpp"
#include "../include/waypoint.hpp"

Map::Map(Tower *towers, Enemy *enemies, Waypoint *start)
      : towers(towers), enemies(enemies), start(start) {
  Waypoint *curr = start;
  for (int i = 0; i < 5; i++) {
    Waypoint *next = new Waypoint(i, i);
    curr->next = next;
    curr = curr->next; }
}


Map::~Map()
{}
