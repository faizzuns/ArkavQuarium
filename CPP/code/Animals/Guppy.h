#ifndef GUPPY_H
#define GUPPY_H
#include "Fish.h"
#include "../FishFood/FishFood.h"
#include "../LinkedList/LinkedList.h"
#include <iostream>

#define MAX_PHASE 3
#define FISH_PRICE 5

class Guppy : public Fish {
private:
  int phase; // Guppy phase
  int totalEatenFood; //total food this guppy eat
  //s
public:

  //Constructor
  // x and y,
  Guppy(double x, double y);
  ~Guppy();

  bool operator== (const Guppy &G);

  int getPhase();
  void setPhase();

  void eat();

  Coin makeCoin();

  void nextPhase();

  FishFood getNearestFood(LinkedList<FishFood> listFood);
};

#endif
