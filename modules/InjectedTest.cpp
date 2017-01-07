#include "ModuleFake.h"
#include "Injected.h"

int main() {
  Injected injected;
  // Uses FooFake, which has no dependencies
  injected.display();
  return 0;
}
