#include "Move.h"
#include <iostream>
using namespace std;

int main(){

  Move m(10,10,10);

  m.moveBottom();
  m.moveTop();
  m.moveRight();
  m.moveLeft();

  cout<<"SPEED = "<<m.getSpeed()<<endl;
  m.setSpeed(11);
  cout<<"NOW SPEED = "<<m.getSpeed()<<endl;

  return 0;
}
