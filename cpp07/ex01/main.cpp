#include <iostream>

#include "iter.hpp"
#include "test.hpp"

void printInt(int i) {
  std::cout << "Passed Int is " << i << std::endl;
  return;
}

void printStr(const std::string &str) {
  std::cout << "Passed String is " << str << std::endl;
  return;
}

void setHoge(std::string &target) {
  std::cout << "Origin String is " << target << std::endl;
  target = "Hoge";
  std::cout << "Current String is " << target << std::endl;
  return;
}

int main(void) {
  int intArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  const std::string cStrArray[7] = {"Sunday",    "Monday",   "Tuesday",
                                    "Wednesday", "Thursday", "Friday",
                                    "Saturday"};
  std::string strArray[3] = {"Top", "Middle", "Bottom"};

  std::cout << "===Int Case===" << std::endl;
  ::iter(intArray, 10, printInt);
  std::cout << "===Case End===" << std::endl;
  std::cout << std::endl;

  std::cout << "===Template Case===" << std::endl;
  ::iter(intArray, 10, ::echo<int>);
  ::iter(cStrArray, 7, ::echo<const std::string>);
  std::cout << "===Case End===" << std::endl;
  std::cout << std::endl;

  std::cout << "===Const String Case===" << std::endl;
  ::iter(cStrArray, 7, printStr);
  std::cout << "===Case End===" << std::endl;
  std::cout << std::endl;

  std::cout << "===nonConst String Case===" << std::endl;
  ::iter(strArray, 3, setHoge);
  std::cout << "===Case End===" << std::endl;
  std::cout << std::endl;

  return 0;
}
