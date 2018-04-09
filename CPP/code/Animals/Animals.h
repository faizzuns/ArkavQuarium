#ifndef ANIMALS_H
#define ANIMALS_H
#include "../Move/Move.h"
#include "../Coordinate/Coordinate.h"
#include "../LinkedList/LinkedList.h"
#include <iostream>

#define LOOKING_LEFT 0
#define LOOKING_RIGHT 1

class Animals : public Move {
private:
  int lookAt;
public:

  Animals(double x, double y, double speed):Move(x,y,speed){
    lookAt = LOOKING_LEFT;
  }

  int getLookAt() {
    return lookAt;
  }
  void setLookAt(int lookAt) {
    this->lookAt = lookAt;
  }

};

#endif
