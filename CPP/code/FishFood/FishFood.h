#ifndef FISHFOOD_H
#define FISHFOOD_H
#include "../Move/Move.h"
#include "../Coordinate/Coordinate.h"
#include <iostream>

class FishFood : public Move {
public:

  FishFood():Move(0,0, FISH_FOOD_SPEED){  }

  FishFood(double x, double y):Move(x,y,FISH_FOOD_SPEED){  }
};

#endif
