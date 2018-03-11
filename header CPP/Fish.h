#ifndef FISH_H
#define FISH_H
#include "Move.h"
#include "Coordinate.h"
#include <iostream>

#define OUTPUT_COIN 3
#define STATE_FULL 4
#define STATE_DEAD 5
#define LOOKING_LEFT 0
#define LOOKING_RIGHT 1
#define MOVE_TOP 0
#define MOVE_BOTTOM 1
#define MOVE_RIGHT 2
#define MOVE_LEFT 3
#define MOVE_DIAGONAL_TOP_LEFT 4
#define MOVE_DIAGONAL_TOP_RIGHT 5
#define MOVE_DIAGONAL_BOTTOM_RIGHT 6
#define MOVE_DIAGONAL_BOTTOM_LEFT 7

class Fish : public Move, public Coordinate {
private:
  static GENERATE_ID = 0; //for generate id fish
  int id; //uniqe atribute
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
  Fish(int x, int y);

  //setters and getters
  int getId();
  int getLifetime();
  int getStillFull();
  int getCountingDead();
  int getLookAt();
  void setId(int id);
  void setLifetime(int lifetime);
  void setStillFull(int stillFull);
  void setCountingDead(int countingDead);
  void setLookAt(int lookAt);

  //fish can eat, but every fish has different way to eat
  virtual void eat() = 0;

  //fish can move to all direction
  void move(int direction);
  void moveTop();
  void moveBottom();
  void moveRight();
  void moveLeft();
  void moveDiagonalTopLeft();
  void moveDiagonalTopRight();
  void moveDiagonalBottomRight();
  void moveDiagonalBottomLeft();

  //synchronize data after 1 lifetime
  void synchronize();
};

#endif
