#ifndef SNAIL_H
#define SNAIL_H
#include "Animals.h"
#include "../Coin/Coin.h"
#include <iostream>

class Snail : public Animals{
public:
  Snail():Animals(0,0,SNAIL_SPEED){}
  Snail(double x, double y):Animals(x,y,SNAIL_SPEED){}

  void eat();

  void synchronize();

  Snail& operator= (const Snail &S);

  Coin getNearestCoin(LinkedList<Coin> listCoin);
};

#endif
