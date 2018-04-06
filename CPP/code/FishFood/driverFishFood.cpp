#include "FishFood.h"
#include <iostream>
using namespace std;

int main(){

  FishFood f(10, 10);

  cout<<f.getX()<<" "<<f.getY()<<endl;

  f.moveBottom();

  cout<<f.getX()<<" "<<f.getY()<<endl;

  return 0;
}
