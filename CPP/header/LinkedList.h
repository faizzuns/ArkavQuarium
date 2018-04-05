#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

template <class T>
class LinkedList{
private:
  T data; //data
  LinkedList *next; //for check next of lists

public:
  //Default Constructor
  LinkedList(T data);

  //Destructor
  //delete memory
  ~LinkedList();

  //will return true if size = 0
  bool isEmpty();

  //add element to list (adding to last of list)
  void add(T element);

  //remove element in list with value 'element'
  void remove(T element);

  //return value (type = T)
  T get(int index);
};

#endif
