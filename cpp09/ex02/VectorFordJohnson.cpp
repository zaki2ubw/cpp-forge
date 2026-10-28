#include <cstddef>
#include <stdexcept>
#include <utility>
#include <vector>

#include "Jacobsthal.hpp"
#include "VectorFordJohnson.hpp"

VectorFordJohnson::VectorFordJohnson() : unpaired(0), sortCount(0) {}

VectorFordJohnson::VectorFordJohnson(const std::vector<int> &origin)
    : before(origin), unpaired(0), sortCount(0) {}

VectorFordJohnson::VectorFordJohnson(const VectorFordJohnson &src)
    : before(src.before), paired(src.paired), unpaired(src.unpaired),
      sortCount(src.sortCount) {}

VectorFordJohnson &VectorFordJohnson::operator=(const VectorFordJohnson &src) {
  if (this != &src) {
    before = src.before;
    paired = src.paired;
    unpaired = src.unpaired;
    sortCount = src.sortCount;
  }
  return *this;
}

VectorFordJohnson::~VectorFordJohnson() {}

/**
 * Ford-Johnson merge-insertion sort of `before`.
 *
 * Pairs the input, sorts the large elements recursively, then splits the
 * sorted top-level pairs into Main and Pend and inserts every pending small
 * element (and the leftover, if any) in Jacobsthal order, each bounded by
 * the current position of its partner. Working state is reset first so
 * that repeated calls on the same instance behave identically.
 *
 * @return sorted copy of `before`
 */
std::vector<int> VectorFordJohnson::mergeInsertionSort(
    const std::vector<std::size_t> &jacobVector) {
  paired.clear();
  unpaired = 0;
  sortCount = 0;
  if (before.size() <= 1)
    return before;
  makePair();
  std::vector<std::size_t> sortedIds = sortLargeChain(jacobVector);
  ComparePairVector topLevelPairs =
      buildTopLevelPairs(reorderTopLevelPairs(sortedIds));
  BasePairVector mainChain;
  ComparePairVector pendPairs;
  buildMainAndPend(topLevelPairs, mainChain, pendPairs);
  bool hasUnpaired = (before.size() % 2 != 0);
  BasePair unpairedTarget;
  if (hasUnpaired) {
    unpairedTarget.first = unpaired;
    unpairedTarget.second = paired.size();
  }
  insertPending(mainChain, pendPairs, hasUnpaired, unpairedTarget, jacobVector);
  return extractValues(mainChain);
}

std::size_t VectorFordJohnson::getSortCount() const { return sortCount; }

/**
 * Top-level pairing of `before` into `paired`.
 *
 * Each entry is (id, (small, large)); the id equals the index in `paired`
 * and identifies the pair through every recursion level. When the input
 * size is odd the last element is stored in `unpaired`. One comparison per
 * pair is counted in sortCount.
 */
