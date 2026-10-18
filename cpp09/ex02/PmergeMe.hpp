#pragma once

#include <cstddef>
#include <utility>
#include <vector>

// Be template later

/**
 * Ford-Johnson (merge-insertion) sort driver.
 *
 * Per-function glossaries of the Ford-Johnson roles (Main, Pend, target,
 * partner, rightBound, ...) are in PmergeMe.cpp next to each definition.
 */
class PmergeMe {
public:
  PmergeMe(const std::vector<int> &origin);
  ~PmergeMe();
  /** @brief Top-level pairing of the int input into `paired`. */
  void makePair();
  /** @brief Sorts the large elements recursively; returns pair ids in
   *         the resulting order. */
  std::vector<std::size_t>
  sortLargeChain(const std::vector<std::size_t> &jacobVector);
  void debugPrintPairs() const;
  std::vector<int> mergeInsertionSort();

private:
  // Definition
  /**
   * BasePair          : (value, original id)
   *                     id is the index of the top-level pair in `paired`
   *                     (assigned in makePair) and travels unchanged through
   *                     every recursion level
   * ComparePair       : (small BasePair, large BasePair)
   * BasePairVector    : std::vector<BasePair>
   * ComparePairVector : std::vector<ComparePair>
   */
  typedef std::pair<std::size_t, std::pair<int, int>> InputPair;
  typedef std::vector<InputPair> InputPairVector;
  typedef std::pair<int, std::size_t> BasePair;
  typedef std::pair<BasePair, BasePair> ComparePair;
  typedef std::vector<BasePair> BasePairVector;
  typedef std::vector<ComparePair> ComparePairVector;

  // Forbidden
  PmergeMe();
  PmergeMe(const PmergeMe &src);
  PmergeMe &operator=(const PmergeMe &src);

  // Recursive sort helpers
  /** @brief Pairs adjacent BasePairs into (small, large) ComparePairs;
   *         reports a leftover element when the chain length is odd. */
  void makeRecursivePairs(const BasePairVector &currentLargeChain,
                          ComparePairVector &currentPairs, bool &hasUnpaired,
                          BasePair &currentUnpaired);

  /** @brief Extracts the large element of each ComparePair. */
  BasePairVector buildLargeChain(const ComparePairVector &currentPairs) const;

  /** @brief Reorders currentPairs to follow the sorted large chain. */
  ComparePairVector reorderPairs(const ComparePairVector &currentPairs,
                                 const BasePairVector &sortedLargeChain) const;

  /** @brief One level of the Ford-Johnson recursion. */
  BasePairVector recursiveSortLarge(BasePairVector currentLargeChain,
                                    const std::vector<std::size_t> &jacobVector,
                                    std::size_t depth);

  /** @brief Splits sorted pairs into Main (b_1, a_1..a_k) and Pend. */
  void buildMainAndPend(const ComparePairVector &sortedCurrentPairs,
                        BasePairVector &mainChain,
                        ComparePairVector &pendPairs) const;

  /** @brief Jacobsthal numbers 0, 1, 1, 3, 5, 11, ... up to jacobLimit. */
  std::vector<std::size_t> generateJacobVector(std::size_t jacobLimit) const;

  /** @brief 1-based insertion order of pending elements (3 2 5 4 11 ...). */
  std::vector<std::size_t>
  buildInsertionOrder(const std::vector<std::size_t> &jacobVector,
                      std::size_t jacobLimit) const;

  /** @brief Binary-inserts target into mainChain within [0, rightBound). */
  void binaryInsert(BasePairVector &mainChain, const BasePair &target,
                    std::size_t rightBound);

  std::size_t findPartnerIndex(const BasePairVector &mainChain,
                               std::size_t partnerId) const;

  InputPairVector
  reorderTopLevelPairs(const std::vector<std::size_t> &sortedIds) const;

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

  void debugPrintInsertionOrder(
      std::size_t jacobLimit,
      const std::vector<std::size_t> &insertionOrder) const;

  // member
  /** before    : original input sequence, kept unmodified */
  std::vector<int> before;
  /** paired    : (pair id, (small, large)) built from `before` by makePair */
  InputPairVector paired;
  /** unpaired  : leftover element of `before` when its size is odd */
  int unpaired;
  /** sortCount : number of element comparisons performed so far */
  std::size_t sortCount;
};
