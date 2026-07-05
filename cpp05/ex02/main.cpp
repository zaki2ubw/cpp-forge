#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void) {
  {
    std::cout << "=== CASE1: Normal Start ===" << std::endl;
    try {
      Form f1("TEST01", 50, 45);
      std::cout << f1 << std::endl;
      Bureaucrat p1("Tanaka", 42);
      std::cout << p1 << std::endl;
      p1.signForm(f1);
      std::cout << f1 << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    std::cout << "=== CASE1: Normal End ===" << std::endl;
  }
  std::cout << std::endl;
  {
    std::cout << "=== CASE2: Boundary Start ===" << std::endl;
    try {
      Form f2("TEST02", 150, 1);
      std::cout << f2 << std::endl;
      Bureaucrat p2("Yamada", 1);
      std::cout << p2 << std::endl;
      p2.signForm(f2);
      std::cout << f2 << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    std::cout << "=== CASE2: Boundary End ===" << std::endl;
  }
  std::cout << std::endl;
  {
    std::cout << "=== CASE3: Sign Failed Start ===" << std::endl;
    try {
      Form f3("TEST03", 50, 42);
      std::cout << f3 << std::endl;
      Bureaucrat p3("Arakawa", 150);
      std::cout << p3 << std::endl;
      p3.signForm(f3);
      std::cout << f3 << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    std::cout << "=== CASE3: Sign Failed End ===" << std::endl;
  }
  std::cout << std::endl;
  {
    std::cout << "=== CASE4: Grade High Start ===" << std::endl;
    try {
      Form f4("TEST04", 150, 0);
      std::cout << f4 << std::endl;
      Bureaucrat p4("Kitamura", 1);
      std::cout << p4 << std::endl;
      p4.signForm(f4);
      std::cout << f4 << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    std::cout << "=== CASE4: Grade High End ===" << std::endl;
  }
  std::cout << std::endl;
  {
    std::cout << "=== CASE5: Grade Low Start ===" << std::endl;
    try {
      Form f5("TEST05", 151, 1);
      std::cout << f5 << std::endl;
      Bureaucrat p5("Shinozaki", 52);
      std::cout << p5 << std::endl;
      p5.signForm(f5);
      std::cout << f5 << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    std::cout << "=== CASE5: Grade Low End ===" << std::endl;
  }
  std::cout << std::endl;
  {
    std::cout << "=== CASE6: Already Signed Start ===" << std::endl;
    try {
      Form f6("TEST06", 50, 42);
      std::cout << f6 << std::endl;
      Bureaucrat p6("Kurashiki", 40);
      std::cout << p6 << std::endl;
      p6.signForm(f6);
      std::cout << f6 << std::endl;
      p6.signForm(f6);
      std::cout << f6 << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    std::cout << "=== CASE6: Already Signed End ===" << std::endl;
  }
  return 0;
}
