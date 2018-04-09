#ifndef FISH_H
#define FISH_H
#include "Animals.h"
#include "../Coin/Coin.h"
#include <iostream>

#define STATE_FULL 1000
#define STATE_DEAD 1500
#define GUPPY_PRICE 5
#define PIRANHA_PRICE 50

class Fish : public Animals {
private:
  int lifetime; //variabel for check to output coin
  int stillFull; //variabel for check if fish is still full or not
  int countingDead; //varaibel for check when fish dont eat after full
  int lookAt; //define the fish direction

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
  }
  Fish() : Animals(0,0,0){
    setLifetime(0);
    setStillFull(STATE_FULL);
    setCountingDead(STATE_DEAD);
    setLookAt(LOOKING_RIGHT);
  }
  ~Fish() {

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

  void randomMove(){}
};

#endif
