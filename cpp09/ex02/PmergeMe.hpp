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

private:
  // Forbidden
  PmergeMe();
  PmergeMe(const PmergeMe &src);
  PmergeMe &operator=(const PmergeMe &src);
  // member
  std::vector<int> before;
  std::vector<std::pair<std::size_t, std::pair<int, int>>> paired;
  int unpaired;
};
