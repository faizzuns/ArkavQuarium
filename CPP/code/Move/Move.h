#ifndef MOVE_H
#define MOVE_H

#define GUPPY_SPEED 1.5
#define PIRANHA_SPEED 1.7
#define FISH_SPEED 2
#define SNAIL_SPEED 0.7
#define COIN_SPEED 0.6
#define FISH_FOOD_SPEED 0.4

#define MOVE_TOP 0
#define MOVE_BOTTOM 1
#define MOVE_RIGHT 2
#define MOVE_LEFT 3

#include "../Coordinate/Coordinate.h"
#include <math.h>
#include <cstdlib>

class Move : public Coordinate{
private:
  double speed;
public:
  Move(double x, double y, double speed): Coordinate(x,y){
    this->speed = speed;
  }

  void moveTop(){
    setY(getY() - speed);
  }
  void moveBottom(){
    setY(getY() + speed);
  }
  void moveRight(){
    setX(getX() + speed);
  }
  void moveLeft(){
    setX(getX() - speed);
  }

  void moveGeneral(double x2, double y2){
    double a = atan2(y2-getY(), x2-getX());
    setX(getX() + (getSpeed() * cos(a) * 1));
    setY(getY() + (getSpeed() * sin(a) * 1));
  }

  double getSpeed(){
    return speed;
  }
  void setSpeed(double speed){
    this->speed = speed;
  }


};

#endif
