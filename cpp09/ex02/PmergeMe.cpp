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
  BasePairVector sortedLargePair = recursiveSortLarge(currentLargeChain, 0);
  std::size_t sortedLen = sortedLargePair.size();
  for (std::size_t j = 0; j < sortedLen; ++j) {
    sortedIds.push_back(sortedLargePair[j].second);
  }
  return sortedIds;
}

void PmergeMe::makeRecursivePairs(const BasePairVector &currentLargeChain,
                                  ComparePairVector &currentPairs,
                                  bool &hasUnpaired,
                                  BasePair &currentUnpaired) {
  std::size_t len = currentLargeChain.size();
  std::size_t i = 0;

  while (1) {
    if (len - i <= 1)
      break;

    ComparePair currentPair;
    BasePair left = currentLargeChain[i];
    BasePair right = currentLargeChain[i + 1];

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

  if (i < len) {
    currentUnpaired = currentLargeChain[i];
    hasUnpaired = true;
  }
}

PmergeMe::BasePairVector
PmergeMe::buildLargeChain(const ComparePairVector &currentPairs) const {
  BasePairVector nextLargeChain;

  for (std::size_t i = 0; i < currentPairs.size(); ++i) {
    nextLargeChain.push_back(currentPairs[i].second);
  }

  return nextLargeChain;
}

PmergeMe::ComparePairVector
PmergeMe::reorderPairs(const ComparePairVector &currentPairs,
                       const BasePairVector &sortedLargeChain) const {
  ComparePairVector sortedCurrentPairs;

  for (std::size_t i = 0; i < sortedLargeChain.size(); ++i) {
    std::size_t targetId = sortedLargeChain[i].second;

    for (std::size_t j = 0; j < currentPairs.size(); ++j) {
      if (currentPairs[j].second.second == targetId) {
        sortedCurrentPairs.push_back(currentPairs[j]);
        break;
      }
    }
  }

  return sortedCurrentPairs;
}

PmergeMe::BasePairVector
PmergeMe::recursiveSortLarge(PmergeMe::BasePairVector currentLargeChain,
                             std::size_t depth) {
  if (currentLargeChain.size() <= 1)
    return currentLargeChain;

  bool hasUnpaired = false;
  ComparePairVector currentPairs;
  BasePair currentUnpaired;

  makeRecursivePairs(currentLargeChain, currentPairs, hasUnpaired,
                     currentUnpaired);

  BasePairVector nextLargeChain = buildLargeChain(currentPairs);

  BasePairVector sortedLargeChain =
      recursiveSortLarge(nextLargeChain, depth + 1);

  ComparePairVector sortedCurrentPairs =
      reorderPairs(currentPairs, sortedLargeChain);

  debugPrintRecursiveState(depth, currentLargeChain, currentPairs,
                           sortedCurrentPairs, hasUnpaired, currentUnpaired,
                           nextLargeChain, sortedLargeChain);

  return sortedLargeChain;

  // TODO: later: rebuild Main / Pend and insert
}

void PmergeMe::buildMainAndPend(const ComparePairVector &sortedCurrentPairs,
                                BasePairVector &mainChain,
                                ComparePairVector &pendPairs) const {
  mainChain.push_back(sortedCurrentPairs[0].first);
  mainChain.push_back(sortedCurrentPairs[0].second);
  for (std::size_t i = 1; i < sortedCurrentPairs.size(); ++i) {
    mainChain.push_back(sortedCurrentPairs[i].second);
    pendPairs.push_back(sortedCurrentPairs[i]);
  }
  return;
}
