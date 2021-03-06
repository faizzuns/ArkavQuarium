#ifndef PIRANHA_H
#define PIRANHA_H
#include <iostream>
#include "Guppy.h"

#define PIRANHA_COIN 3

class Piranha : public Fish {
public:
  Piranha(double x, double y) : Fish(x, y, PIRANHA_SPEED) {}
  Piranha() : Fish(0,0, PIRANHA_SPEED){}
  ~Piranha(){}

  void eat(LinkedList<Guppy> &listGuppy, LinkedList<Coin> &listCoin) {
    if (!listGuppy.isEmpty()) {
      int guppyIdx = getNearestGuppy(listGuppy);
      Guppy guppyTemp = listGuppy.get(guppyIdx);

      if (beetweenX(guppyTemp.getX(),5)){
        if (beetweenY(guppyTemp.getY(),10)){
          listCoin.add(makeCoin(listGuppy.get(guppyIdx).getPhase()));
          listGuppy.remove(guppyIdx);
          setStillFull(STATE_FULL);
          setCountingDead(STATE_DEAD);
        }else moveGeneral(guppyTemp.getX(), guppyTemp.getY());
      }else{
        if (getX() < guppyTemp.getX()){
          moveGeneral(guppyTemp.getX(), guppyTemp.getY());
          setLookAt(LOOKING_RIGHT);
        }else if (getX() > guppyTemp.getX()){
          moveGeneral(guppyTemp.getX(), guppyTemp.getY());
          setLookAt(LOOKING_LEFT);
        } else randomMove();
      }
    } else randomMove();
  }

  Coin makeCoin(int phase) {
    int x = GUPPY_PRICE * (phase + 1);
  	Coin c(getX(), getY(), x);
  	return c;
  }

  int getNearestGuppy(LinkedList<Guppy> &listGuppy) {
  	if (!listGuppy.isEmpty()){
      int n = listGuppy.size();
      int guppyIdx;
      double distMin, distCurr;

      guppyIdx = 0;
      distMin = distance2Point(listGuppy.get(0).getX(), listGuppy.get(0).getY(), this->getX(), this->getY());

      for (int i = 1; i < n; i++){
        distCurr = distance2Point(listGuppy.get(i).getX(), listGuppy.get(i).getY(), this->getX(), this->getY());
        if (distCurr <= distMin) {
          guppyIdx = i;
          distMin = distCurr;
        }
      }
      return guppyIdx;
    }else return 0;
  }

  int synchronize(LinkedList<Coin> &listCoin) {
    setLifetime((getLifetime() + 1) % 1000);
    if (notHungry()) {
      setStillFull(getStillFull() - 1);
      return 2;
      //fish move randomly
    } else {
      setCountingDead(getCountingDead() - 1);
      if (getCountingDead() == 0) {
        return 0;
        //fish is dead
      } else {
        return 1;
        //fish is dying
      }
    }
  }
};

#endif
