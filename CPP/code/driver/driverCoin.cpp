#include "Coin.h"
#include <iostream>
using namespace std;

int main(){

  Coin c(10,10,10);

  cout<< "Value Awal                    : "<< c.getValue() <<endl;
  c.setValue(100);
  cout<< "Value Akhir setelah setValue  : "<< c.getValue() <<endl;

  cout<< "Posisi awal                   :(" << c.getX() <<","<<c.getY()<<")"<<endl;
  c.moveBottom();
  cout<< "Posisi setelah move bottom    :(" << c.getX() <<","<<c.getY()<<")"<<endl;

  return 0;
}
