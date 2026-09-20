#pragma once

#include <algorithm>
#include <stdexcept>

template <typename T> typename T::iterator easyfind(T &src, int target) {
  typename T::iterator it = std::find(src.begin(), src.end(), target);
  if (it != src.end())
    return it;
  else
    throw std::runtime_error("ERROR: target not found");
}
