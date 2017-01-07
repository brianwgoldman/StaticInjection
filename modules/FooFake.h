#ifndef FOOFAKE_H
#define FOOFAKE_H
#include <iostream>

class FooFake {
 public:
  void display(int) {
    std::cout << "This is using FooFake" << std::endl;
  }
};

#endif
