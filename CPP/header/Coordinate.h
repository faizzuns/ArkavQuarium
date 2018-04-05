#ifndef COORDINATE_H
#define COORDINATE_H
#include <iostream>

class Coordinate {
private:
  double x;
  double y;

public:
  //Default Constructor
  //assign x,y = 0
  Coordinate();

  //Constructor
  //assign this.x = x
  //assign this.y = y
  Coordinate(double x, double y);

  //return value x
  double getX();

  //return value y
  double getY();

  //set value X
  void setX(double x);

  //set value Y
  void setY(double y);

  bool operator== (const Coordinate &C);
};

#endif
