#ifndef INCLUDE_SHOT_HPP_
#define INCLUDE_SHOT_HPP_

class Shot {
 public:
    // constructor and destructor
    Shot(int x1, int y1, int x2, int y2, float timecreated);
    ~Shot();
    int x1;
    int x2;
    int y1;
    int y2;
    float lifespan;
    float timecreated;
};

#endif  // INCLUDE_SHOT_HPP_
