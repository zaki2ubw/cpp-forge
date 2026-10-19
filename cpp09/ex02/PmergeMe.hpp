#pragma once

#include <vector>

/**
 * Facade over the container-specific Ford-Johnson implementations.
 * Each sort call runs a fresh VectorFordJohnson on the stored input.
 */
class PmergeMe {
public:
  PmergeMe();
  PmergeMe(const std::vector<int> &origin);
  PmergeMe(const PmergeMe &src);
  PmergeMe &operator=(const PmergeMe &src);
  ~PmergeMe();

  /** @brief Returns the input sorted with the std::vector implementation. */
  std::vector<int> sortVector() const;

private:
  /** before : original input sequence, kept unmodified */
  std::vector<int> before;
};
