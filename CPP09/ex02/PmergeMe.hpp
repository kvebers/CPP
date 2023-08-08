#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <chrono>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>

#define TRESHOLD 10

template <typename CONT>
void printContainer(CONT &cont, typename CONT::iterator start, typename CONT::iterator end,
					std::string justTheString) {
	std::cout << std::endl << justTheString;
	for (; start != end; start++) {
		std::cout << *start << " ";
	}
}

template <typename CONT>
void fordJohnsonSort(CONT &cont, typename CONT::iterator start, typename CONT::iterator end);

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

	typename CONT::iterator it = start;
	typename CONT::const_iterator itStartSide = startSide.begin();	// Use const_iterator
	typename CONT::const_iterator itEndSide = endSide.begin();		// Use const_iterator
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
		while (previousCnt >= start && theValue < *previousCnt)	 // Perform Shift of the
		{
			*(previousCnt + 1) = *previousCnt;
			previousCnt--;
		}
		*(previousCnt + 1) = theValue;
	}
}
template <typename CONT>
void recursion(CONT &cont, typename CONT::iterator start, typename CONT::iterator end) {
	typename CONT::iterator mid = start + std::distance(start, end) / 2;
	fordJohnsonSort(cont, start, mid);
	fordJohnsonSort(cont, mid + 1, end);
	merge(cont, start, mid, end);
}

template <typename CONT>
void fordJohnsonSort(CONT &cont, typename CONT::iterator start, typename CONT::iterator end) {
	if (std::distance(start, end) > 0) {
		if (std::distance(start, end) < TRESHOLD)
			insertionSort(cont, start, end);
		else
			recursion(cont, start, end);
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
	std::vector<unsigned int> _theVector;
	std::deque<unsigned int> _theDeque;
	std::list<unsigned int> _theList;
	void printVector();
};

#endif