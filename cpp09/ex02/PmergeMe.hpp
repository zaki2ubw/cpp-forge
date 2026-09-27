#pragma once

#include <cstddef>
#include <utility>
#include <vector>

// Be template later

class PmergeMe {
public:
  PmergeMe(const std::vector<int> &origin);
  ~PmergeMe();
  void makePair();
  std::vector<std::size_t> sortLargeChain();
  std::vector<std::pair<int, size_t>>
  recursiveSortLarge(std::vector<std::pair<int, size_t>> origin);
  // debug
  void debugPrintPairs() const;

private:
  // Forbidden
  PmergeMe();
  PmergeMe(const PmergeMe &src);
  PmergeMe &operator=(const PmergeMe &src);
  // member
  std::vector<int> before;
  std::vector<std::pair<std::size_t, std::pair<int, int>>> paired;
  int unpaired;
  std::size_t sortCount;
};
