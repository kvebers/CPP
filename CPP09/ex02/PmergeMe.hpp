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

typedef std::pair<int, int> Pair;

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
	std::vector<int> _theVector;
	std::deque<int> _theDeque;
	std::vector<int> _theVector1;
	std::deque<int> _theDeque1;
	void sortDeque1();
	void sortVector1();
	void sortDeque();
	void sortVector();
	void estimateThreshold();
	void FordVector(std::vector<int> &cont);
	std::vector<Pair> PairVectors(std::vector<int> &cont);
	std::vector<Pair> mergeSortVector(std::vector<Pair> &cont);
	std::vector<int> createVectorFirstElements(std::vector<Pair> &cont);
	std::vector<int> createVectorOtherElements(std::vector<Pair> &cont);
};

#endif