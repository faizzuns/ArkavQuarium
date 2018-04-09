#ifndef GUPPY_H
#define GUPPY_H
#include "Fish.h"
#include "../FishFood/FishFood.h"
#include "../LinkedList/LinkedList.h"
#include <iostream>

#define GUPPY_COIN 3
#define PHASE_2 5
#define PHASE_3 12
#define MAX_PHASE 3
#define COIN_VALUE_PHASE_1 1
#define COIN_VALUE_PHASE_2 2
#define COIN_VALUE_PHASE_3 3

class Guppy : public Fish {
private:
  int phase; // Guppy phase
  int totalEatenFood; //total food this guppy eat
public:

  //Constructor
  // x and y,
  Guppy(double x, double y) : Fish(x, y, GUPPY_SPEED, COIN_VALUE_PHASE_1){
    setPhase(1);
    setTotalEatenFood(0);
  }
  ~Guppy();

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
  void eat(LinkedList<FishFood> &listFood) {
    if (!listFood.isEmpty()) {
      int foodIdx = getNearestFood(listFood);
      FishFood foodTemp = listFood.get(foodIdx);
      
      if (beetweenX(foodTemp.getX(),5)){
        if (beetweenY(foodTemp.getY(),10)){
          listFood.remove(foodIdx);
          totalEatenFood++;
          if (totalEatenFood == PHASE_2 || totalEatenFood == PHASE_3) {
            nextPhase();
          }
          cout << "kenyang" << endl;
        }
      }else{
        if (getX() < foodTemp.getX()){
          cout<<"belok kanan"<<endl;
          moveGeneral(foodTemp.getX(), foodTemp.getY());
          setLookAt(LOOKING_RIGHT);
        }else if (getX() > foodTemp.getX()){
          moveGeneral(foodTemp.getX(), foodTemp.getY());
          setLookAt(LOOKING_LEFT);
          cout<<"belok kiri"<<endl;
        }
      }
    }
  }
  Coin makeCoin() {
    Coin(getX(), getY(), getCoinValue());
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
    }
  }

  virtual void dead(LinkedList<Guppy> &listGuppy) {
    if
  }
};

#endif
