#ifndef FISHFOOD_H
#define FISHFOOD_H
#include "Move.h"
#include "Coordinate.h"
#include <iostream>

class FishFood : public Move,public Coordinate {
private:
  int speed;
public:

  FishFood(int x, int y, int speed);
  ~FishFood();

  int getSpeed();
  void setSpeed(int speed);

  void moveBottom();

  bool operator== (const FishFood &F);
};

#endif
