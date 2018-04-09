#include "Snail.h"
#include <iostream>
using namespace std;

int main(){
  Snail s(10,10);

  LinkedList<Coin> *list = new LinkedList<Coin>();

  Coin c(10,10,2);
  //cout<<c.getX()<<endl;
  list->add(c);
  list->add(c);

  cout<<list->size()<<endl;


  //cout<<list.get(0).getX()<<endl;

  // int i = 0;
  // while (list.size() != 0) {
  //   /* code */
  //   cout<<list.get(0).getY()<<endl;
  //   s.eat(list);
  //   Node<Coin> *node = list.getNode(0);
  //   c.setY(c.getY() + 1);
  //   node->setData(c);
  // }

  return 0;
}
