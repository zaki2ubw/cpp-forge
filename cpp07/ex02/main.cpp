#include <iostream>
#include <string>

#include "Array.hpp"

int main(void) {
  {
    std::cout << "===Case===" << std::endl;
    std::cout << "===Case End===" << std::endl;
    std::cout << std::endl;
  }
  {
    std::cout << "===Default int Case===" << std::endl;
    Array<int> a;
    std::cout << "Size of Default Array=" << a.size() << std::endl;
    std::cout << "===Case End===" << std::endl;
    std::cout << std::endl;
  }
  {
    std::cout << "===Default String Case===" << std::endl;
    Array<std::string> a;
    std::cout << "Size of Default Array=" << a.size() << std::endl;
    std::cout << "===Case End===" << std::endl;
    std::cout << std::endl;
  }
  {
    std::cout << "===Int Case===" << std::endl;
    try {
      Array<int> a(10);
      for (std::size_t i = 0; i < 10; ++i) {
        if (a[i] != 0)
          std::cout << "Code must be incorrect" << std::endl;
      }
      std::cout << "All Array values are initialized as " << a[0] << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    std::cout << "===Case End===" << std::endl;
    std::cout << std::endl;
  }

  return 0;
}
