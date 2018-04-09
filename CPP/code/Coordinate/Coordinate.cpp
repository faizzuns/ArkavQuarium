#include "Coordinate.h"

Coordinate::Coordinate(){
  x = 0;
  y = 0;
}

//Constructor
//assign this.x = x
//assign this.y = y
Coordinate::Coordinate(double x, double y){
  this->x = x;
  this->y = y;
}

//return value x
double Coordinate::getX(){
  return x;
}

//return value y
double Coordinate::getY(){
  return y;
}

//set value X
void Coordinate::setX(double x){
  this->x = x;
}

//set value Y
void Coordinate::setY(double y){
  this->y = y;
}
