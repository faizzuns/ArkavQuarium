#ifndef COORDINATE_H
#define COORDINATE_H
#include <iostream>

class Coordinate {
private:
  int x;
  int y;

public:
  //Default Constructor
  //assign x,y = 0
  Coordinate();

  //Constructor
  //assign this.x = x
  //assign this.y = y
  Coordinate(int x, int y);

  //return value x
  int getX();

  //return value y
  int getY();

  //set value X
  void setX(int x);

  //set value Y
  void setY(int y);

  bool operator== (const Coordinate &C); 
};

#endif
