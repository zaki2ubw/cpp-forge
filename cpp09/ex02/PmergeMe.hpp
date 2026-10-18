#pragma once

#include <cstddef>
#include <utility>
#include <vector>

/**
 * Ford-Johnson (merge-insertion) sort driver.
 *
 * Ford-Johnson roles (Main, Pend, partner, Jacobsthal insertion order) are
 * documented in PmergeMe.cpp next to each definition.
 */
class PmergeMe {
public:
  PmergeMe(const std::vector<int> &origin);
  ~PmergeMe();

  /** @brief Entry point: returns a sorted copy of the input. */
  std::vector<int> mergeInsertionSort();

  /** @brief Top-level pairing of the int input into `paired`. */
  void makePair();
  /** @brief Sorts the large elements recursively; returns pair ids in
   *         the resulting order. */
  std::vector<std::size_t>
  sortLargeChain(const std::vector<std::size_t> &jacobVector);

private:
  /**
   * InputPair         : (pair id, (small, large)) built from the int input
   * InputPairVector   : std::vector<InputPair>
   * BasePair          : (value, id)
   *                     id is the index of the top-level pair in `paired`
   *                     (assigned in makePair) and travels unchanged through
   *                     every recursion level
   * ComparePair       : (small BasePair, large BasePair)
   * BasePairVector    : std::vector<BasePair>
   * ComparePairVector : std::vector<ComparePair>
   */
  typedef std::pair<std::size_t, std::pair<int, int> > InputPair;
  typedef std::vector<InputPair> InputPairVector;
  typedef std::pair<int, std::size_t> BasePair;
  typedef std::pair<BasePair, BasePair> ComparePair;
  typedef std::vector<BasePair> BasePairVector;
  typedef std::vector<ComparePair> ComparePairVector;

  // Forbidden
  PmergeMe();
  PmergeMe(const PmergeMe &src);
  PmergeMe &operator=(const PmergeMe &src);

  // Top-level orchestration
  /** @brief Reorders `paired` to follow the sorted pair ids. */
  InputPairVector
  reorderTopLevelPairs(const std::vector<std::size_t> &sortedIds) const;

  // Recursive Ford-Johnson core
  /** @brief One level of the Ford-Johnson recursion. */
  BasePairVector
  recursiveSortLarge(BasePairVector currentLargeChain,
                     const std::vector<std::size_t> &jacobVector);

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

  /** @brief Splits sorted pairs into Main (b_1, a_1..a_k) and Pend. */
  void buildMainAndPend(const ComparePairVector &sortedCurrentPairs,
                        BasePairVector &mainChain,
                        ComparePairVector &pendPairs) const;

  // Jacobsthal / insertion helpers
  /** @brief Jacobsthal numbers 0, 1, 1, 3, 5, 11, ... up to jacobLimit. */
  std::vector<std::size_t> generateJacobVector(std::size_t jacobLimit) const;

  /** @brief 1-based insertion order of pending elements (3 2 5 4 11 ...). */
  std::vector<std::size_t>
  buildInsertionOrder(const std::vector<std::size_t> &jacobVector,
                      std::size_t jacobLimit) const;

  /** @brief Current index in mainChain of the element with id partnerId. */
  std::size_t findPartnerIndex(const BasePairVector &mainChain,
                               std::size_t partnerId) const;

  /** @brief Binary-inserts target into mainChain within [0, rightBound). */
  void binaryInsert(BasePairVector &mainChain, const BasePair &target,
                    std::size_t rightBound);

  // Members
  /** before    : original input sequence, kept unmodified */
  std::vector<int> before;
  /** paired    : (pair id, (small, large)) built from `before` by makePair */
  InputPairVector paired;
  /** unpaired  : leftover element of `before` when its size is odd */
  int unpaired;
  /** sortCount : number of element comparisons performed so far */
  std::size_t sortCount;
};
