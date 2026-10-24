#include <vector>

#include "PmergeMe.hpp"
#include "VectorFordJohnson.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const std::vector<int> &origin) : before(origin) {}

PmergeMe::PmergeMe(const PmergeMe &src) : before(src.before) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
  if (this != &src)
    before = src.before;
  return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<int> PmergeMe::sortVector() const {
  VectorFordJohnson sorter(before);
  return sorter.mergeInsertionSort();
}

void PmergeMe::benchmark() {
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
