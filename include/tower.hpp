
#ifndef INCLUDE_TOWER_HPP_
#define INCLUDE_TOWER_HPP_

class Tower {
 private:
    int firerate;
    int damage;
    int range;
    int x;
    int y;
 public:
    // constructor and destructor
    Tower(int firerate, int damage, int range, int x, int y);
    ~Tower();
};

#endif  // INCLUDE_TOWER_HPP_
