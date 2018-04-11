#include "LinkedList.h"
using namespace std;

int main(){

  LinkedList<int> list;

  cout<<list.size()<<endl;

  list.add(1);
  list.add(2);
  list.add(3);
  list.add(4);
  list.add(5);
  list.add(6);
  list.add(7);
  list.add(8);
  list.add(9);
  list.add(10);

  cout<<list.size()<<endl;

  cout<<list.get(2)<<endl;

  list.remove(5);

  cout<<list.size()<<endl;

  return 0;
}
