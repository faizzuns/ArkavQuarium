#ifndef COIN_H
#define COIN_H
#include "Move.h"
#include "Coordinate.h"
#include <iostream>

#define BASE_COIN

class Coin : public Move, public Coordinate{
private:
  int value;
  int speed;

public:
  Coin(int x, int y, int value, int speed);
  ~Coin();

  int getSpeed();
  void setSpeed(int speed);

  void moveBottom();

  bool operator== (const Coin &C);
};


#endif
