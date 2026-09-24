#include <iostream>
#include <list>
#include <stack>
#include <vector>

#include "MutantStack.hpp"

int main() {
  {
    // subject
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int> s(mstack);
  }
  {
    // vector
    MutantStack<int, std::vector<int> > mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int, std::vector<int> >::iterator it = mstack.begin();
    MutantStack<int, std::vector<int> >::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int, std::vector<int> > s(mstack);
  }
  {
    // list
    MutantStack<int, std::list<int> > mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int, std::list<int> >::iterator it = mstack.begin();
    MutantStack<int, std::list<int> >::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int, std::list<int> > s(mstack);
  }
  {
    // copy constructor
    std::cout << "--- Copy Constructor ---" << std::endl;

    MutantStack<int> src;
    src.push(5);
    src.push(17);
    src.push(42);

    MutantStack<int> copy(src);

    MutantStack<int>::iterator it = copy.begin();
    MutantStack<int>::iterator ite = copy.end();

    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }

    // Check that the copy is independent from the source.
    src.push(99);

    std::cout << "--- Copy After Source Modified ---" << std::endl;

    it = copy.begin();
    ite = copy.end();

    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
  }

  {
    // copy assignment
    std::cout << "--- Copy Assignment ---" << std::endl;

    MutantStack<int> src;
    src.push(5);
    src.push(17);
    src.push(42);

    MutantStack<int> dst;
    dst.push(999);

    dst = src;

    MutantStack<int>::iterator it = dst.begin();
    MutantStack<int>::iterator ite = dst.end();

    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }

    // Check that the assigned object is independent from the source.
    src.push(99);

    std::cout << "--- Assignment After Source Modified ---" << std::endl;

    it = dst.begin();
    ite = dst.end();

    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
  }
  return 0;
}
