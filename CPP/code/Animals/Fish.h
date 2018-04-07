#ifndef FISH_H
#define FISH_H
#include "Animals.h"
#include "../Coin/Coin.h"
#include <iostream>

#define OUTPUT_COIN 3
#define STATE_FULL 4
#define STATE_DEAD 5
#define LOOKING_LEFT 0
#define LOOKING_RIGHT 1

class Fish : public Animals {
private:
  static GENERATE_ID = 0; //for generate id fish
  int id; //unique atribute
  int lifetime; //variabel for check to output coin
  int stillFull; //variabel for check if fish is still full or not
  int countingDead; //variabel for check when fish dont eat after full
  int lookAt; //define the fish direction

public:
  //Constructor
  //generate id will assign the value to id, and increase his variable
  //lifetime, looking, stillFull, counting dead will assigned automatic
  //without user input
  //assign coordinate value to parent
  //assign move value to parent
  Fish(double x, double y, int speed) : Animals(x, y, speed){
  	setId(GENERATE_ID);
  	GENERATE_ID++;
  	setLifetime(0);
  	setStillFull(STATE_FULL);
  	setCountingDead();
  	setLookAt(LOOKING_RIGHT);
  }
  ~Fish();

  //setters and getters
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
  int getLookAt() {
  	return lookAt;
  }
  void setId(int id) {
  	this.id = id;
  }
  void setLifetime(int lifetime) {
  	this.lifetime = lifetime;
  }
  void setStillFull(int stillFull) {
  	this.stillFull = stillFull;
  }
  void setCountingDead(int countingDead) {
  	this.countingDead = countingDead;
  }
  void setLookAt(int lookAt) {
  	this.lookAt = lookAt;
  }
  bool notHungry();
  bool isDead();

  //fish can output some Coin
  virtual Coin makeCoin() = 0;

  //fish can move to all direction
  void move(int direction) {
  	switch(direction) {
  		case MOVE_TOP :
  			moveTop();
  			break;
  		case MOVE_BOTTOM :
  			moveBottom();
  			break;
  		case MOVE_RIGHT :
  			moveRight();
  			break;
  		case MOVE_LEFT :
  			moveLeft();
  			break;
  	}
  }
  void moveTop() {
  	setY(getY() - speed);
  }
  void moveBottom() {
  	setY(getY() + speed);
  }
  void moveRight() {
  	setX(getX() + speed);
  	setLookAt(LOOKING_RIGHT);
  }
  void moveLeft() {
  	setX(getX() - speed);
  	setLookAt(LOOKING_LEFT);
  }

  //synchronize data after 1 lifetime
  void synchronize();

  //make fish dead
  void dead();
};

#endif
