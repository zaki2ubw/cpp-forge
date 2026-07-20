#include <iostream>
#include <string>

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "USAGE: ./convert target" << std::endl;
    return 1;
  }
  std::string target(argv[1]);
  ScalarConverter::convert(target);
  return 0;
}
