// objects example
#include <iostream>

using namespace std;

class Object {
  public:
    Object();
    void printI() { cout << i << endl;};
    void setI(int val) { i = val;};
  private:
    int i;
};

Object::Object() { new int;};

class Test{
  public:
    int i;
    Object o;
    Test(){
      //i=4;}
      o.setI(5);};
  private:
  };

int main() {
  Test t;
  t.o.printI();
  t.i = 4;
  return 0;
}
