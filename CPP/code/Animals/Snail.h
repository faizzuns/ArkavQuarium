#ifndef SNAIL_H
#define SNAIL_H
#include "Animals.h"
#include "../Coin/Coin.h"
#include <cmath>
#include <iostream>

class Snail : public Animals{
public:
  Snail():Animals(0,0,SNAIL_SPEED){}
  Snail(double x, double y):Animals(x,y,SNAIL_SPEED){}

  void eat(LinkedList<Coin> &listCoin) {
    if (!listCoin.isEmpty()) {
      int coinIdx = getNearestCoin(listCoin);
      Coin coinTemp = listCoin.get(coinIdx);
      moveGeneral(coinTemp.getX(), coinTemp.getY());
      if (getX() == coinTemp.getX() && getY() == coinTemp.getY()) {
        listCoin.remove(coinIdx);
      }
    }
  }

  void synchronize(){
    setX();
    setY();
    setSpeed();
  }

  Snail& operator= (const Snail &S){
    this->setX(S.getX);
    this->setY(S.getY);
    this->setSpeed(S.getSpeed);

    return this;
  }

  int getNearestCoin(LinkedList<Coin> listCoin) {
   if (!listCoin.isEmpty()){
      int n = listCoin.size();
      int coinIdx;
      double distMin, distCurr;

      coinIdx = 0;
      distMin = distance2Point(listCoin.get(0).getX(), listCoin.get(0).getY(), this->getX(), this->getY());

      for (int i = 1; i < n; i++){
        distCurr = distance2Point(listCoin.get(i).getX(), listCoin.get(i).getY(), this->getX(), this->getY());
        if (distCurr <= distMin) {
          coinIdx = i;
          distMin = distCurr;
        }
      }
      return coinIdx;
    }
  }

};

#endif
