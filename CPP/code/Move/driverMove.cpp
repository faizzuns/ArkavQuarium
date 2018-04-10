#include "Move.h"
#include <iostream>
using namespace std;

int main(){

  Move m(10,10,10);

  cout << "Current position     : (" << m.getX() <<"," << m.getY()<< ")" << endl; 
  m.moveBottom();
  cout << "Setelah move bottom  : (" << m.getX() <<"," << m.getY()<< ")" << endl; 
  m.moveTop();
  cout << "Setelah move top     : (" << m.getX() <<"," << m.getY()<< ")" << endl; 
  m.moveRight();
  cout << "Setelah move right   : (" << m.getX() <<"," << m.getY()<< ")" << endl; 
  m.moveLeft();
  cout << "Setelah move left    : (" << m.getX() <<"," << m.getY()<< ")" << endl; 

  cout<<  "Current speed        : "<<m.getSpeed()<<endl;
  m.setSpeed(11);
  cout<<  "Setelah setSpeed     : "<<m.getSpeed()<<endl;

  return 0;
}
