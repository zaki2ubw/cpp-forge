#include <cstddef>
#include <utility>
#include <vector>

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::vector<int> &origin)
    : before(origin), unpaired(0), sortCount(0) {}

PmergeMe::~PmergeMe() {}

void PmergeMe::makePair() {
  std::size_t len = this->before.size();
  std::size_t i = 0;
  std::size_t id = 0;
  while (1) {
    if (len - i <= 1)
      break;
    int left = before[i];
    int right = before[i + 1];
    std::pair<int, int> current_val;
    ++sortCount;
    if (left <= right) {
      current_val.first = left;
      current_val.second = right;
    } else {
      current_val.first = right;
      current_val.second = left;
    }
    std::pair<std::size_t, std::pair<int, int>> current_pair;
    current_pair.first = id;
    current_pair.second = current_val;
    this->paired.push_back(current_pair);
    i += 2;
    ++id;
  }
  if (i < len) {
    this->unpaired = before[i];
  }
  return;
}

std::vector<std::pair<int, size_t>>
PmergeMe::recursiveSortLarge(std::vector<std::pair<int, size_t>> origin) {}
