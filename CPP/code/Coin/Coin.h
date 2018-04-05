#ifndef COIN_H
#define COIN_H
#include "../Move/Move.h"
#include "../Coordinate/Coordinate.h"
#include <iostream>

#define BASE_COIN

class Coin : public Move, public Coordinate{
private:
  int value;
  int speed;
  //s

public:
  Coin(int x, int y, int value, int speed);
  ~Coin();

  int getSpeed();
  int getValue();
  void setSpeed(int speed);
  void setValue(int value);

  void moveBottom();

  bool operator== (const Coin &C);
};


#endif
