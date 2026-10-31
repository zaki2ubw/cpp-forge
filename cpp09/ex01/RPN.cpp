#include <list>
#include <sstream>
#include <stack>
#include <string>

int RPN::calculate(const std::string &expression) {
#stackを用意
  std::stack<int, std::list<int>> calcStack;
#stringstreamにexpressionを入れる
  stringstream ss = expression;
  int token while (ss >> token) if (RPN::isNumber(token)) calcStack.push(token);

  else if (RPN::isOperator(token)) {
#stackに2個未満しかなければError
    if (stack.size() < 2)
      return -1;
    int right = calcStack.top();
    calcStack.pop();

    int left = calcStack.top();
    calcStack.pop();

    result = applyOperator(left, right, operator) calcStack.push(result);
  }
  else return -1;

#最後にstackの要素数が1でなければError
  if (calcStack.size() != 1)
    return -1;
  return calcStack.top();
}
