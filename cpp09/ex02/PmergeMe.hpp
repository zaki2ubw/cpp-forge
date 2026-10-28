#pragma once

#include <deque>
#include <sstream>
#include <vector>

/**
 * Facade over the container-specific Ford-Johnson implementations.
 * Each sort call runs a fresh VectorFordJohnson on the stored input.
 */
class PmergeMe {
public:
  PmergeMe();
  PmergeMe(const PmergeMe &src);
  PmergeMe &operator=(const PmergeMe &src);
  ~PmergeMe();

  /** @brief Returns the input sorted with the std::vector implementation. */
  void benchmark(int argc, char **argv);

private:
  template <typename Container> Container makeContainer(int argc, char **argv) {
    Container container;

    for (int i = 1; i < argc; ++i) {
      std::stringstream ss(argv[i]);
      int value;

      ss >> value;
      container.push_back(value);
    }
    return container;
  }

  template <typename Container>
  bool isSorted(const Container &container) const {
    for (std::size_t i = 1; i < container.size(); ++i) {
      if (container[i - 1] > container[i])
        return false;
    }
    return true;
  }

  double getCurrentTime() const;
  std::size_t calculateTheoreticalMax(std::size_t inputSize) const;
  void auditResults() const;

  /** before : original input sequence, kept unmodified */
  std::vector<std::size_t> jacobVector;
  std::vector<int> vectorResult;
  std::deque<int> dequeResult;
  double jacobTimeUs;
  double vectorTimeUs;
  double dequeTimeUs;
  std::size_t vectorSortCount;
  std::size_t dequeSortCount;
  std::size_t theoreticalMax;
};
