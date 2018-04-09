#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <cstdio>
#include "Node.h"
using namespace std;

template <class T>
class LinkedList{
private:
  Node<T> *head;

public:

  //Default Constructor
  LinkedList(){
    head = NULL;
  }

  //Destructor
  //delete memory
  ~LinkedList(){
    delete head;
  }

  //will return true if size = 0
  bool isEmpty(){
    if (head == NULL) return true;
    else return false;
  }

  int size(){
    int count = 0;
    Node<T> *now = head;
    while (now != NULL) {
      count++;
      now = now->getNext();
    }
    return count;
  }

  //add element to list (adding to last of list)
  void add(T element){
    if (head == NULL){
      head = new Node<T>(element);
      cout<<"Satu kali aja"<<endl;
    }
    else{
      Node<T> *temp = head;
      while (temp->getNext() != NULL) temp = temp->getNext();
      temp->setNext(new Node<T>(element));
      cout<<"yang selanjutnya"<<endl;
    }
  }

  //remove element in list with value 'element'
  bool remove(T element){
    Node<T> *prev = NULL;
    Node<T> *now = head;

    while (now != NULL && now->getData() != element){
      prev = now;
      now = now->getNext();
      cout<<"EA"<<endl;
    }

    if (now != NULL){
      if (prev != NULL){
        prev->setNext(now->getNext());
      }else{
        head = now->getNext();
      }
      now->setNext(NULL);
      delete now;
      return true;
    }else return false;

  }

  bool remove(int idx){
    Node<T> *prev = NULL;
    Node<T> *now = head;

    cout<<idx<<endl;
    int i = 0;
    while (i < idx){
      cout<<"FAIZ HEBAT"<<endl;
      prev = now;
      now = now->getNext();
      i++;
    }

    if (now != NULL){
      if (prev != NULL){
        prev->setNext(now->getNext());
      }else{
        head = now->getNext();
      }
      now->setNext(NULL);
      delete now;
      return true;
    }else return false;

  }

  //return value (type = T)
  T get(int index){
    if (index < size()){
      Node<T> *now = head;
      int i = 0;
      while (i < index) {
        now = now->getNext();
        i++;
      }
      return now->getData();
    }else{
      throw "Index out of Bound";
    }
  }

  T* getRef(int index){
    if (index < size()){
      Node<T> *now = head;
      int i = 0;
      while (i < index) {
        now = now->getNext();
        i++;
      }
      return now->getDataRef();
    }else{
      throw "Index out of Bound";
    }
  }

  Node<T>* getNode(int index){
    if (index < size()){
      Node<T> *now = head;
      int i = 0;
      while (i < index) {
        now = now->getNext();
        i++;
      }
      return now;
    }else{
      throw "Index out of Bound";
    }
  }
};

#endif
