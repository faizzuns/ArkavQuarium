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
  Coordinate(){
    x = 0;
    y = 0;
  }

  //Constructor
  //assign this.x = x
  //assign this.y = y
  Coordinate(double x, double y){
    this->x = x;
    this->y = y;
  }

  //return value x
  double getX(){
    return x;
  }

  //return value y
  double getY(){
    return y;
  }

  //set value X
  void setX(double x){
    this->x = x;
  }

  //set value Y
  void setY(double y){
    this->y = y;
  }

  double distance2Point(double x1, double y1, double x2, double y2){
    double distance;
    distance = sqrt((pow(x2-x1,2)) + (pow(y2-y1,2)));
    return distance;
  }

  bool beetweenX(double cX, double radius){
    return ((cX <= (x + radius)) && (cX >= (x - radius)));
  }

  bool beetweenY(double  cY, int radius){
    return ((cY <= (y + radius)) && (cY >= (y - radius)));
  }
};
#endif
