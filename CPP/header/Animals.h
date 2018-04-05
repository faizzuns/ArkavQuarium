#ifndef ANIMALS_H
#define ANIMALS_H
#include "Move.h"
#include "Coordinate.h"
#include <iostream>

class Animals : public Move, public Coordinate {
private:
  int speed;
public:
  Animals(double x, double y, int speed);
  ~Animals();

  //animals can eat, but every animals has different way to eat
  virtual void eat() = 0;

  //all animals after 1 lifetime
  virtual void synchronize() = 0;

  int getSpeed();
  void setSpeed(int speed);
};

#endif
