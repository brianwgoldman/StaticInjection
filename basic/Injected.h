#ifndef INJECTED_H
#define INJECTED_H

#include "FooProvider.h"

class Injected {
  decltype(INJECT_FOO) foo = INJECT_FOO;
  public:
  void display() {
    foo.display();
  }
};

#endif
