#include <climits>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "PmergeMe.hpp"

bool isPositiveInteger(const std::string &target) {
  long num = 0;
  int digit = 0;
  std::size_t len = target.length();
  for (std::size_t i = 0; i < len; ++i) {
    digit = target[i] - 0;
    if (num > (INT_MAX - digit) / 10)
      return false;
    num = num * 10 + digit;
  }
  if (num == 0)
    return false;
  return true;
}

bool isValidNumber(const std::string &target) {
  if (target.empty())
    return false;
  std::size_t len = target.length();
  for (std::size_t i = 0; i < len; ++i) {
    if (!std::isdigit(static_cast<unsigned char>(target[i])))
      return false;
  }
  if (!isPositiveInteger(target))
    return false;
  return true;
}

int toInteger(const std::string &target) {
  std::stringstream ss(target);
  int num = 0;
  ss >> num;
  return num;
}

// Be template later
void print_before(const std::vector<int> &vec) {
  std::cout << "Before: ";
  std::size_t len = vec.size();
  for (std::size_t i = 0; i < len; ++i) {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
  return;
}

int main(int argc, char **argv) {
  if (argc < 2)
    return 1;
  for (int i = 1; i < argc; ++i) {
    if (!isValidNumber(argv[i]))
      return 1;
  }
  std::vector<int> vec;
  for (int j = 1; j < argc; ++j) {
    vec.push_back(toInteger(argv[j]));
  }
  print_before(vec);
  return 0;
}
