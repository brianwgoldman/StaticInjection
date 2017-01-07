#include "ModuleFake.h"
#include "Injected.h"
#include "Foo.h"

int main() {
  Foo foo;
  // Uses the real Foo but the fake Bar
  foo.display(19);
  return 0;
}
