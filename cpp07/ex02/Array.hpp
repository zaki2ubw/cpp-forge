#pragma once

#include <cstddef>

template <typename T> class Array {
public:
  // Constructor & Destructor
  Array();
  Array(unsigned int n);
  Array(const Array &src);
  ~Array();

  // Overloded operators
  Array &operator=(const Array &src);
  T &operator[](std::size_t i);
  const T &operator[](std::size_t i) const;

  // .size() method
  std::size_t size() const;

private:
  // Value
  T *tArray_;
  std::size_t length_;
};

#include "Array.tpp"
