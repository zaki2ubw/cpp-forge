#include <iostream>

#include "debug_util.hpp"

void PmergeMe::debugPrintPairs() const {
  std::cout << "--- Paired ---" << std::endl;

  for (std::size_t i = 0; i < paired.size(); ++i) {
    std::cout << "id: " << paired[i].first
              << " small: " << paired[i].second.first
              << " large: " << paired[i].second.second << std::endl;
  }

  std::cout << "--- Unpaired ---" << std::endl;

  if (unpaired != 0)
    std::cout << unpaired << std::endl;
  else
    std::cout << "none" << std::endl;
}

void PmergeMe::debugPrintRecursiveState(
    std::size_t depth, const BasePairVector &currentLargeChain,
    const ComparePairVector &currentPairs, bool hasUnpaired,
    const BasePair &currentUnpaired, const BasePairVector &nextLargeChain,
    const BasePairVector &sortedLargeChain) const {

  std::cout << std::endl;
  std::cout << "=== Recursive Depth " << depth << " ===" << std::endl;

  std::cout << "Input: ";
  for (std::size_t i = 0; i < currentLargeChain.size(); ++i) {
    std::cout << "(" << currentLargeChain[i].first
              << ", id:" << currentLargeChain[i].second << ")";
    if (i + 1 < currentLargeChain.size())
      std::cout << " ";
  }
  std::cout << std::endl;

  std::cout << "Pairs:" << std::endl;
  for (std::size_t i = 0; i < currentPairs.size(); ++i) {
    std::cout << "  small=(" << currentPairs[i].first.first
              << ", id:" << currentPairs[i].first.second << ") large=("
              << currentPairs[i].second.first
              << ", id:" << currentPairs[i].second.second << ")" << std::endl;
  }

  std::cout << "Unpaired: ";
  if (hasUnpaired) {
    std::cout << "(" << currentUnpaired.first
              << ", id:" << currentUnpaired.second << ")";
  } else {
    std::cout << "none";
  }
  std::cout << std::endl;

  std::cout << "Next Large: ";
  for (std::size_t i = 0; i < nextLargeChain.size(); ++i) {
    std::cout << "(" << nextLargeChain[i].first
              << ", id:" << nextLargeChain[i].second << ")";
    if (i + 1 < nextLargeChain.size())
      std::cout << " ";
  }
  std::cout << std::endl;

  std::cout << "Returned Sorted Large: ";
  for (std::size_t i = 0; i < sortedLargeChain.size(); ++i) {
    std::cout << "(" << sortedLargeChain[i].first
              << ", id:" << sortedLargeChain[i].second << ")";
    if (i + 1 < sortedLargeChain.size())
      std::cout << " ";
  }
  std::cout << std::endl;
}
