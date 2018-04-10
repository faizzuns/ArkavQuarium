#ifndef FISH_H
#define FISH_H
#include "Animals.h"
#include "../Coin/Coin.h"
#include <iostream>

#define STATE_FULL 700
#define STATE_DEAD 1000
#define GUPPY_PRICE 5
#define PIRANHA_PRICE 20

class Fish : public Animals {
private:
  int lifetime; //variabel for check to output coin
  int stillFull; //variabel for check if fish is still full or not
  int countingDead; //varaibel for check when fish dont eat after full
  Coordinate randa;

public:
  //Constructor
  //generate id will assign the value to id, and increase his variable
  //lifetime, looking, stillFull, counting dead will assigned automatic
  //without user input
  //assign coordinate value to parent
  //assign move value to parent
  Fish(double x, double y, int speed) : Animals(x, y, speed){
    setLifetime(0);
    setStillFull(STATE_FULL);
    setCountingDead(STATE_DEAD);
    setLookAt(LOOKING_RIGHT);
    randa.setX(x);
    randa.setY(y);
  }
  Fish() : Animals(0,0,0){
    setLifetime(0);
    setStillFull(STATE_FULL);
    setCountingDead(STATE_DEAD);
    setLookAt(LOOKING_RIGHT);
  }
  ~Fish() {

  }

  //move Random
  void randomMove(){
    int xx = rand() % 10;
    double aa = 0;double bb = 0;
    for (int i = 0; i < xx; i++){
      aa =double(rand() % 620);
      bb =double(rand() % 440);
    }
    if (beetweenX(randa.getX(), 20) && beetweenY(randa.getY(), 20) && getX() > 0  && getX() < 640 && getY() > 0 && getY() < 440) {
      randa.setX(aa);
      randa.setY(bb);
    }
    moveGeneral(randa.getX(), randa.getY());

    if (getX() < randa.getX()){
      setLookAt(LOOKING_RIGHT);
    }else setLookAt(LOOKING_LEFT);

  }

  //setters and getters

  int getLifetime() {
    return lifetime;
  }
  int getStillFull() {
    return stillFull;
  }
  int getCountingDead() {
    return countingDead;
  }
  Coordinate getRanda(){return randa;}

  void setRandaX(double x){
    randa.setX(x);
  }

  void setRandaY(double y){
    randa.setY(y);
  }

  void setLifetime(int lifetime) {
    this->lifetime = lifetime;
  }
  void setStillFull(int stillFull) {
    this->stillFull = stillFull;
  }
  void setCountingDead(int countingDead) {
    this->countingDead = countingDead;
  }
  bool notHungry() {
    return (stillFull != 0);
  }

  //fish can output some Coin
  virtual Coin makeCoin(int phase) = 0;

  //synchronize data after 1 lifetime
  virtual int synchronize(LinkedList<Coin> &listCoin) = 0;


};

#endif
