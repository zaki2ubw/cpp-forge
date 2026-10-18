#include <cstddef>
#include <stdexcept>
#include <utility>
#include <vector>

#include "PmergeMe.hpp"

/**
 * before    : copy of the original input sequence
 * unpaired  : leftover element when the input size is odd (set in makePair)
 * sortCount : number of element comparisons performed so far
 */
PmergeMe::PmergeMe(const std::vector<int> &origin)
    : before(origin), unpaired(0), sortCount(0) {}

/** Nothing to release; all members are self-managed containers. */
PmergeMe::~PmergeMe() {}

/**
 * Top-level pairing step of Ford-Johnson on the raw int input.
 *
 * before       : original input sequence
 * paired       : output, vector of (pair id, (small, large))
 * id           : sequential pair id, equal to the index in `paired`
 * i            : read position in `before`, advanced by 2 per pair
 * left / right : adjacent elements before[i], before[i + 1]
 * current_val  : (small, large) of the current pair, one comparison each
 * current_pair : (id, current_val) pushed into `paired`
 * unpaired     : leftover element when the input size is odd
 * sortCount    : incremented once per comparison
 */
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

/**
 * Entry point of the recursive sort of the larger elements.
 *
 * currentLargeChain : initial large chain, one BasePair per entry of
 *                     `paired`: (large value, pair id)
 * jacobVector       : Jacobsthal numbers generated up to (n + 1) / 2,
 *                     n = before.size()
 * order3/5/10       : debug only, insertion orders for small limits
 * sortedLargePair   : large chain as returned by recursiveSortLarge
 * sortedIds         : pair ids extracted from sortedLargePair (return value)
 */
std::vector<std::size_t> PmergeMe::sortLargeChain() {
  BasePairVector currentLargeChain;
  std::vector<std::size_t> sortedIds;
  std::vector<std::size_t> jacobVector =
      generateJacobVector((before.size() + 1) / 2);
  // debug
  std::vector<std::size_t> order3 = buildInsertionOrder(jacobVector, 3);
  std::vector<std::size_t> order5 = buildInsertionOrder(jacobVector, 5);
  std::vector<std::size_t> order10 = buildInsertionOrder(jacobVector, 10);

  debugPrintInsertionOrder(3, order3);
  debugPrintInsertionOrder(5, order5);
  debugPrintInsertionOrder(10, order10);
  // debug end

  std::size_t len = this->paired.size();
  for (std::size_t i = 0; i < len; ++i) {
    BasePair currentPair;
    currentPair.first = this->paired[i].second.second;
    currentPair.second = this->paired[i].first;
    currentLargeChain.push_back(currentPair);
  }
  BasePairVector sortedLargePair =
      recursiveSortLarge(currentLargeChain, jacobVector, 0);
  std::size_t sortedLen = sortedLargePair.size();
  for (std::size_t j = 0; j < sortedLen; ++j) {
    sortedIds.push_back(sortedLargePair[j].second);
  }
  return sortedIds;
}

/**
 * Pairing step at one recursion level, on BasePairs instead of ints.
 *
 * currentLargeChain : BasePairs to be paired at this level
 * currentPairs      : output, one ComparePair (small, large) per adjacent
 *                     pair, ordered by value (.first), one comparison each
 * left / right      : adjacent BasePairs currentLargeChain[i], [i + 1]
 * hasUnpaired       : set to true when the chain length is odd
 * currentUnpaired   : the leftover BasePair when hasUnpaired is true
 * sortCount         : incremented once per comparison
 */
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

/**
 * nextLargeChain : the large BasePair (.second) of each ComparePair, in the
 *                  order of currentPairs; input chain of the next recursion
 *                  level
 */
PmergeMe::BasePairVector
PmergeMe::buildLargeChain(const ComparePairVector &currentPairs) const {
  BasePairVector nextLargeChain;

  for (std::size_t i = 0; i < currentPairs.size(); ++i) {
    nextLargeChain.push_back(currentPairs[i].second);
  }

  return nextLargeChain;
}

