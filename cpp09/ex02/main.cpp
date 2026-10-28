#include <cctype>
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
    digit = target[i] - '0';
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

void print_before(int argc, char **argv) {
  std::cout << "Before: ";
  for (int i = 1; i < argc; ++i)
    std::cout << argv[i] << " ";
  std::cout << std::endl;
}

void print_after(const std::vector<int> &vec) {
  std::cout << "After : ";
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

  try {
    PmergeMe runner;

    print_before(argc, argv);

    runner.benchmark(argc, argv);

    print_after(runner.getResult());

    std::cout << "Time to process a range of " << argc - 1
              << " elements with std::vector : " << runner.getVectorTimeUs()
              << " us" << std::endl;

    std::cout << "Time to process a range of " << argc - 1
              << " elements with std::deque  : " << runner.getDequeTimeUs()
              << " us" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
