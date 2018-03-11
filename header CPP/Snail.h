#ifndef PIRANHA_H
#define PIRANHA_H
#include <iostream>


class Snail : public Animals{
private:
  int speed;
public:
  Snail(int x, int y);
  ~Snail();

  int getSpeed();
  void setSpeed(int speed);

  void eat();

  void synchronize();

  Coin getNearestCoin(LinkedList<Coin> listCoin);

  void moveRight();
  void moveLeft();
};

#endif
