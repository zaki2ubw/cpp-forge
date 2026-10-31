#include <list>
#include <sstream>
#include <stack>
#include <string>

#include "RPN.hpp"

int RPN::calculate(const std::string &expression) const {
  // stackを用意
  std::stack<int, std::list<int>> calcStack;
  // stringstreamにexpressionを入れる
  std::stringstream ss(expression);
  std::string token;
  while (ss >> token) {
    if (RPN::isNumber(token))
      calcStack.push(token);
    else if (RPN::isOperator(token)) {
      // stackに2個未満しかなければError
      if (calcStack.size() < 2)
        throw std::runtime_error("Error");
      int right = calcStack.top();
      calcStack.pop();

      int left = calcStack.top();
      calcStack.pop();

      int result = applyOperator(left, right, token[0]);
      calcStack.push(result);
    } else
      return -1;
  }
  // 最後にstackの要素数が1でなければError
  if (calcStack.size() != 1)
    throw std::runtime_error("Error");
  return calcStack.top();
}
