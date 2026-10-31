#include <list>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

bool RPN::isNumber(const std::string &token) const {
  return token.size() == 1 && token[0] >= '0' && token[0] <= '9';
}

bool RPN::isOperator(const std::string &token) const {
  if (token.size() != 1)
    return false;

  return token[0] == '+' || token[0] == '-' || token[0] == '*' ||
         token[0] == '/';
}

int RPN::applyOperator(int left, int right, char op) const {
  if (op == '+')
    return left + right;
  if (op == '-')
    return left - right;
  if (op == '*')
    return left * right;
  if (op == '/') {
    if (right == 0)
      throw std::runtime_error("Error");
    return left / right;
  }

  throw std::runtime_error("Error");
}

int RPN::calculate(const std::string &expression) const {
  std::stack<int, std::list<int> > calcStack;
  std::stringstream ss(expression);
  std::string token;
  while (ss >> token) {
    if (RPN::isNumber(token))
      calcStack.push(token[0] - '0');
    else if (RPN::isOperator(token)) {
      if (calcStack.size() < 2)
        throw std::runtime_error("Error");
      int right = calcStack.top();
      calcStack.pop();

      int left = calcStack.top();
      calcStack.pop();

      int result = applyOperator(left, right, token[0]);
      calcStack.push(result);
    } else
      throw std::runtime_error("Error");
  }
  if (calcStack.size() != 1)
    throw std::runtime_error("Error");
  return calcStack.top();
}
