#ifndef GUPPY_H
#define GUPPY_H
#include "Fish.h"
#include "../FishFood/FishFood.h"
#include "../LinkedList/LinkedList.h"
#include <iostream>

#define PHASE_2 5
#define PHASE_3 12
#define MAX_PHASE 3
#define FISH_PRICE 5

class Guppy : public Fish {
private:
  int phase; // Guppy phase
  int totalEatenFood; //total food this guppy eat
public:

  //Constructor
  // x and y,
  Guppy(double x, double y) : Fish(x, y, GUPPY_SPEED){
    setPhase(1);
    setTotalEatenFood(0);
  }
  ~Guppy();

  bool operator== (const Guppy &G);

  int getPhase() {
    return phase;
  }
  int getTotalEatenFood() {
    return totalEatenFood;
  }
  void setPhase(int phase) {
    this.phase = phase;
  }
  void setTotalEatenFood(int totalEatenFood) {
    this.totalEatenFood = totalEatenFood;
  }
  void eat() {
    totalEatenFood++;
    if (totalEatenFood == PHASE_2 || totalEatenFood == PHASE_3) {
      void nextPhase();
    }
  }

  Coin makeCoin() {

  }

  void nextPhase() {
    phase++;
  }

  FishFood getNearestFood(LinkedList<FishFood> listFood);
};

#endif
