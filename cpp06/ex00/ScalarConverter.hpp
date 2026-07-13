#pragma once

#include <string>

class ScalarConverter {
public:
  // Static method
  static void convert(const std::string &target) const;

private:
  enum e_types { INVALIDFORM = 0, CHAR, INT, FLOAT, DOUBLE };

  // Forbidden OCF Functions
  ScalarConverter();
  ~ScalarConverter();
  ScalarConverter(const ScalarConverter &src);
  ScalarConverter &operator=(const ScalarConverter &src);
}
