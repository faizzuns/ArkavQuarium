#ifndef NODE_H
#define NODE_H
#include <cstdio>
#include <iostream>

template <class T>
class Node{
private:
  T data;
  Node<T> *next;

public:

  Node(){
    next = NULL;
  }

  Node(T data){
    this->data = data;
    next = NULL;
  }

  ~Node(){
    delete next;
  }

  T getData() {return data;}
  void setData(T data) {this->data = data;}
  Node<T> *getNext(){return next;}
  void setNext(Node<T> *next){this->next = next;}
};

#endif
