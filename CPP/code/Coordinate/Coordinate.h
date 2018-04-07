#ifndef COORDINATE_H
#define COORDINATE_H
#include <iostream>
#include <math.h>
#include <cmath>

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

  double distance2Point(double x1, double y1, double x2, double y2){
    double distance;
    distance = sqrt((pow(x2-x1)) + (pow(y2-y1)));
    return distance;
  }
};

#endif
