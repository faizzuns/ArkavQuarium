#include "FishFood.h"
#include <iostream>
using namespace std;

int main(){

  FishFood f(10, 10);

  cout<< "Posisi awal                :(" <<f.getX()<<","<<f.getY()<<")"<<endl;

  f.moveBottom();

  cout<< "Posisi setelah move bottom :(" << f.getX()<<","<<f.getY()<<")"<<endl;

  return 0;
}
