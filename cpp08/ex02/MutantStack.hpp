#pragma once

#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
  typedef typename Container::iterator iterator;
  // OCF
  MutantStack();
  ~MutantStack();
  MutantStack(const MutantStack &src);
  MutantStack &operator=(const MutantStack &src);

  // iter funcs
  iterator begin();
  iterator end();

private:
};

#include "MutantStack.tpp"
