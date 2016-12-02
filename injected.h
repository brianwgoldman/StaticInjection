#ifndef INJECTED_H
#define INJECTED_H

#include "FooProvider.h"

class Injected {
  decltype(INJECT_FOO) injected_var = INJECT_FOO;
  public:
  void display() {
    injected_var.display();
  }
};

#endif
