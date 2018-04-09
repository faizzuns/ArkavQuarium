#ifndef PIRANHA_H
#define PIRANHA_H
#include <iostream>
#include "Guppy.h"

#define PIRANHA_COIN 3

class Piranha : public Fish {
public:
  Piranha(double x, double y) : Fish(x, y, PIRANHA_SPEED) {};
  ~Piranha();

  void eat(LinkedList<Guppy> &listGuppy, LinkedList<Coin> &listCoin) {
    if (!listGuppy.isEmpty()) {
      int guppyIdx = getNearestFood(listGuppy);
      Guppy guppyTemp = listGuppy.get(guppyIdx);
      
      if (beetweenX(guppyTemp.getX(),5)){
        if (beetweenY(guppyTemp.getY(),10)){
          listCoin.add(makeCoin());
          stillFull = STATE_FULL;
          countingDead = STATE_DEAD;
          cout<<"kenyang"<<endl;
        }
      }else{
        if (getX() < guppyTemp.getX()){
          cout<<"belok kanan"<<endl;
          moveRight();
          setLookAt(LOOKING_RIGHT);
        }else if (getX() > guppyTemp.getX()){
          moveLeft();
          setLookAt(LOOKING_LEFT);
          cout<<"belok kiri"<<endl;
        }
      }

      moveGeneral(guppyTemp.getX(), guppyTemp.getY());
      if (getX() == guppyTemp.getX() && getY() == guppyTemp.getY()) {
        listGuppy.remove(guppyIdx);
      }
    }
  }
  
  Coin makeCoin() {
  	int phase =  listGuppy.get(guppyIdx).getPhase();
    int x = GUPPY_PRICE * (phase + 1);
  	Coin c(getX(), getY(), x);
  	return c;
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

  int synchronize(linkedList<Coin> &listCoin) {
    if (notHungry()) {
      stillFull--;
      return 2;
      //fish move randomly
    } else {
      countingDead--;
      if (countingDead == 0) {
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
