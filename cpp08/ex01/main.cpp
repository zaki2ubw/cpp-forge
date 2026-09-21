#include <climits>
#include <iostream>
#include <list>
#include <vector>

#include "Span.hpp"

int main(void) {
  {
    // subject main
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }
  {
    // requirement 10000 Case
    try {
      Span sp = Span(10000);
      for (int i = 0; i < 10000; ++i) {
        sp.addNumber(i);
      }
      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    // requirement range case by vector
    try {
      Span sp = Span(10);
      std::vector<int> v;
      v.push_back(21);
      v.push_back(1);
      v.push_back(34);
      v.push_back(3);
      v.push_back(1);
      v.push_back(13);
      v.push_back(2);
      v.push_back(55);
      v.push_back(5);
      v.push_back(8);
      sp.addNumber(v.begin(), v.end());
      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    // requirement range case by list
    try {
      Span sp = Span(10);
      std::list<int> l;
      l.push_back(21);
      l.push_back(1);
      l.push_back(34);
      l.push_back(3);
      l.push_back(1);
      l.push_back(13);
      l.push_back(2);
      l.push_back(55);
      l.push_back(5);
      l.push_back(8);
      sp.addNumber(l.begin(), l.end());
      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    // multiple range case
    try {
      Span sp = Span(10);
      std::vector<int> v;
      std::list<int> l;
      v.push_back(21);
      v.push_back(1);
      v.push_back(34);
      v.push_back(3);
      v.push_back(1);
      l.push_back(13);
      l.push_back(2);
      l.push_back(55);
      l.push_back(5);
      sp.addNumber(v.begin(), v.end());
      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
      sp.addNumber(l.begin(), l.end());
      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
      sp.addNumber(v.begin(), v.end());
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    // out of bounds exceptions
    try {
      Span sp = Span(5);
      sp.addNumber(6);
      sp.addNumber(3);
      sp.addNumber(17);
      sp.addNumber(9);
      sp.addNumber(11);
      sp.addNumber(11);
      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    // not enough param exceptions in short
    try {
      Span sp = Span(5);
      sp.addNumber(6);
      std::cout << sp.shortestSpan() << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    // not enough param exceptions in long
    try {
      Span sp = Span(5);
      sp.addNumber(6);
      std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    // over 10000 Case
    try {
      Span sp = Span(100000);
      for (int i = 0; i < 100000; ++i) {
        sp.addNumber(i);
      }
      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    // boundary test
    try {
      Span sp = Span(5);
      std::vector<int> v;
      v.push_back(INT_MAX);
      v.push_back(-302);
      v.push_back(42);
      v.push_back(INT_MAX);
      v.push_back(INT_MIN);
      sp.addNumber(v.begin(), v.end());
      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
}
