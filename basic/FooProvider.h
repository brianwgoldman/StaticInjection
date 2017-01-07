#ifndef FOOPROVIDER_H
#define FOOPROVIDER_H

#ifndef FOO_FAKE
  #include "Foo.h"
  #define INJECT_FOO Foo()
#else
  #include "FooFake.h"
  #define INJECT_FOO FooFake()
#endif

#endif
