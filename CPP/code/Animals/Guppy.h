#ifndef GUPPY_H
#define GUPPY_H
#include "Fish.h"
#include "../FishFood/FishFood.h"
#include "../LinkedList/LinkedList.h"
#include "../Coin/Coin.h"
#include <iostream>

#define GUPPY_COIN 3
#define PHASE_2 5
#define PHASE_3 12
#define MAX_PHASE 3
#define COIN_VALUE_PHASE_1 1
#define COIN_VALUE_PHASE_2 2
#define COIN_VALUE_PHASE_3 3
#define COIN_PERIODIC 100000

class Guppy : public Fish {
private:
  int phase; // Guppy phase
  int totalEatenFood; //total food this guppy eat
  int coinValue;
public:

  //Constructor
  // x and y,
  Guppy(double x, double y) : Fish(x, y, GUPPY_SPEED){
    setPhase(1);
    setTotalEatenFood(0);
    setCoinValue(COIN_VALUE_PHASE_1);
  }
  Guppy():Fish(0,0,GUPPY_SPEED){
    setPhase(1);
    setTotalEatenFood(0);
    setCoinValue(COIN_VALUE_PHASE_1);
  }
  ~Guppy(){}
  int getCoinValue() {
    return coinValue;
  }
  void setCoinValue(int coinValue) {
    this->coinValue = coinValue;
  }
  int getPhase() {
    return phase;
  }
  int getTotalEatenFood() {
    return totalEatenFood;
  }
  void setPhase(int phase) {
    this->phase = phase;
  }
  void setTotalEatenFood(int totalEatenFood) {
    this->totalEatenFood = totalEatenFood;
  }

  void eat(LinkedList<FishFood> &listFood) {
    if (!listFood.isEmpty()) {
      int foodIdx = getNearestFood(listFood);
      FishFood foodTemp = listFood.get(foodIdx);

      if (beetweenX(foodTemp.getX(),5)){
        if (beetweenY(foodTemp.getY(),10)){
          listFood.remove(foodIdx);
          totalEatenFood++;
          setStillFull(STATE_FULL);
          setCountingDead(STATE_DEAD);
          if (totalEatenFood == PHASE_2 || totalEatenFood == PHASE_3) {
            nextPhase();
          }
        }
      }else{
        if (getX() < foodTemp.getX()){
          moveGeneral(foodTemp.getX(), foodTemp.getY());
          setLookAt(LOOKING_RIGHT);
        }else if (getX() > foodTemp.getX()){
          moveGeneral(foodTemp.getX(), foodTemp.getY());
          setLookAt(LOOKING_LEFT);
        }
      }
    }
  }
  Coin makeCoin(int phase) {
    Coin c(getX(), getY(), getCoinValue());
    return c;
  }

  void nextPhase() {
    phase++;
    if(phase == 2) {
      setCoinValue(COIN_VALUE_PHASE_2);
    } else if(phase == 3) {
      setCoinValue(COIN_VALUE_PHASE_3);
    }
  }

  int getNearestFood(LinkedList<FishFood> listFood) {
    //return index of nearest Food
    if (!listFood.isEmpty()){
      int n = listFood.size();
      int foodIdx;
      double distMin, distCurr;

      foodIdx = 0;
      distMin = distance2Point(listFood.get(0).getX(), listFood.get(0).getY(), this->getX(), this->getY());

      for (int i = 1; i < n; i++){
        distCurr = distance2Point(listFood.get(i).getX(), listFood.get(i).getY(), this->getX(), this->getY());
        if (distCurr <= distMin) {
          foodIdx = i;
          distMin = distCurr;
        }
      }
      return foodIdx;
    }else return 0;
  }

  int synchronize(LinkedList<Coin> &listCoin) {
    if (getLifetime() % COIN_PERIODIC == 0) {
      listCoin.add(makeCoin(0));
    }
    if (notHungry()) {
      setStillFull(getStillFull() - 1);
      return 2;
      //fish move randomly
    } else {
      setCountingDead(getCountingDead() - 1);
      if (getCountingDead() == 0) {
        return 0;
        //fish is dead
      } else {
        return 1;
        //fish is dying
      }
    }
  }
};

#endif
