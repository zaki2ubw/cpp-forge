#include <deque>
#include <vector>

#include "PmergeMe.hpp"
#include "VectorFordJohnson.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) { *this = src; }

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
  if (this != &src) {
    jacobVector = src.jacobVector;
    vectorResult = src.vectorResult;
    dequeResult = src.dequeResult;
    jacobTimeUs = src.jacobTimeUs;
    vectorTimeUs = src.vectorTimeUs;
    dequeTimeUs = src.dequeTimeUs;
    vectorSortCount = src.vectorSortCount;
    dequeSortCount = src.dequeSortCount;
    theoreticalMax = src.theoreticalMax;
  }
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
