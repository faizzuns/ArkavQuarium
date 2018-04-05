#ifndef AQUARIUM_H
#define AQUARIUM_H
#include <iostream>

#define MAX_LENGTH 100
#define MAX_WIDTH 100

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

  Coordinate randomCoordinate();

  void initiateGuppy();
  void initiatePiranha();
  void initiateSnail();

public:
  int aquariumCoin = 10;
  int egg = 0;

  Aquarium();
  Aquarium(int length, int width);
  ~Aquarium();

  void initiateMap();

  void nextLifetime();

  void addGuppy();
  void addPiranha();
  void addCoin();
  void addFishFood();

  int checkAlreadyWin();

  int getAquariumLifetime();
  void setAquariumLifetime(int lifetime);

};

#endif