void VectorFordJohnson::makePair() {
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
 * Sorts the large elements of `paired` with the recursive Ford-Johnson core.
 *
 * @param jacobVector Jacobsthal numbers shared by all recursion levels
 * @return top-level pair ids ordered by ascending large value
 */
std::vector<std::size_t>
VectorFordJohnson::sortLargeChain(const std::vector<std::size_t> &jacobVector) {
  BasePairVector currentLargeChain;
  std::vector<std::size_t> sortedIds;

  std::size_t len = this->paired.size();
  for (std::size_t i = 0; i < len; ++i) {
    BasePair currentPair;
    currentPair.first = this->paired[i].second.second;
    currentPair.second = this->paired[i].first;
    currentLargeChain.push_back(currentPair);
  }
  BasePairVector sortedLargePair =
      recursiveSortLarge(currentLargeChain, jacobVector);
  std::size_t sortedLen = sortedLargePair.size();
  for (std::size_t j = 0; j < sortedLen; ++j) {
    sortedIds.push_back(sortedLargePair[j].second);
  }
  return sortedIds;
}

/**
 * @param sortedIds top-level pair ids ordered by ascending large value
 * @return entries of `paired` reordered to follow sortedIds
 */
VectorFordJohnson::InputPairVector VectorFordJohnson::reorderTopLevelPairs(
    const std::vector<std::size_t> &sortedIds) const {
  InputPairVector reordered;
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

/**
 * The small element of pair id p is given the id p + paired.size() + 1 and
 * the leftover the id paired.size(), so that no element in the main chain
 * shares an id with a large element.
 *
 * @param sortedPairs top-level pairs ordered by ascending large value
 * @return the same pairs as (small BasePair, large BasePair)
 */
VectorFordJohnson::ComparePairVector VectorFordJohnson::buildTopLevelPairs(
    const InputPairVector &sortedPairs) const {
  ComparePairVector topLevelPairs;
  for (std::size_t i = 0; i < sortedPairs.size(); ++i) {
    ComparePair currentPair;
    currentPair.first.first = sortedPairs[i].second.first;
    currentPair.first.second = sortedPairs[i].first + paired.size() + 1;
    currentPair.second.first = sortedPairs[i].second.second;
    currentPair.second.second = sortedPairs[i].first;
    topLevelPairs.push_back(currentPair);
  }
  return topLevelPairs;
}

/**
 * @param mainChain finished main chain
 * @return its values in order
 */
std::vector<int>
VectorFordJohnson::extractValues(const BasePairVector &mainChain) const {
  std::vector<int> sorted;
  for (std::size_t i = 0; i < mainChain.size(); ++i) {
    sorted.push_back(mainChain[i].first);
  }
  return sorted;
}

/**
 * One level of the Ford-Johnson recursion.
 *
 * Pairs the chain, recurses on the large elements, restores the pair
 * structure in sorted order, then splits it into Main and Pend and inserts
 * every pending element (and the leftover, if any) in Jacobsthal order.
 *
 * @param currentLargeChain chain to sort at this level (taken by value)
 * @param jacobVector       Jacobsthal numbers shared by all recursion levels
 * @return the chain fully sorted
 */
VectorFordJohnson::BasePairVector VectorFordJohnson::recursiveSortLarge(
    BasePairVector currentLargeChain,
    const std::vector<std::size_t> &jacobVector) {
  if (currentLargeChain.size() <= 1)
    return currentLargeChain;

  bool hasUnpaired = false;
  ComparePairVector currentPairs;
  BasePair currentUnpaired;

  makeRecursivePairs(currentLargeChain, currentPairs, hasUnpaired,
                     currentUnpaired);

  BasePairVector nextLargeChain = buildLargeChain(currentPairs);

  BasePairVector sortedLargeChain =
      recursiveSortLarge(nextLargeChain, jacobVector);

  ComparePairVector sortedCurrentPairs =
      reorderPairs(currentPairs, sortedLargeChain);

  BasePairVector mainChain;
  ComparePairVector pendPairs;

  buildMainAndPend(sortedCurrentPairs, mainChain, pendPairs);

  insertPending(mainChain, pendPairs, hasUnpaired, currentUnpaired,
                jacobVector);
  return mainChain;
}

/**
 * Pairing step of one recursion level, on BasePairs.
 *
 * @param currentLargeChain chain to pair
 * @param currentPairs      output, one (small, large) ComparePair per two
 *                          adjacent elements, one counted comparison each
 * @param hasUnpaired       set to true when the chain length is odd
 * @param currentUnpaired   the leftover element when hasUnpaired is true
 */
void VectorFordJohnson::makeRecursivePairs(
    const BasePairVector &currentLargeChain, ComparePairVector &currentPairs,
    bool &hasUnpaired, BasePair &currentUnpaired) {
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
 * @param currentPairs ComparePairs of this level
 * @return the large element of each pair, in the same order; this is the
 *         input of the next recursion level
 */
VectorFordJohnson::BasePairVector VectorFordJohnson::buildLargeChain(
    const ComparePairVector &currentPairs) const {
  BasePairVector nextLargeChain;

  for (std::size_t i = 0; i < currentPairs.size(); ++i) {
    nextLargeChain.push_back(currentPairs[i].second);
  }

  return nextLargeChain;
}

/**
 * Restores the pair structure after the recursive call sorted the large
 * elements. Pairs are matched by the id of their large element.
 *
 * @param currentPairs     unsorted ComparePairs of this level
 * @param sortedLargeChain large elements in sorted order
 * @return currentPairs reordered to follow sortedLargeChain
 */
VectorFordJohnson::ComparePairVector
VectorFordJohnson::reorderPairs(const ComparePairVector &currentPairs,
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
 * Splits the sorted pairs into Main and Pend. Ford-Johnson notation:
 * a_i = large element, b_i = small element of the i-th sorted pair.
 *
 * @param sortedCurrentPairs ComparePairs ordered by their large element
 * @param mainChain          output: b_1, a_1, a_2, ..., a_k
 *                           (b_1 needs no comparison since b_1 <= a_1)
 * @param pendPairs          output: sortedCurrentPairs[1 .. k-1]; the whole
 *                           ComparePair is kept so that each pending b_i
 *                           still knows its partner a_i
 */
void VectorFordJohnson::buildMainAndPend(
    const ComparePairVector &sortedCurrentPairs, BasePairVector &mainChain,
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
 * Inserts the pending elements in Jacobsthal order. Each pending b_i is
 * binary-inserted into [0, index of its partner a_i); the leftover is
 * inserted into the whole main chain. The 1-based insertion index of the
 * leftover is (number of pairs) + 1.
 *
 * @param mainChain      main chain under construction
 * @param pendPairs      pending pairs; pendPairs.size() + 1 pairs exist
 * @param hasUnpaired    whether a leftover element exists at this level
 * @param unpairedTarget the leftover element when hasUnpaired is true
 * @param jacobVector    Jacobsthal numbers shared by all recursion levels
 */
void VectorFordJohnson::insertPending(
    BasePairVector &mainChain, const ComparePairVector &pendPairs,
    bool hasUnpaired, const BasePair &unpairedTarget,
    const std::vector<std::size_t> &jacobVector) {
  std::size_t pairCount = pendPairs.size() + 1;
  std::size_t jacobLimit = pairCount;
  if (hasUnpaired)
    jacobLimit += 1;
  std::vector<std::size_t> insertionOrder =
      buildJacobsthalInsertionOrder(jacobVector, jacobLimit);
  for (std::size_t i = 0; i < insertionOrder.size(); ++i) {
    BasePair target;
    std::size_t rightBound;
    if (hasUnpaired && insertionOrder[i] == pairCount + 1) {
      target = unpairedTarget;
      rightBound = mainChain.size();
    } else {
      std::size_t pendIndex = insertionOrder[i] - 2;
      target = pendPairs[pendIndex].first;
      BasePair partner = pendPairs[pendIndex].second;
      rightBound = findPartnerIndex(mainChain, partner.second);
    }
    binaryInsert(mainChain, target, rightBound);
  }
}

/**
 * @param mainChain main chain under construction
 * @param partnerId id of the pending element's partner a_i
 * @return current index of the partner in mainChain
 * @throws std::runtime_error when the partner is not present
 */
std::size_t VectorFordJohnson::findPartnerIndex(const BasePairVector &mainChain,
                                                std::size_t partnerId) const {

  for (std::size_t i = 0; i < mainChain.size(); ++i) {
    if (mainChain[i].second == partnerId)
      return i;
  }
  throw std::runtime_error("Unfortunately, pair was not found.");
}

/**
 * Binary insertion of one element into the main chain, counting one
 * comparison per probe. Equal values are placed after existing ones.
 *
 * @param mainChain  main chain under construction
 * @param target     element to insert
 * @param rightBound exclusive upper bound of the search range
 *                   [0, rightBound): the index of target's partner a_i, or
 *                   mainChain.size() for the leftover element
 */
void VectorFordJohnson::binaryInsert(BasePairVector &mainChain,
                                     const BasePair &target,
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
