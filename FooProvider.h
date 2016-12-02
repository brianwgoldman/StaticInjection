#ifndef PROVIDER_H
#define PROVIDER_H

#ifndef TESTING
  #include "Foo.h"
  #define INJECT_FOO Foo()
#else
  #include "FooFake.h"
  #define INJECT_FOO FooFake()
#endif

#endif
