#pragma once

#include <iterator>
#include <stdexcept>
#include <vector>

class Span {
public:
  Span(unsigned int N);
  ~Span();
  void addNumber(int num);
  unsigned int shortestSpan();
  unsigned int longestSpan();
  template <typename Iter> void addNumber(Iter first, Iter last) {
    std::size_t range = std::distance(first, last);
    if (range + vec.size() > maxSize)
      throw std::invalid_argument("range over");
    vec.insert(vec.end(), first, last);
    return;
  }

private:
  Span();
  Span(const Span &src);
  Span &operator=(const Span &src);
  std::vector<int> vec;
  unsigned int maxSize;
};
