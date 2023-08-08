#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <list>
#include <vector>

#define TRESHOLD 10





template <typename CONT>
void insertionSort(CONT &cont, typename CONT::iterator start, typename CONT::iterator end) {

}

template <typename CONT>
void merge(CONT &cont, typename CONT::iterator start, typename CONT::iterator mid,
		   typename CONT::iterator end) {
	for (typename CONT::iterator cnt = start + 1; cnt != end; cnt++) {
		typename CONT::value_type theValue = *cnt;
		typename CONT::iterator previousCnt = cnt - 1;
		while (previousCnt >= start && theValue < *previousCnt)	 // Perform Shift
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