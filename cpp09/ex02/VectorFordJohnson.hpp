#pragma once

#include <cstddef>
#include <utility>
#include <vector>

/**
 * Ford-Johnson (merge-insertion) sort on std::vector.
 *
 * Ford-Johnson roles (Main, Pend, partner, Jacobsthal insertion order) are
 * documented in VectorFordJohnson.cpp next to each definition.
 */
class VectorFordJohnson {
public:
  VectorFordJohnson();
  VectorFordJohnson(const std::vector<int> &origin);
  VectorFordJohnson(const VectorFordJohnson &src);
  VectorFordJohnson &operator=(const VectorFordJohnson &src);
  ~VectorFordJohnson();

  /** @brief Entry point: returns a sorted copy of the input. */
  std::vector<int>
  mergeInsertionSort(const std::vector<std::size_t> &jacobVector);

  std::size_t getSortCount() const;

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
  typedef std::pair<std::size_t, std::pair<int, int>> InputPair;
  typedef std::vector<InputPair> InputPairVector;
  typedef std::pair<int, std::size_t> BasePair;
  typedef std::pair<BasePair, BasePair> ComparePair;
  typedef std::vector<BasePair> BasePairVector;
  typedef std::vector<ComparePair> ComparePairVector;

  // Top-level orchestration
  /** @brief Top-level pairing of the int input into `paired`. */
  void makePair();

  /** @brief Sorts the large elements recursively; returns pair ids in
   *         the resulting order. */
  std::vector<std::size_t>
  sortLargeChain(const std::vector<std::size_t> &jacobVector);

  /** @brief Reorders `paired` to follow the sorted pair ids. */
  InputPairVector
  reorderTopLevelPairs(const std::vector<std::size_t> &sortedIds) const;

  /** @brief Converts sorted top-level pairs into ComparePairs with
   *         distinct small/large ids. */
  ComparePairVector
  buildTopLevelPairs(const InputPairVector &sortedPairs) const;

  /** @brief Extracts the values of the finished main chain. */
  std::vector<int> extractValues(const BasePairVector &mainChain) const;

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

  // Insertion helpers
  /** @brief Inserts every pending element (and the leftover, if any) into
   *         mainChain in Jacobsthal order. */
  void insertPending(BasePairVector &mainChain,
                     const ComparePairVector &pendPairs, bool hasUnpaired,
                     const BasePair &unpairedTarget,
                     const std::vector<std::size_t> &jacobVector);

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
