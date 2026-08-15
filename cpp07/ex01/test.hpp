#pragma once

#include <iostream>

template <typename T> void echo(T &t) {
  std::cout << "Passed Argument is " << t << std::endl;
  return;
}
