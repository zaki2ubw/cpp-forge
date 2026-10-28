#include <deque>
#include <stdexcept>
#include <sys/time.h>
#include <vector>

#include "DequeFordJohnson.hpp"
#include "Jacobsthal.hpp"
#include "PmergeMe.hpp"
#include "VectorFordJohnson.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) { *this = src; }

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
  if (this != &src) {
    jacobVector = src.jacobVector;
    vectorResult = src.vectorResult;
    dequeResult = src.dequeResult;
    jacobTimeUs = src.jacobTimeUs;
    vectorTimeUs = src.vectorTimeUs;
    dequeTimeUs = src.dequeTimeUs;
    vectorSortCount = src.vectorSortCount;
    dequeSortCount = src.dequeSortCount;
    theoreticalMax = src.theoreticalMax;
  }
  return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::benchmark(int argc, char **argv) {
  // 1. 前回状態をreset
  jacobVector.clear();
  vectorResult.clear();
  dequeResult.clear();

  jacobTimeUs = 0.0;
  vectorTimeUs = 0.0;
  dequeTimeUs = 0.0;

  vectorSortCount = 0;
  dequeSortCount = 0;
  theoreticalMax = 0;
  // 2. Jacob生成 + 計測
  const std::size_t inputSize = static_cast<std::size_t>(argc - 1);

  double jacobStart = getCurrentTime();
  jacobVector = generateJacobsthalSequence((inputSize + 1) / 2);
  jacobTimeUs = getCurrentTime() - jacobStart;
  // 3. raw input -> vector
  //    VectorFordJohnson実行 + 計測
  double startVector = getCurrentTime();

  std::vector<int> vectorInput = makeContainer<std::vector<int>>(argc, argv);

  VectorFordJohnson vectorSorter(vectorInput);
  vectorResult = vectorSorter.mergeInsertionSort(jacobVector);

  vectorTimeUs = jacobTimeUs + (getCurrentTime() - startVector);
  vectorSortCount = vectorSorter.getSortCount();
  // 4. raw input -> deque
  //    DequeFordJohnson実行 + 計測
  double startDeque = getCurrentTime();

  std::deque<int> dequeInput = makeContainer<std::deque<int>>(argc, argv);

  DequeFordJohnson dequeSorter(dequeInput);
  dequeResult = dequeSorter.mergeInsertionSort(jacobVector);

  dequeTimeUs = jacobTimeUs + (getCurrentTime() - startDeque);
  dequeSortCount = dequeSorter.getSortCount();
  // 5. sortCount取得

  // 6. theoreticalMax計算
  theoreticalMax = calculateTheoreticalMax(static_cast<std::size_t>(argc - 1));
  // 7. auditResults()
  auditResults();
}

const std::vector<int> &PmergeMe::getResult() const { return vectorResult; }

double PmergeMe::getVectorTimeUs() const { return vectorTimeUs; }

double PmergeMe::getDequeTimeUs() const { return dequeTimeUs; }

std::size_t PmergeMe::getVectorSortCount() const { return vectorSortCount; }

std::size_t PmergeMe::getDequeSortCount() const { return dequeSortCount; }

std::size_t PmergeMe::getTheoreticalMax() const { return theoreticalMax; }

double PmergeMe::getCurrentTime() const {
  struct timeval time;

  gettimeofday(&time, NULL);
  return static_cast<double>(time.tv_sec) * 1000000.0 +
         static_cast<double>(time.tv_usec);
}

std::size_t PmergeMe::calculateTheoreticalMax(std::size_t inputSize) const {
  std::size_t total = 0;

  for (std::size_t k = 1; k <= inputSize; ++k) {
    std::size_t power = 1;
    std::size_t comparisonCount = 0;

    while (4 * power < 3 * k) {
      power *= 2;
      ++comparisonCount;
    }
    total += comparisonCount;
  }

  return total;
}

void PmergeMe::auditResults() const {
  if (vectorResult.size() != dequeResult.size())
    throw std::runtime_error("Vector and deque result sizes differ");

  for (std::size_t i = 0; i < vectorResult.size(); ++i) {
    if (vectorResult[i] != dequeResult[i])
      throw std::runtime_error("Vector and deque results differ");
  }

  if (!isSorted(vectorResult))
    throw std::runtime_error("Vector result is not sorted");

  if (!isSorted(dequeResult))
    throw std::runtime_error("Deque result is not sorted");

  if (vectorSortCount > theoreticalMax)
    throw std::runtime_error("Vector comparison count exceeds theoretical max");

  if (dequeSortCount > theoreticalMax)
    throw std::runtime_error("Deque comparison count exceeds theoretical max");

  if (vectorSortCount != dequeSortCount)
    throw std::runtime_error("Vector and deque comparison counts differ");
}
