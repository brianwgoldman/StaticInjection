#ifndef FOO_H
#define FOO_H
#include <iostream>
#include "BarProvider.h"

class Foo {
 private:
  decltype(INJECT_BAR) bar = INJECT_BAR;
 public:
  void display(int x) {
    std::cout << "The square of " << x << " is " << bar.make_square(x) << std::endl;
  }
};

#endif
