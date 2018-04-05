#include "Coordinate.h"
using namespace std;

int main(){

  Coordinate c;

  cout<<c.getX()<<" "<<c.getY()<<endl;

  c.setX(10);
  c.setY(88);

  cout<<c.getX()<<" "<<c.getY()<<endl;

  return 0;
}
