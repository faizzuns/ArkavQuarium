#ifndef SNAIL_H
#define SNAIL_H
#include "Animals.h"
#include "Coin.h"
#include <iostream>

class Snail : public Animals{
private:
  int speed;
public:
  Snail(double x, double y);
  ~Snail();

  int getSpeed();
  void setSpeed(int speed);

  void eat();

  void synchronize();

  Snail& operator= (const Snail &S);

  Coin getNearestCoin(LinkedList<Coin> listCoin);

  void moveRight();
  void moveLeft();
};

#endif
