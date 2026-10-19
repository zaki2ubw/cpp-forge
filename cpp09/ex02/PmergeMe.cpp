#include <vector>

#include "PmergeMe.hpp"
#include "VectorFordJohnson.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const std::vector<int> &origin) : before(origin) {}

PmergeMe::PmergeMe(const PmergeMe &src) : before(src.before) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
  if (this != &src)
    before = src.before;
  return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<int> PmergeMe::sortVector() const {
  VectorFordJohnson sorter(before);
  return sorter.mergeInsertionSort();
}
