#ifndef ANIMALS_H
#define ANIMALS_H
#include "../Move/Move.h"
#include "../Coordinate/Coordinate.h"
#include <iostream>

class Animals : public Move {
public:
  Animals(double x, double y, int speed):Move(x,y,speed){}

  //animals can eat, but every animals has different way to eat
  virtual void eat() = 0;

  //all animals after 1 lifetime
  virtual void synchronize() = 0;

};

#endif
