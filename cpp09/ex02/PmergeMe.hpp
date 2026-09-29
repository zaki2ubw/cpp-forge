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

  // Recursive sort helpers
  void makeRecursivePairs(const BasePairVector &currentLargeChain,
                          ComparePairVector &currentPairs, bool &hasUnpaired,
                          BasePair &currentUnpaired);

  BasePairVector buildLargeChain(const ComparePairVector &currentPairs) const;

  ComparePairVector reorderPairs(const ComparePairVector &currentPairs,
                                 const BasePairVector &sortedLargeChain) const;

  BasePairVector recursiveSortLarge(BasePairVector currentLargeChain,
                                    std::size_t depth);

  void buildMainAndPend(const ComparePairVector &sortedCurrentPairs,
                        BasePairVector &mainChain,
                        ComparePairVector &pendPairs) const;

  // debug
  void debugPrintRecursiveState(std::size_t depth,
                                const BasePairVector &currentLargeChain,
                                const ComparePairVector &currentPairs,
                                const ComparePairVector &sortedCurrentPairs,
                                const BasePairVector &mainChain,
                                const ComparePairVector &pendPairs,
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
