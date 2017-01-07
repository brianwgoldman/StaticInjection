#include <iostream>

#include "ModuleFake.h"
#include "Bar.h"

using std::cout;
using std::endl;

int main() {
  Bar bar;
  if (bar.make_square(12) == 144) {
    cout << "Passed" << endl;
  } else {
    cout << "Failed" << endl;
  }
  return 0;
}
