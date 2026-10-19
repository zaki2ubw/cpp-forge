#include <cstddef>
#include <vector>

#include "Jacobsthal.hpp"

/**
 * Jacobsthal numbers J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2):
 * 0, 1, 1, 3, 5, 11, 21, ...
 *
 * @param jacobLimit generation stops once a term >= jacobLimit is appended
 *                   (that term is included)
 */
std::vector<std::size_t>
generateJacobsthalSequence(std::size_t jacobLimit) {
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
buildJacobsthalInsertionOrder(const std::vector<std::size_t> &jacobVector,
                              std::size_t jacobLimit) {
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
