#pragma once

#include <cstddef>
#include <vector>

/**
 * Container-independent Jacobsthal helpers shared by every Ford-Johnson
 * implementation.
 */

/** @brief Jacobsthal numbers 0, 1, 1, 3, 5, 11, ... up to jacobLimit. */
std::vector<std::size_t> generateJacobsthalSequence(std::size_t jacobLimit);

/** @brief 1-based insertion order of pending elements (3 2 5 4 11 ...). */
std::vector<std::size_t>
buildJacobsthalInsertionOrder(const std::vector<std::size_t> &jacobVector,
                              std::size_t jacobLimit);
