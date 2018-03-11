#ifndef FISHFOOD_H
#define FISHFOOD_H
#include "Move.h"
#include "Coordinate.h"
#include <iostream>

class FishFood : public Move,public Coordinate {
public:

  FishFood(int x, int y);
  ~FishFood();

  void moveBottom();

  bool operator== (const FishFood &F);
};

#endif
