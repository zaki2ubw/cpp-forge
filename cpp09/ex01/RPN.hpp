#pragma once
#include <string>

class RPN {
public:
  RPN();
  RPN(const RPN &src);
  RPN &operator=(const RPN &src);
  ~RPN();

  int calculate(const std::string &expression) const;

private:
  bool isNumber(const std::string &token) const;
  bool isOperator(const std::string &token) const;
  int applyOperator(int left, int right, char op) const;
};
