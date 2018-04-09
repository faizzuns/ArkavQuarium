#ifndef FISH_H
#define FISH_H
#include "Animals.h"
#include "../Coin/Coin.h"
#include <iostream>

#define STATE_FULL 4
#define STATE_DEAD 5
#define GUPPY_PRICE 5
#define PIRANHA_PRICE 50

class Fish : public Animals {
private:
  static GENERATE_ID = 0; //for generate id fish
  int id; //uniqe atribute
  int lifetime; //variabel for check to output coin
  int stillFull; //variabel for check if fish is still full or not
  int countingDead; //varaibel for check when fish dont eat after full
  int lookAt; //define the fish direction
  int coinValue;

public:
  //Constructor
  //generate id will assign the value to id, and increase his variable
  //lifetime, looking, stillFull, counting dead will assigned automatic
  //without user input
  //assign coordinate value to parent
  //assign move value to parent
  Fish(double x, double y, int speed, int coinValue) : Animals(x, y, speed){
    setId(GENERATE_ID);
    GENERATE_ID++;
    setLifetime(0);
    setStillFull(STATE_FULL);
    setCountingDead(STATE_DEAD);
    setLookAt(LOOKING_RIGHT);
    setCoinValue(coinValue);
  }
  ~Fish() {

  }

  //setters and getters
  int getCoinValue() {
    return coinValue;
  }
  int getId() {
    return id;
  }
  int getLifetime() {
    return lifetime;
  }
  int getStillFull() {
    return stillFull;
  }
  int getCountingDead() {
    return countingDead;
  }

  void setCoinValue(int coinValue) {
    this->coinValue = coinValue;
  }
  void setId(int id) {
    this->id = id;
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
  virtual Coin makeCoin() = 0;

  //synchronize data after 1 lifetime
  void synchronize() {
    if (notHungry()) {
      stillFull--;
    } else {
      countingDead--;
    }
    if (countingDead == 0) {
      dead();
    }
  }
};

#endif
