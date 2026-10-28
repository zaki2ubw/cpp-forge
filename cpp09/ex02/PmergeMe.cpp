#include <deque>
#include <vector>

#include "PmergeMe.hpp"
#include "VectorFordJohnson.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src){}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
  return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::benchmark(int argc, char **argv) {
  // 1. 前回状態をreset

  // 2. Jacob生成 + 計測

  // 3. raw input -> vector
  //    VectorFordJohnson実行 + 計測

  // 4. raw input -> deque
  //    DequeFordJohnson実行 + 計測

  // 5. sortCount取得

  // 6. theoreticalMax計算

  // 7. auditResults()
}
