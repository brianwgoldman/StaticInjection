#ifndef INJECTABLE_H
#define INJECTABLE_H
#include <iostream>

class Foo {
 public:
  void display() {
    std::cout << "This is the real class" << std::endl;    
  }
  int unused() {
    return 7;
  }
};

#endif
