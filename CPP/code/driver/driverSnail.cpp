#include "Snail.h"
#include <iostream>
using namespace std;

int main(){
  Snail s1;
  Snail s2(10, 10);

  LinkedList<Coin> listCoin;

  Coin c1(10, 10, 1);
  Coin c2(0, 0, 2);
  Coin c3(50, 10, 3);
  Coin c4(50, 0, 4);
  
  //cout<<c.getX()<<endl;
  listCoin.add(c1);
  listCoin.add(c2);
  listCoin.add(c3);
  listCoin.add(c4);

  cout << listCoin.size() << endl;
  //it should print 4

  cout << s1.eat(listCoin) << endl; //2
  cout << s1.eat(listCoin) << endl; //0
  cout << s2.eat(listCoin) << endl; //1
  cout << s2.eat(listCoin) << endl; //0


  return 0;
}