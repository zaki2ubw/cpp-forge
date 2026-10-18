#include <cstddef>
#include <stdexcept>
#include <utility>
#include <vector>

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::vector<int> &origin)
    : before(origin), unpaired(0), sortCount(0) {}

PmergeMe::~PmergeMe() {}

/**
 * Ford-Johnson merge-insertion sort of `before`.
 *
 * Pairs the input, sorts the large elements recursively, then splits the
 * sorted top-level pairs into Main and Pend and inserts every pending small
 * element (and the leftover, if any) in Jacobsthal order, each bounded by
 * the current position of its partner.
 *
 * At the top level the small element of pair id p is given the id
 * p + paired.size() + 1 and the leftover the id paired.size(), so that no
 * element in the main chain shares an id with a large element.
 *
 * @return sorted copy of `before`
 */
std::vector<int> PmergeMe::mergeInsertionSort() {
  if (before.size() <= 1)
    return before;
  makePair();
  std::vector<std::size_t> jacobVector =
      generateJacobVector((before.size() + 1) / 2);
  std::vector<std::size_t> sortedIds = sortLargeChain(jacobVector);
  InputPairVector sortedPairs = reorderTopLevelPairs(sortedIds);
  bool hasUnpaired = (before.size() % 2 != 0);
  ComparePairVector topLevelPairs;
  for (std::size_t i = 0; i < sortedIds.size(); ++i) {
    ComparePair currentPair;
    currentPair.first.first = sortedPairs[i].second.first;
    currentPair.first.second = sortedPairs[i].first + paired.size() + 1;
    currentPair.second.first = sortedPairs[i].second.second;
    currentPair.second.second = sortedPairs[i].first;
    topLevelPairs.push_back(currentPair);
  }
  BasePairVector mainChain;
  ComparePairVector pendPairs;
  buildMainAndPend(topLevelPairs, mainChain, pendPairs);
  std::size_t jacobLimit = topLevelPairs.size();
  BasePair unpairedTarget;
  if (hasUnpaired) {
    unpairedTarget.first = unpaired;
    unpairedTarget.second = paired.size();
    ++jacobLimit;
  }
  std::vector<std::size_t> insertionOrder =
      buildInsertionOrder(jacobVector, jacobLimit);
  for (std::size_t i = 0; i < insertionOrder.size(); ++i) {
    BasePair target;
    std::size_t rightBound;
    if (hasUnpaired && insertionOrder[i] == topLevelPairs.size() + 1) {
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
  std::vector<int> sorted;
  for (std::size_t i = 0; i < mainChain.size(); ++i) {
    sorted.push_back(mainChain[i].first);
  }
  return sorted;
}

/**
 * Top-level pairing of `before` into `paired`.
 *
 * Each entry is (id, (small, large)); the id equals the index in `paired`
 * and identifies the pair through every recursion level. When the input
 * size is odd the last element is stored in `unpaired`. One comparison per
 * pair is counted in sortCount.
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

/**
 * Sorts the large elements of `paired` with the recursive Ford-Johnson core.
 *
 * @param jacobVector Jacobsthal numbers shared by all recursion levels
 * @return top-level pair ids ordered by ascending large value
 */
std::vector<std::size_t>
PmergeMe::sortLargeChain(const std::vector<std::size_t> &jacobVector) {
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

/**
 * One level of the Ford-Johnson recursion.
 *
 * Pairs the chain, recurses on the large elements, restores the pair
 * structure in sorted order, then splits it into Main and Pend and inserts
 * every pending element (and the leftover, if any) in Jacobsthal order.
 * Each pending b_i is binary-inserted into [0, index of its partner a_i);
 * the leftover is inserted into the whole main chain.
 *
 * @param currentLargeChain chain to sort at this level (taken by value)
 * @param jacobVector       Jacobsthal numbers shared by all recursion levels
 * @return the chain fully sorted
 */
PmergeMe::BasePairVector
PmergeMe::recursiveSortLarge(PmergeMe::BasePairVector currentLargeChain,
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
 * Pairing step of one recursion level, on BasePairs.
 *
 * @param currentLargeChain chain to pair
 * @param currentPairs      output, one (small, large) ComparePair per two
 *                          adjacent elements, one counted comparison each
 * @param hasUnpaired       set to true when the chain length is odd
 * @param currentUnpaired   the leftover element when hasUnpaired is true
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
 * @param currentPairs ComparePairs of this level
 * @return the large element of each pair, in the same order; this is the
 *         input of the next recursion level
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
 * elements. Pairs are matched by the id of their large element.
 *
 * @param currentPairs     unsorted ComparePairs of this level
 * @param sortedLargeChain large elements in sorted order
 * @return currentPairs reordered to follow sortedLargeChain
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
 * Jacobsthal numbers J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2):
 * 0, 1, 1, 3, 5, 11, 21, ...
 *
 * @param jacobLimit generation stops once a term >= jacobLimit is appended
 *                   (that term is included)
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
 * Ford-Johnson insertion order as 1-based indices: for each Jacobsthal
 * boundary J, emit J, J-1, ..., previous boundary + 1. Index 1 is never
 * emitted since b_1 is already in Main.
 * Example, jacobLimit = 10: 3 2 5 4 10 9 8 7 6
 *
 * @param jacobVector Jacobsthal numbers; iteration starts at J(3) = 3
 * @param jacobLimit  inclusive upper bound of the emitted indices; a
 *                    boundary beyond it is clamped to jacobLimit and ends
 *                    the sequence
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
 * @param mainChain main chain under construction
 * @param partnerId id of the pending element's partner a_i
 * @return current index of the partner in mainChain
 * @throws std::runtime_error when the partner is not present
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
 * Binary insertion of one element into the main chain, counting one
 * comparison per probe. Equal values are placed after existing ones.
 *
 * @param mainChain  main chain under construction
 * @param target     element to insert
 * @param rightBound exclusive upper bound of the search range
 *                   [0, rightBound): the index of target's partner a_i, or
 *                   mainChain.size() for the leftover element
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
