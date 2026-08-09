#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Base.hpp"
#include "TypeIdentifier.hpp"

int main(void) {
  std::srand(std::time(NULL));

  Base *target;
  try {
    target = generate();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  identify(target);
  identify(*target);
  delete target;
  return 0;
}
