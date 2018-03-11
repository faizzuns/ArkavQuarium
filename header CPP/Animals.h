#ifndef ANIMALS_H
#define ANIMALS_H
#include <iostream>

class Animals : public Move, public Coordinate {
public:
  Animals(int x, int y, int speed);
  ~Animals();

  //animals can eat, but every animals has different way to eat
  virtual void eat() = 0;

  //all animals after 1 lifetime
  virtual void synchronize() = 0;
};

#endif
