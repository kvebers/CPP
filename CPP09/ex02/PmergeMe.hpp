#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <array>
#include <chrono>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>

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
	std::vector<unsigned int> _theVector1;
	std::deque<unsigned int> _theDeque1;
	void sortDeque1();
	void sortVector1();
	void sortDeque();
	void sortVector();
	void estimateThreshold();
};

#endif