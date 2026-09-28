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
    std::pair<std::size_t, std::pair<int, int> > current_pair;
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

std::vector<std::size_t> PmergeMe::sortLargeChain() {
  BasePairVector currentLargeChain;
  std::vector<std::size_t> sortedIds;
  std::size_t len = this->paired.size();
  for (std::size_t i = 0; i < len; ++i) {
    BasePair currentPair;
    currentPair.first = this->paired[i].second.second;
    currentPair.second = this->paired[i].first;
    currentLargeChain.push_back(currentPair);
  }
  BasePairVector sortedLargePair = recursiveSortLarge(currentLargeChain);
  std::size_t sortedLen = sortedLargePair.size();
  for (std::size_t j = 0; j < sortedLen; ++j) {
    sortedIds.push_back(sortedLargePair[j].second);
  }
  return sortedIds;
}

PmergeMe::BasePairVector
PmergeMe::recursiveSortLarge(PmergeMe::BasePairVector currentLargeChain,
                             std::size_t depth) {
  bool hasUnpaired = false;
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
    BasePair left = currentLargeChain[i];
    BasePair right = currentLargeChain[i + 1];
    // TODO: compare each pair and decide small / large
    // TODO: increment sortCount for each value comparison
    ++this->sortCount;
    if (left.first <= right.first) {
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
  if (i < len) {
    currentUnpaired = currentLargeChain[i];
    hasUnpaired = true;
  }

  // TODO: build nextLargeChain from each pair's large side
  std::size_t largeSide = len / 2;
  for (std::size_t j = 0; j < largeSide; ++j) {
    nextLargeChain.push_back(currentPairs[j].second);
  }

  // TODO: recursively sort nextLargeChain
  sortedLargeChain = PmergeMe::recursiveSortLarge(nextLargeChain, depth + 1);

  // TODO: verify recursive return / restore current level state
  debugPrintRecursiveState(depth, currentLargeChain, currentPairs, hasUnpaired,
                           currentUnpaired, nextLargeChain, sortedLargeChain);
  return sortedLargeChain;
  // TODO: later: rebuild Main / Pend and insert
}
