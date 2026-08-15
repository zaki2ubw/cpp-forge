#include <cstddef>
#include <stdexcept>

template <typename T> Array<T>::Array() : tArray_(NULL), length_(0) {}

template <typename T> Array<T>::Array(unsigned int n) {
  this->tArray_ = new T[n]();
  this->length_ = static_cast<std::size_t>(n);
}

template <typename T> Array<T>::Array(const Array &src) {
  T *tmp = new T[src.length_];
  try {
    for (std::size_t i = 0; i < src.length_; ++i) {
      tmp[i] = src.tArray_[i];
    }
  } catch (...) {
    delete[] tmp;
    throw;
  }
  this->tArray_ = tmp;
  this->length_ = src.length_;
}

template <typename T> Array<T>::~Array() { delete[] tArray_; }

template <typename T> Array<T> &Array<T>::operator=(const Array &src) {
  // check self assignment
  if (this == &src)
    return *this;

  // get new resources
  T *tmp = new T[src.length_];

  // copy values
  try {
    for (std::size_t i = 0; i < src.length_; ++i) {
      tmp[i] = src.tArray_[i];
    }
  } catch (...) {
    delete[] tmp;
    throw;
  }

  // delete old resources
  delete[] this->tArray_;

  // assign new array
  this->tArray_ = tmp;

  // update array length
  this->length_ = src.length_;

  return *this;
}

template <typename T> T &Array<T>::operator[](std::size_t i) {
  if (i >= this->length_)
    throw std::out_of_range("Index out of bounds");
  return this->tArray_[i];
}

template <typename T> const T &Array<T>::operator[](std::size_t i) const {
  if (i >= this->length_)
    throw std::out_of_range("Index out of bounds");
  return this->tArray_[i];
}

template <typename T> std::size_t Array<T>::size() const {
  return this->length_;
}
