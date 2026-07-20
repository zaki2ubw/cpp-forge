#pragma once

#include <string>

class ScalarConverter {
public:
  // Static method
  static void convert(const std::string &target);

private:
  // Forbidden OCF Functions
  ScalarConverter();
  ~ScalarConverter();
  ScalarConverter(const ScalarConverter &src);
  ScalarConverter &operator=(const ScalarConverter &src);
};
