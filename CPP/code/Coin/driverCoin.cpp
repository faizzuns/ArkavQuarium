#include "Coin.h"
#include <iostream>
using namespace std;

int main(){

  Coin c(10,10,10);

  c.getValue();
  c.setValue(100);
  c.getValue();

  cout<<c.getX()<<" "<<c.getY()<<endl;
  c.moveBottom();
  cout<<c.getX()<<" "<<c.getY()<<endl;

  return 0;
}
