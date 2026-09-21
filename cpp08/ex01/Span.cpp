#include <algorithm>
#include <climits>
#include <cstddef>
#include <stdexcept>
#include <vector>

#include "Span.hpp"

Span::Span(unsigned int N) : maxSize(N) {}

Span::~Span() {}

void Span::addNumber(int num) {
  if (vec.size() >= maxSize)
    throw std::runtime_error("container is already full");
  vec.push_back(num);
  return;
}

unsigned int Span::shortestSpan() {
  if (vec.size() < 2)
    throw std::runtime_error("not have enough values");
  std::vector<int> sorted(vec);
  std::sort(sorted.begin(), sorted.end());
  std::vector<int>::iterator it = sorted.begin();
  std::vector<int>::iterator it_next = it + 1;
  unsigned int shortest = UINT_MAX;
  for (; it_next != sorted.end();) {
    unsigned int diff =
        static_cast<unsigned int>(*it_next) - static_cast<unsigned int>(*it);
    if (shortest > diff)
      shortest = diff;
    ++it;
    ++it_next;
  }
  return shortest;
}

unsigned int Span::longestSpan() {
  if (vec.size() < 2)
    throw std::runtime_error("not have enough values");
  unsigned int biggest =
      static_cast<unsigned int>(*std::max_element(vec.begin(), vec.end()));
  unsigned int smallest =
      static_cast<unsigned int>(*std::min_element(vec.begin(), vec.end()));
  return biggest - smallest;
}
