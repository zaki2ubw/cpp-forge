#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
  {
    try {
      std::cout << "===CASE1===" << std::endl;
      Bureaucrat p1("Tanaka", 42);
      std::cout << p1 << std::endl;
      p1.incrementGrade();
      std::cout << p1 << std::endl;
      p1.decrementGrade();
      std::cout << p1 << std::endl;
      std::cout << "===========" << std::endl;
      std::cout << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      std::cout << "===CASE2===" << std::endl;
      Bureaucrat p2("Yamada", 1);
      std::cout << p2 << std::endl;
      p2.incrementGrade();
      std::cout << p2 << std::endl;
      std::cout << "===========" << std::endl;
      std::cout << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      std::cout << "===CASE3===" << std::endl;
      Bureaucrat p3("Arakawa", 150);
      std::cout << p3 << std::endl;
      p3.decrementGrade();
      std::cout << p3 << std::endl;
      std::cout << "===========" << std::endl;
      std::cout << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      std::cout << "===CASE4===" << std::endl;
      Bureaucrat p4("Kitamura", 0);
      std::cout << p4 << std::endl;
      std::cout << "===========" << std::endl;
      std::cout << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      std::cout << "===CASE5===" << std::endl;
      Bureaucrat p5("Shinozaki", 151);
      std::cout << p5 << std::endl;
      std::cout << "===========" << std::endl;
      std::cout << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      std::cout << "===CASE6===" << std::endl;
      Bureaucrat p6("Kurashiki", -42);
      std::cout << p6 << std::endl;
      std::cout << "===========" << std::endl;
      std::cout << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  return 0;
}
