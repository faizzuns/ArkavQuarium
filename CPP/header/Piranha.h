#ifndef PIRANHA_H
#define PIRANHA_H
#include <iostream>
#include "Guppy.h"
class Piranha : public Fish {
public:
  Piranha(double x, double y);
  ~Piranha();

  bool operator== (const Piranha &G);

  void eat();

  Coin makeCoin();

  Guppy getNearestGuppy(LinkedList<Guppy> listGuppy);
};

#endif
