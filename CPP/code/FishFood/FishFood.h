#ifndef FISHFOOD_H
#define FISHFOOD_H
#include "../Move/Move.h"
#include "../Coordinate/Coordinate.h"
#include <iostream>

class FishFood : public Move,public Coordinate {
private:
  double speed;
public:

  FishFood():Move(), Coordinate(0,0){
    speed = FISH_FOOD_SPEED;
  }

  FishFood(double x, double y):Move(), Coordinate(x,y){
    speed = FISH_FOOD_SPEED;
  }

  double getSpeed(){
    return speed;
  }
  void setSpeed(double speed){
    this->speed = speed;
  }

  void moveBottom(){
    setY(getY() + (speed));
  }

  void moveTop(){}
  void moveRight(){}
  void moveLeft(){}
};

#endif
