#include "PmergeMe.hpp"

// UTILS

template <typename CONT>
void checkContainer(CONT &cont, typename CONT::iterator start, typename CONT::iterator end) {
	typename CONT::iterator itCheck = start;
	int cnt = 0;
	itCheck++;
	for (; end != itCheck; itCheck++) {
		if (*itCheck < *start) {
			std::cout << "| \033[1;31mSomething ain't sorted " << *start << " " << *itCheck
					  << "\033[0m" << std::endl;
			return;
		}
		start++;
	}
	std::cout << "| \033[1;32mAll sorted\033[0m" << std::endl;
}

template <typename CONT>
void printContainer(CONT &cont, std::string justTheString) {
	std::cout << "\033[1;32m" << justTheString << "\033[0m \033[1;33m";
	typename CONT::iterator start = cont.begin();
	for (typename CONT::iterator start = cont.begin(); start != cont.end(); start++) {
		std::cout << *start << " ";
	}
	std::cout << "\033[0m";
	checkContainer(cont, cont.begin(), cont.end());
}

template <typename CONT>
void printPairVector(const CONT &pair) {
	std::cout << std::endl;
	for (size_t i = 0; i < pair.size(); ++i) {
		std::cout << "Pair " << i << ": (" << pair[i].first << ", " << pair[i].second << ")"
				  << std::endl;
	}
}

// END OF UTILS

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