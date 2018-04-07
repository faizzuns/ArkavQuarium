#include "Coin.h"
#include <iostream>
using namespace std;

int main(){

  Coin c(10,10,10);

  c.getValue();
  c.setValue(100);
  c.getValue();

  return 0;
}
