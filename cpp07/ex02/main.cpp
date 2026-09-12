#include <iostream>
#include <string>

#include "Array.hpp"

int main(void) {
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
  {
    std::cout << "===Case00 Writable Array===" << std::endl;
    Array<int> a(3);
    a[1] = 42;
    std::cout << "Value of a[1] = " << a[1] << std::endl;
    std::cout << "===Case00 End===" << std::endl;
    std::cout << std::endl;
  }
  {
    std::cout << "===Case01 String Array===" << std::endl;
    Array<std::string> a(3);
    a[0] = "Hoge";
    a[1] = "Fuga";
    a[2] = "Piyo";
    std::cout << a[0] << std::endl;
    std::cout << a[1] << std::endl;
    std::cout << a[2] << std::endl;
    std::cout << "===Case01 End===" << std::endl;
    std::cout << std::endl;
  }
  {
    std::cout << "===Case02 Const Array===" << std::endl;
    const Array<int> a(1);
    std::cout << "Value of a[0] = " << a[0] << std::endl;
    std::cout << "===Case02 End===" << std::endl;
    std::cout << std::endl;
  }
  {
    std::cout << "===Case03 OutOfBounds===" << std::endl;
    try {
      Array<int> a(3);
      std::cout << "4th Value is " << a[4] << std::endl;
    } catch (const std::exception &e1) {
      std::cout << e1.what() << std::endl;
    }
    try {
      Array<int> b;
      std::cout << "Empty Array b's First Value is " << b[0] << std::endl;
    } catch (const std::exception &e2) {
      std::cout << e2.what() << std::endl;
    }
    std::cout << "===Case03 End===" << std::endl;
    std::cout << std::endl;
  }
  {
    std::cout << "===Case04 Copy Constructor===" << std::endl;
    Array<int> a(3);
    a[0] = 0;
    a[1] = 10;
    a[2] = 20;
    Array<int> b(a);
    for (std::size_t i = 0; i < 3; ++i) {
      std::cout << "Current a is " << a[i] << std::endl;
      std::cout << "Current b is " << b[i] << std::endl;
    }
    b[0] = 999;
    if (a[0] == b[0])
      std::cout << "Copy Constructor is Working incorrect" << std::endl;
    else
      std::cout << "Copy Constructor is Working Correct" << std::endl;
    std::cout << "===Case04 End===" << std::endl;
    std::cout << std::endl;
  }
  {
    std::cout << "===Case05 Deep Copy===" << std::endl;
    try {
      Array<int> a(3);
      Array<int> b(5);
      a[0] = 1;
      a[1] = 2;
      a[2] = 3;
      b[0] = 10;
      b[1] = 20;
      b[2] = 30;
      b[3] = 40;
      b[4] = 50;
      std::cout << "Initial a.size() = " << a.size() << std::endl;
      std::cout << "Initial a[0] = " << a[0] << std::endl;
      std::cout << "Initial a[2] = " << a[2] << std::endl;
      a = b;
      std::cout << "Assigned a.size() = " << a.size() << std::endl;
      std::cout << "Current a[0] = " << a[0] << std::endl;
      std::cout << "Current a[2] = " << a[2] << std::endl;
    } catch (const std::exception &e1) {
      std::cout << e1.what() << std::endl;
    }
    try {
      Array<int> a(3);
      Array<int> b(5);
      a[0] = 1;
      a[1] = 2;
      a[2] = 3;
      b[0] = 10;
      b[1] = 20;
      b[2] = 30;
      b[3] = 40;
      b[4] = 50;
      std::cout << "Initial b.size() = " << b.size() << std::endl;
      std::cout << "Initial b[0] = " << b[0] << std::endl;
      std::cout << "Initial b[2] = " << b[2] << std::endl;
      b = a;
      std::cout << "Assigned b.size() = " << b.size() << std::endl;
      std::cout << "Current b[0] = " << b[0] << std::endl;
      std::cout << "Current b[2] = " << b[2] << std::endl;
    } catch (const std::exception &e2) {
      std::cout << e2.what() << std::endl;
    }
    std::cout << "===Case05 End===" << std::endl;
    std::cout << std::endl;
  }
  {
    std::cout << "===Case06 Self Assignment===" << std::endl;
    Array<int> a(3);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    std::cout << "Initial a.size() = " << a.size() << std::endl;
    for (std::size_t i = 0; i < 3; ++i) {
      std::cout << "a[i] = " << a[i] << std::endl;
    }
    a = a;
    std::cout << "Current a.size() = " << a.size() << std::endl;
    for (std::size_t l = 0; l < 3; ++l) {
      std::cout << "a[l] = " << a[l] << std::endl;
    }
    std::cout << "===Case06 End===" << std::endl;
    std::cout << std::endl;
  }
  {
    std::cout << "===Case07 Empty Array===" << std::endl;
    Array<int> empty;
    Array<int> a(3);
    Array<int> b(5);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    b[0] = 10;
    b[1] = 20;
    b[2] = 30;
    b[3] = 40;
    b[4] = 50;
    std::cout << "Initial a.size() = " << a.size() << std::endl;
    std::cout << "Initial b.size() = " << b.size() << std::endl;
    a = empty;
    std::cout << "Current a.size() = " << a.size() << std::endl;
    empty = b;
    std::cout << "Current empty.size() = " << empty.size() << std::endl;
    std::cout << "===Case07 End===" << std::endl;
    std::cout << std::endl;
  }

  return 0;
}
