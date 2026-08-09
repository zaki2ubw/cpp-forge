#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include "TypeIdentifier.hpp"

Base *generate(void) {
  int pick = std::rand() % 3;
  Base *result = NULL;
  if (pick == 0)
    result = new A;
  else if (pick == 1)
    result = new B;
  else
    result = new C;
  return result;
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    print_realType("A");
  else if (dynamic_cast<B *>(p))
    print_realType("B");
  else if (dynamic_cast<C *>(p))
    print_realType("C");
  else
    std::cout << "[ERROR] Unknown Type" << std::endl;
  return;
}

void identify(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    print_realType("A");
    return;
  } catch (std::exception &e) {
    // Go Next
  }
  try {
    (void)dynamic_cast<B &>(p);
    print_realType("B");
    return;
  } catch (std::exception &e) {
    // Go Next
  }
  try {
    (void)dynamic_cast<C &>(p);
    print_realType("C");
    return;
  } catch (std::exception &e) {
    // Go Next
  }
  std::cout << "[ERROR] Unknown Type" << std::endl;
  return;
}

void print_realType(const std::string &type) {
  std::cout << type << std::endl;
  return;
}
