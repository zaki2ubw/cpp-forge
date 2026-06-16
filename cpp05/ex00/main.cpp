#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
  {
    try {
      Bureaucrat p1("Tanaka", 42);
      std::cout << p1 << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      Bureaucrat p2("Yamada", 1);
      std::cout << p2 << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      Bureaucrat p3("Arakawa", 150);
      std::cout << p3 << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      Bureaucrat p4("Kitamura", 0);
      std::cout << p4 << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      Bureaucrat p5("Shinozaki", 151);
      std::cout << p5 << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      Bureaucrat p6("Kurashiki", -42);
      std::cout << p6 << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      Bureaucrat p7("Kitahara", 5);
      while (1) {
        p7.incrementGrade();
        std::cout << p7 << std::endl;
      }
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      Bureaucrat p8("Wada", 145);
      while (1) {
        p8.decrementGrade();
        std::cout << p8 << std::endl;
      }
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  return 0;
}
