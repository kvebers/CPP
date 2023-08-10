#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <array>
#include <chrono>
#include <deque>
#include <iomanip>
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
	// vector + deque
	std::vector<int> _theVector;
	std::deque<int> _theDeque;
	std::vector<int> _theVector1;
	std::deque<int> _theDeque1;
	// functions for sortins stuff
	void sortDeque1();
	void sortVector1();
	void sortDeque();
	void sortVector();
	// estimate the stuff for mergesort optimisation
	void estimateThreshold();
	// vectort sort
	std::vector<int> FordVector(std::vector<int> &cont);
	std::vector<Pair> PairVectors(std::vector<int> &cont);
	std::vector<Pair> mergeSortVector(std::vector<Pair> &cont);
	std::vector<int> createVectorFirstElements(std::vector<Pair> &cont);
	std::vector<int> createVectorOtherElements(std::vector<Pair> &cont);
	void vectorInsertionSort(std::vector<int> &FirstVector, std::vector<int> &otherVector);
	void binaryInsertVector(std::vector<int> &FirstVector, int value, int range);

	// deque sort for later
};

#endif