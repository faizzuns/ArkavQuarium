#include "Node.h"
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  Node<int> node(10);

  int x = node.getData();
  cout<<x<<endl;
  node.setData(5);
  x = node.getData();
  cout<<x<<endl;

  Node<int> *n = node.getNext();

  if (n == NULL) cout<<"EA"<<endl;

  n = new Node<int>(3);
  node.setNext(n);

  n = node.getNext();

  cout<<n->getData()<<endl;
}
