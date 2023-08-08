#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <array>
#include <chrono>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>

template <typename CONT>
void checkContainer(CONT &cont, typename CONT::iterator start, typename CONT::iterator end) {
	typename CONT::iterator itCheck = start;
	itCheck++;
	for (; end != itCheck; itCheck++) {
		if (*itCheck < *start) {
			std::cout << "Something ain't sorted" << std::endl;
		}
		start++;
	}
	std::cout << "All sorted" << std::endl;
}

template <typename CONT>
void printContainer(CONT &cont, typename CONT::iterator start, typename CONT::iterator end,
					std::string justTheString) {
	std::cout << std::endl << justTheString;
	for (; start != end; start++) {
		std::cout << *start << " ";
	}
}

template <typename CONT>
void mergeSort(CONT &cont, typename CONT::iterator start, typename CONT::iterator end,
			   int treshold);

template <typename CONT>
void emptySubs(CONT &cont, CONT &leftovers, typename CONT::iterator &it,
			   typename CONT::const_iterator &otherIt) {
	while (otherIt != leftovers.end()) {
		*it = *otherIt;
		it++;
		otherIt++;
	}
}

template <typename CONT>
void mergeSubArrays(CONT &cont, CONT &startSide, CONT &endSide, typename CONT::iterator &it,
					typename CONT::const_iterator &itStartSide,
					typename CONT::const_iterator &itEndSide) {
	while (itStartSide != startSide.end() && itEndSide != endSide.end()) {
		if (*itStartSide <= *itEndSide) {
			*it = *itStartSide;
			itStartSide++;
		} else {
			*it = *itEndSide;
			itEndSide++;
		}
		it++;
	}
}

template <typename CONT>
void insertionSort(CONT &cont, typename CONT::iterator start, typename CONT::iterator end) {
	CONT startSide;
	CONT endSide;

	// printContainer(cont, start, end, "Incersion sort ");  // Uncomment for testing
	typename CONT::iterator it = start;
	typename CONT::const_iterator itStartSide = startSide.begin();
	typename CONT::const_iterator itEndSide = endSide.begin();
	mergeSubArrays(cont, startSide, endSide, it, itStartSide, itEndSide);
	emptySubs(cont, startSide, it, itStartSide);
	emptySubs(cont, endSide, it, itEndSide);
}

template <typename CONT>
void merge(CONT &cont, typename CONT::iterator start, typename CONT::iterator mid,
		   typename CONT::iterator end) {
	for (typename CONT::iterator cnt = start + 1; cnt != end; cnt++) {
		typename CONT::value_type theValue = *cnt;
		typename CONT::iterator previousCnt = cnt - 1;
		while (previousCnt >= start && theValue < *previousCnt) {
			*(previousCnt + 1) = *previousCnt;
			previousCnt--;
		}
		*(previousCnt + 1) = theValue;
	}
}

template <typename CONT>
void recursion(CONT &cont, typename CONT::iterator start, typename CONT::iterator end,
			   int treshold) {
	typename CONT::iterator mid = start + std::distance(start, end) / 2;
	mergeSort(cont, start, mid, treshold);
	mergeSort(cont, mid + 1, end, treshold);
	merge(cont, start, mid, end);
}

template <typename CONT>
void mergeSort(CONT &cont, typename CONT::iterator start, typename CONT::iterator end,
			   int treshold) {
	// printContainer(cont, start, end, "Recusion ");  // Uncomment for testing
	if (std::distance(start, end) > 0) {
		if (std::distance(start, end) < treshold)
			insertionSort(cont, start, end);
		else
			recursion(cont, start, end, treshold);
	}
}

class PmergeMe {
   public:
	PmergeMe();
	PmergeMe(char **argv, int argc);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &idk);
	PmergeMe(const PmergeMe &idk);
	void start();

   private:
	char **_input;
	int _argc;
	int _treshold;
	std::vector<unsigned int> _theVector;
	std::deque<unsigned int> _theDeque;
	void printVector();
	void sortDeque();
	void sortVector();
	void estimateThreshold();
};

#endif