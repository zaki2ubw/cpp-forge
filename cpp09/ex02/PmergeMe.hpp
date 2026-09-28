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
  //  std::vector<std::pair<int, size_t> >
  // recursiveSortLarge(std::vector<std::pair<int, size_t> > origin);
  // debug
  void debugPrintPairs() const;

private:
  // Definition
  typedef std::pair<int, std::size_t> BasePair;
  typedef std::pair<BasePair, BasePair> ComparePair;
  typedef std::vector<BasePair> BasePairVector;
  typedef std::vector<ComparePair> ComparePairVector;
  // Forbidden
  PmergeMe();
  PmergeMe(const PmergeMe &src);
  PmergeMe &operator=(const PmergeMe &src);
  // scope
  BasePairVector recursiveSortLarge(BasePairVector currentLargeChain,
                                    std::size_t depth);
  // debug
  void debugPrintRecursiveState(std::size_t depth,
                                const BasePairVector &currentLargeChain,
                                const ComparePairVector &currentPairs,
                                bool hasUnpaired,
                                const BasePair &currentUnpaired,
                                const BasePairVector &nextLargeChain,
                                const BasePairVector &sortedLargeChain) const;
  // member
  std::vector<int> before;
  std::vector<std::pair<std::size_t, std::pair<int, int> > > paired;
  int unpaired;
  std::size_t sortCount;
};
