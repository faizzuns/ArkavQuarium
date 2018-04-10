#include "Node.h"
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  Node<int> node(10);

  int x = node.getData();
  cout<<"Get Data from getData() from ctor = "<<x<<endl;
  node.setData(5);
  x = node.getData();
  cout<<"Get Data from setData()           = "<<x<<endl;

  
  Node<int> *n = node.getNext();
  if (n == NULL) {
      cout<<"Get next when next Null           = EA"<<endl;
  }
  n = new Node<int>(3);
  node.setNext(n);
  cout << "Set next node with new node        " << endl;

  n = node.getNext();
  cout << "Get data from next node           = " << n->getData() <<endl;


}
