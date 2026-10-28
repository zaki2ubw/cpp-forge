#pragma once

#include <cstddef>
#include <deque>
#include <utility>
#include <vector>

/**
 * Ford-Johnson (merge-insertion) sort on std::vector.
 *
 * Ford-Johnson roles (Main, Pend, partner, Jacobsthal insertion order) are
 * documented in DequeFordJohnson.cpp next to each definition.
 */
class DequeFordJohnson {
public:
  DequeFordJohnson();
  DequeFordJohnson(const std::deque<int> &origin);
  DequeFordJohnson(const DequeFordJohnson &src);
  DequeFordJohnson &operator=(const DequeFordJohnson &src);
  ~DequeFordJohnson();

  /** @brief Entry point: returns a sorted copy of the input. */
  std::deque<int>
  mergeInsertionSort(const std::vector<std::size_t> &jacobVector);

  std::size_t getSortCount() const;

private:
  /**
   * InputPair         : (pair id, (small, large)) built from the int input
   * InputPairDeque   : std::deque<InputPair>
   * BasePair          : (value, id)
   *                     id is the index of the top-level pair in `paired`
   *                     (assigned in makePair) and travels unchanged through
   *                     every recursion level
   * ComparePair       : (small BasePair, large BasePair)
   * BasePairDeque    : std::deque<BasePair>
   * ComparePairDeque : std::deque<ComparePair>
   * B
   */
  typedef std::pair<std::size_t, std::pair<int, int>> InputPair;
  typedef std::deque<InputPair> InputPairDeque;
  typedef std::pair<int, std::size_t> BasePair;
  typedef std::pair<BasePair, BasePair> ComparePair;
  typedef std::deque<BasePair> BasePairDeque;
  typedef std::deque<ComparePair> ComparePairDeque;

  // Top-level orchestration
  /** @brief Top-level pairing of the int input into `paired`. */
  void makePair();

  /** @brief Sorts the large elements recursively; returns pair ids in
   *         the resulting order. */
  std::vector<std::size_t>
  sortLargeChain(const std::vector<std::size_t> &jacobVector);

  /** @brief Reorders `paired` to follow the sorted pair ids. */
  InputPairDeque
  reorderTopLevelPairs(const std::vector<std::size_t> &sortedIds) const;

  /** @brief Converts sorted top-level pairs into ComparePairs with
   *         distinct small/large ids. */
  ComparePairDeque buildTopLevelPairs(const InputPairDeque &sortedPairs) const;

  /** @brief Extracts the values of the finished main chain. */
  std::deque<int> extractValues(const BasePairDeque &mainChain) const;

  // Recursive Ford-Johnson core
  /** @brief One level of the Ford-Johnson recursion. */
  BasePairDeque recursiveSortLarge(BasePairDeque currentLargeChain,
                                   const std::vector<std::size_t> &jacobVector);

  /** @brief Pairs adjacent BasePairs into (small, large) ComparePairs;
   *         reports a leftover element when the chain length is odd. */
  void makeRecursivePairs(const BasePairDeque &currentLargeChain,
                          ComparePairDeque &currentPairs, bool &hasUnpaired,
                          BasePair &currentUnpaired);

  /** @brief Extracts the large element of each ComparePair. */
  BasePairDeque buildLargeChain(const ComparePairDeque &currentPairs) const;

  /** @brief Reorders currentPairs to follow the sorted large chain. */
  ComparePairDeque reorderPairs(const ComparePairDeque &currentPairs,
                                const BasePairDeque &sortedLargeChain) const;

  /** @brief Splits sorted pairs into Main (b_1, a_1..a_k) and Pend. */
  void buildMainAndPend(const ComparePairDeque &sortedCurrentPairs,
                        BasePairDeque &mainChain,
                        ComparePairDeque &pendPairs) const;

  // Insertion helpers
  /** @brief Inserts every pending element (and the leftover, if any) into
   *         mainChain in Jacobsthal order. */
  void insertPending(BasePairDeque &mainChain,
                     const ComparePairDeque &pendPairs, bool hasUnpaired,
                     const BasePair &unpairedTarget,
                     const std::vector<std::size_t> &jacobVector);

  /** @brief Current index in mainChain of the element with id partnerId. */
  std::size_t findPartnerIndex(const BasePairDeque &mainChain,
                               std::size_t partnerId) const;

  /** @brief Binary-inserts target into mainChain within [0, rightBound). */
  void binaryInsert(BasePairDeque &mainChain, const BasePair &target,
                    std::size_t rightBound);

  // Members
  /** before    : original input sequence, kept unmodified */
  std::deque<int> before;
  /** paired    : (pair id, (small, large)) built from `before` by makePair */
  InputPairDeque paired;
  /** unpaired  : leftover element of `before` when its size is odd */
  int unpaired;
  /** sortCount : number of element comparisons performed so far */
  std::size_t sortCount;
};