/**
 * Restores the pair structure after the recursive call sorted the large
 * elements.
 *
 * currentPairs       : unsorted ComparePairs of this level
 * sortedLargeChain   : large BasePairs in sorted order (result of recursion)
 * targetId           : original id of the current sorted large element
 * sortedCurrentPairs : currentPairs reordered to follow sortedLargeChain;
 *                      matched via the id of the large element
 *                      (currentPairs[j].second.second == targetId)
 */
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

/**
 * One level of the Ford-Johnson recursion.
 *
 * currentLargeChain  : chain to sort at this level (copied by value)
 * jacobVector        : shared Jacobsthal numbers, passed down unchanged
 * depth              : recursion depth, 0 at the top level (debug output)
 * currentPairs       : (small, large) ComparePairs made from currentLargeChain
 * hasUnpaired /
 * currentUnpaired    : leftover BasePair when the chain length is odd
 * nextLargeChain     : large elements only, input of the recursive call
 * sortedLargeChain   : result of the recursive call on nextLargeChain
 * sortedCurrentPairs : currentPairs reordered to match sortedLargeChain
 * mainChain          : b_1, a_1, a_2, ..., a_k (see buildMainAndPend)
 * pendPairs          : ComparePairs whose small element b_i is still
 *                      pending insertion into mainChain
 *
 * Note: insertion of pendPairs / currentUnpaired is not implemented yet
 * (see the TODO at the end). mainChain is returned only when there is
 * nothing left to insert; otherwise sortedLargeChain is returned.
 */
PmergeMe::BasePairVector
PmergeMe::recursiveSortLarge(PmergeMe::BasePairVector currentLargeChain,
                             const std::vector<std::size_t> &jacobVector,
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
      recursiveSortLarge(nextLargeChain, jacobVector, depth + 1);

  ComparePairVector sortedCurrentPairs =
      reorderPairs(currentPairs, sortedLargeChain);

  BasePairVector mainChain;
  ComparePairVector pendPairs;

  buildMainAndPend(sortedCurrentPairs, mainChain, pendPairs);

  debugPrintRecursiveState(depth, currentLargeChain, currentPairs,
                           sortedCurrentPairs, mainChain, pendPairs,
                           hasUnpaired, currentUnpaired, nextLargeChain,
                           sortedLargeChain);
  std::size_t jacobLimit = currentPairs.size();
  if (hasUnpaired)
    jacobLimit += 1;
  std::vector<std::size_t> insertionOrder =
      buildInsertionOrder(jacobVector, jacobLimit);
  for (std::size_t i = 0; i < insertionOrder.size(); ++i) {
    BasePair target;
    std::size_t rightBound;
    if (hasUnpaired && insertionOrder[i] == currentPairs.size() + 1) {
      target = currentUnpaired;
      rightBound = mainChain.size();
    } else {
      std::size_t pendIndex = insertionOrder[i] - 2;
      target = pendPairs[pendIndex].first;
      BasePair partner = pendPairs[pendIndex].second;
      rightBound = findPartnerIndex(mainChain, partner.second);
    }
    binaryInsert(mainChain, target, rightBound);
  }
  return mainChain;
}

/**
 * Splits the sorted pairs into Main and Pend. Ford-Johnson notation:
 * a_i = large element, b_i = small element of the i-th sorted pair.
 *
 * sortedCurrentPairs : ComparePairs ordered by their large element
 * mainChain          : b_1, a_1, a_2, ..., a_k
 *                      (b_1 needs no comparison since b_1 <= a_1)
 * pendPairs          : sortedCurrentPairs[1 .. k-1]; the whole ComparePair
 *                      is kept so that each pending b_i (.first) still knows
 *                      its partner a_i (.second)
 */
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

/**
 * jacobVector  : Jacobsthal numbers J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2):
 *                0, 1, 1, 3, 5, 11, 21, ...
 * jacobLimit   : generation stops once a term >= jacobLimit is appended
 *                (that term is included)
 * currentJacob : the term being computed
 */
