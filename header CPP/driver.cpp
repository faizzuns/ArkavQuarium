#include <iostream>
using namespace std;

class A{
public:
  virtual void f() = 0;
};

class B : public A{

};

class C : public B{
public:
  void f(){
    cout<<"ea"<<endl;
  }
};

int main (){
  B b;
  b.f();
  return 0;
}
