#ifndef COIN_H
#define COIN_H
#include "../Move/Move.h"
#include "../Coordinate/Coordinate.h"
#include <iostream>

#define BASE_COIN 10

#define GUPPY_PRICE 5

class Coin : public Move{
private:
  int value;

public:
  Coin():Move(0,0,COIN_SPEED){value = 0;}
  Coin(int x, int y, int value):Move(x,y,COIN_SPEED){
    this->value = value;
  }

  int getValue(){return value;}
  void setValue(int value){this->value = value;}

};


#endif