std::vector<std::size_t>
PmergeMe::generateJacobVector(std::size_t jacobLimit) const {
  std::vector<std::size_t> jacobVector;
  jacobVector.push_back(0);
  jacobVector.push_back(1);
  std::size_t i = 2;
  while (1) {
    std::size_t currentJacob = jacobVector[i - 1] + 2 * jacobVector[i - 2];
    jacobVector.push_back(currentJacob);
    if (currentJacob >= jacobLimit)
      break;
    ++i;
  }
  return jacobVector;
}

/**
 * Builds the Ford-Johnson insertion order as 1-based indices: for each
 * Jacobsthal boundary J, emit J, J-1, ..., previousBoundary + 1.
 * Index 1 is never emitted (previousBoundary starts at 1).
 * Example, jacobLimit = 10: 3 2 5 4 10 9 8 7 6
 *
 * jacobVector      : Jacobsthal numbers; iteration starts at index 3 (J=3)
 * jacobLimit       : inclusive upper bound of the emitted indices; a
 *                    boundary beyond it is clamped to jacobLimit and ends
 *                    the sequence
 * previousBoundary : last boundary already emitted (exclusive lower bound)
 * currentBoundary  : current Jacobsthal number, clamped to jacobLimit
 * boundaryNumber   : countdown index from currentBoundary down to
 *                    previousBoundary + 1
 * insertionOrder   : resulting sequence of indices (return value)
 */
std::vector<std::size_t>
PmergeMe::buildInsertionOrder(const std::vector<std::size_t> &jacobVector,
                              std::size_t jacobLimit) const {
  std::vector<std::size_t> insertionOrder;
  std::size_t previousBoundary = 1;
  for (std::size_t i = 3; i < jacobVector.size(); ++i) {
    std::size_t currentBoundary = jacobVector[i];
    if (currentBoundary >= jacobLimit)
      currentBoundary = jacobLimit;
    std::size_t boundaryNumber = currentBoundary;
    while (boundaryNumber > previousBoundary) {
      insertionOrder.push_back(boundaryNumber);
      --boundaryNumber;
    }
    if (currentBoundary == jacobLimit)
      break;
    previousBoundary = currentBoundary;
  }
  return insertionOrder;
}

/**
 * Binary insertion of one pending element into the main chain.
 *
 * mainChain    : currently constructed sorted main chain
 * target       : b_i to insert into the main chain
 * rightBound   : exclusive upper bound of the search range [0, rightBound);
 *                intended to be the current index of target's partner a_i
 * left / right : current search range; `left` ends as the insertion index
 * mid          : probe index; `<=` places target after equal values
 * sortCount    : incremented once per comparison
 */
void PmergeMe::binaryInsert(BasePairVector &mainChain, const BasePair &target,
                            std::size_t rightBound) {
  std::size_t left = 0;
  std::size_t right = rightBound;
  std::size_t mid;
  while (left < right) {
    mid = left + ((right - left) / 2);
    if (mainChain[mid].first <= target.first)
      left = mid + 1;
    else
      right = mid;
    ++sortCount;
  }
  mainChain.insert(mainChain.begin() + left, target);
  return;
}

/**
 * mainChain : currently constructed sorted main chain
 * partnerId : original id of target's partner a_i
 *
 * return     : current index of the partner in mainChain
 */
std::size_t PmergeMe::findPartnerIndex(const BasePairVector &mainChain,
                                       std::size_t partnerId) const {

  for (std::size_t i = 0; i < mainChain.size(); ++i) {
    if (mainChain[i].second == partnerId)
      return i;
  }
  throw std::runtime_error("Unfortunately, pair was not found.");
}

/**
 * sortedIds : top-level pair ids ordered by ascending large value
 * reordered : input pairs reordered to follow sortedIds
 *
 * return    : input pairs in sorted-large order
 */
PmergeMe::InputPairVector PmergeMe::reorderTopLevelPairs(
    const std::vector<std::size_t> &sortedIds) const {
  PmergeMe::InputPairVector reordered;
  for (std::size_t i = 0; i < sortedIds.size(); ++i) {
    for (std::size_t j = 0; j < paired.size(); ++j) {
      if (sortedIds[i] == paired[j].first) {
        reordered.push_back(paired[j]);
        break;
      }
    }
  }
  return reordered;
}
