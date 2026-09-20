#include <exception>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

int main(void) {
  std::vector<int> v;
  std::list<int> l;
  int val = 10;
  for (int i = 0; i < 5; ++i) {
    v.push_back(val);
    l.push_back(val);
    val += 10;
  }

  try {
    std::cout << *(easyfind(v, 20)) << std::endl;
    std::cout << *(easyfind(v, 60)) << std::endl;
  } catch (const std::exception &e1) {
    std::cout << e1.what() << std::endl;
  }
  try {
    std::cout << *(easyfind(l, 20)) << std::endl;
    std::cout << *(easyfind(l, 60)) << std::endl;
  } catch (const std::exception &e2) {
    std::cout << e2.what() << std::endl;
  }
  return 0;
}
