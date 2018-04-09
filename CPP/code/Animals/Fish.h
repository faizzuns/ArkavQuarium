#ifndef FISH_H
#define FISH_H
#include "Animals.h"
#include "../Coin/Coin.h"
#include <iostream>

#define STATE_FULL 700
#define STATE_DEAD 1000
#define GUPPY_PRICE 5
#define PIRANHA_PRICE 50

class Fish : public Animals {
private:
  int lifetime; //variabel for check to output coin
  int stillFull; //variabel for check if fish is still full or not
  int countingDead; //varaibel for check when fish dont eat after full
  int lookAt; //define the fish direction
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
    
    if (betweenX(randa.getX(), 1) && betweenY(randa.getY(), 1) && getX() > 0  && getX() < 640 && getY() > 0 && getY() < 440) {
      randa.setX(rand() % 640);
      randa.setY(rand() % 440);
    }
    moveGeneral(randa.getX(), randa.getY());

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
