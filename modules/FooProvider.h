#ifndef FOOPROVIDER_H
#define FOOPROVIDER_H

#if defined FOO
  #include "Foo.h"
  #define INJECT_FOO Foo()
#elif defined FOO_FAKE
  #include "FooFake.h"
  #define INJECT_FOO FooFake()
#else
  "No Foo provider specified"
#endif

#endif
