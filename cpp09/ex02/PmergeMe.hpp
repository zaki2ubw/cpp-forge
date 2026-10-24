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
  void benchmark(int argc, char **argv);

private:
  template <typename Container> Container makeContainer(int argc, char **argv);

  /** before : original input sequence, kept unmodified */
  std::vector<std::size_t> jacobVector;
  std::vector<int> vectorResult;
  std::vector<int> dequeResult;
  double jacobTimeUs;
  double vectorTimeUs;
  double dequeTimeUs;
  std::size_t vectorSortCount;
  std::size_t dequeSortCount;
  std::size_t theoreticalMax;
};
