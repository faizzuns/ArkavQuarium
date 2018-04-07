#ifndef AQUARIUM_H
#define AQUARIUM_H
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "../Animals/Snail.h"
#include "../Animals/Piranha.h"
#include "../Animals/Guppy.h"
#include "../Coin/Coin.h"
#include "../FishFood/FishFood.h"
#include "../LinkedList/LinkedList.h"

#define MAX_LENGTH 640
#define MAX_WIDTH 480

#define LOSE 0
#define RUNNING 1
#define WIN 2

//class aquarium
class Aquarium {
private:

  //char[][] map = new char[MAX_LENGTH][MAX_WIDTH];
  //LinkedList<Coordinate> listCoordinate;
  LinkedList<Guppy> listGuppy;
  LinkedList<Piranha> listPiranha;
  LinkedList<Coin> listCoin;
  LinkedList<FishFood> listFishFood;
  Snail snail;
  int length;
  int width;
  int aquariumLifetime;

  Coordinate randomCoordinate(){
    double x = rand() % 480 + 1;
    double y = rand() % 640 + 1;
    Coordinate c(x,y);
    return c;
  }

  void initiateGuppy(){
    addGuppy();
    addGuppy();
  }
  void initiatePiranha(){
    addPiranha();
  }
  void initiateSnail(){
    snail.setX(460);
    snail.setY(20);
    snail.setSpeed(SNAIL_SPEED);
  }

public:
  int aquariumCoin = 10;
  int egg = 0;

  Aquarium(){
    length = MAX_LENGTH;
    width = MAX_WIDTH;
    srand (time(NULL));
  }
  Aquarium(int length, int width){
    this->length = length;
    this->width = width;
    srand (time(NULL));
  }

  void initiateMap(){
    initiateGuppy();
    initiatePiranha();
    initiateSnail();
  }

  void nextLifetime(){
    aquariumLifetime++;
  }

  void addGuppy(){
    Coordinate c = randomCoordinate();
    Guppy g(c.getX(),c.getY());
    listGuppy.add(g);
  }
  void addPiranha(){
    Coordinate c = randomCoordinate();
    Piranha p(c.getX(),c.getY());
    listPiranha.add(p);
  }
  void addCoin(double x, double y){
    Coin c(x,y);
    listCoin.add(c);
  }
  void addFishFood(double x){
    FishFood f(x,20);
    listFood.add(f);
  }

  int checkAlreadyWin(){
    if (egg == 3){
      return WIN;
    }else{
      if (listGuppy.size() == 0
          && listPiranha.size() == 0
          && aquariumCoin < GUPPY_PRICE){
            return LOSE;
          }else{
            return RUNNING;
          }
    }
  }

  int getAquariumLifetime(){
    return aquariumLifetime;
  }
  void setAquariumLifetime(int lifetime){
    this->aquariumLifetime = lifetime;
  }

};

#endif
