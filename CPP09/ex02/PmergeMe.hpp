#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
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

int jacobsNumberGen(int n);

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
	std::vector<int> _theBuiltinVector;
	std::deque<int> _theBuiltinDeque;
	// functions for sortins stuff
	void sortDeque1();
	void sortVector1();
	void sortDeque();
	void sortVector();
	void checkBuiltin();
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
	std::vector<Pair> mergeVector(std::vector<Pair> &left, std::vector<Pair> &right);

	// deque sort for later
	std::deque<int> FordDeque(std::deque<int> &cont);
	std::deque<Pair> PairDeque(std::deque<int> &cont);
	std::deque<Pair> mergeSortDeque(std::deque<Pair> &cont);
	std::deque<int> createDequeFirstElements(std::deque<Pair> &cont);
	std::deque<int> createDequeOtherElements(std::deque<Pair> &cont);
	void dequeInsertionSort(std::deque<int> &FirstVector, std::deque<int> &otherVector);
	void binaryInsertDeque(std::deque<int> &FirstVector, int value, int range);
	std::deque<Pair> mergeDeque(std::deque<Pair> &left, std::deque<Pair> &right);
};

#endif