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

  int eat(LinkedList<Coin> &listCoin) {
    if (!listCoin.isEmpty()) {
      int coinIdx = getNearestCoin(listCoin);
      //int coinIdx = 0;
      Coin coinTemp = listCoin.get(coinIdx);
      cout<<coinIdx<<endl;

      if (beetweenX(coinTemp.getX(),5)){
        if (beetweenY(coinTemp.getY(),10)){
          int x =  listCoin.get(coinIdx).getValue();
          listCoin.remove(coinIdx);
          return x;
        }
      }else{
        if (getX() < coinTemp.getX()){
          moveRight();
          setLookAt(LOOKING_RIGHT);
        }else if (getX() > coinTemp.getX()){
          moveLeft();
          setLookAt(LOOKING_LEFT);
        }
      }
    }
    return 0;
  }

  Snail& operator= (const Snail &S){
    //setX(S.getX());
    //setY(S.getY());
    //setSpeed(S.getSpeed());

    return *this;
  }

  int getNearestCoin(LinkedList<Coin> &listCoin) {
   if (!listCoin.isEmpty()){
      int n = listCoin.size();
      int coinIdx;
     double distMin, distCurr;

     coinIdx = 0;
     distMin = distance2Point(listCoin.get(coinIdx).getX(), listCoin.get(coinIdx).getY(), getX(), getY());

      for (int i = 1; i < n; i++){
        distCurr = distance2Point(listCoin.get(i).getX(), listCoin.get(i).getY(), getX(), getY());
        if (distCurr <= distMin) {
          coinIdx = i;
          distMin = distCurr;
        }
      }
      return coinIdx;
    }else return 0;
  }

};

#endif
