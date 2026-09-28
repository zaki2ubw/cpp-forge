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

BasePairVector PmergeMe::recursiveSortLarge(BasePairVector currentLargeChain) {
  ComparePairVector currentPairs;
  BasePair currentUnpaired;
  BasePairVector nextLargeChain;
  BasePairVector sortedLargeChain;
  std::size_t len = currentLargeChain.size();
  // TODO: base case
  if (len <= 1)
    return currentLargeChain;

  // TODO: make compare pairs from currentLargeChain
  std::size_t i = 0;
  while (1) {
    if (len - i <= 1)
      break;
    ComparePair currentPair;
    BasePair left = currentLargeChain[i].first;
    BasePair right = currentLargeChain[i + 1].first;
    // TODO: compare each pair and decide small / large
    // TODO: increment sortCount for each value comparison
    ++this->sortCount;
    if (left <= right) {
      currentPair.first = left;
      currentPair.second = right;
    } else {
      currentPair.first = right;
      currentPair.second = left;
    }
    currentPairs.push_back(currentPair);
    i += 2;
  }

  // TODO: if odd, keep currentUnpaired
  if (i < len)
    currentUnpaired = currentLargeChain[i];

  // TODO: build nextLargeChain from each pair's large side
  std::size_t largeSide = len / 2;
  for (std::size_t j = 0; j < largeSide; ++j) {
    nextLargeChain.push_back(currentPairs[j].second);
  }

  // TODO: recursively sort nextLargeChain
  sortedLargeChain = PmergeMe::recursiveSortLarge(nextLargeChain);

  // TODO: verify recursive return / restore current level state

  // TODO: later: rebuild Main / Pend and insert
}
