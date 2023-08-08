#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <list>
#include <vector>

template <typename CONT>
void insertionSort(CONT &cont, typename CONT::iterator left, typename CONT::iterator right) {}

template <typename CONT>
void merge(CONT &cont, typename CONT::iterator left, typename CONT::iterator mid,
		   typename CONT::iterator right) {}

template <typename CONT>
void fordJohnsonSort(CONT &cont, typename CONT::iterator left, typename CONT::iterator right) {
	if (std::distance(left, right) > 0) {
	
	
	
	
	
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