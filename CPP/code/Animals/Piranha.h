#ifndef PIRANHA_H
#define PIRANHA_H
#include <iostream>
#include "Guppy.h"

#define PIRANHA_COIN 3

class Piranha : public Fish {
public:
  Piranha(double x, double y) : Fish(x, y, PIRANHA_SPEED) {};
  ~Piranha();

  void eat(LinkedList<Guppy> &listGuppy) {
    if (!listGuppy.isEmpty()) {
      int guppyIdx = getNearestFood(listGuppy);
      Guppy guppyTemp = listGuppy.get(guppyIdx);
      moveGeneral(guppyTemp.getX(), guppyTemp.getY());
      if (getX() == guppyTemp.getX() && getY() == guppyTemp.getY()) {
        listGuppy.remove(guppyIdx);
      }
    }
  }
  
  Coin makeCoin() {
  	Coin(getX(), getY(), PIRANHA_COIN);
  	harga ikan * (tahap ikan yang dimakan + 1)
  }

  int getNearestGuppy(LinkedList<Guppy> listGuppy) {
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
    }
  }
};

#endif
