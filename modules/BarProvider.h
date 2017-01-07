#ifndef BARPROVIDER_H
#define BARPROVIDER_H

#if defined BAR
  #include "Bar.h"
  #define INJECT_BAR Bar()
#elif defined BAR_FAKE
  #include "BarFake.h"
  #define INJECT_BAR BarFake()
#else
  "No Bar provider specified"
#endif

#endif
