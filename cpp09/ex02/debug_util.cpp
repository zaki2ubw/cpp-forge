#include <iostream>

#include "debug_util.hpp"

void PmergeMe::debugPrintPairs() const {
  std::cout << "--- Paired ---" << std::endl;

  for (std::size_t i = 0; i < paired.size(); ++i) {
    std::cout << "id: " << paired[i].first
              << " small: " << paired[i].second.first
              << " large: " << paired[i].second.second << std::endl;
  }

  std::cout << "--- Unpaired ---" << std::endl;

  if (unpaired != 0)
    std::cout << unpaired << std::endl;
  else
    std::cout << "none" << std::endl;
}
