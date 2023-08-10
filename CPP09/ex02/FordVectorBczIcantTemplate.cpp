
#include <cmath>
#include <iostream>
#include <vector>

#include "ExtraSort.tpp"
#include "PmergeMe.hpp"

int jacobsNumberGen(int n) {
	int term1 = n * std::ceil(std::log2(3.0 * n / 4.0));
	int term2 = std::floor(std::pow(2, std::floor(std::log2(6.0 * n))) / 3);
	int term3 = std::floor(std::log2(6.0 * n) / 2);

	int result = term1 - term2 + term3;
	return result;
}

void PmergeMe::insertVector(std::vector<int> &FirstVector, int value, int range) {
	int cnt = range;
	while (cnt >= 0 && FirstVector[cnt] > value) {
		cnt--;
	}
	FirstVector.insert(FirstVector.begin() + cnt + 1, value);
}

void PmergeMe::vectorInsertionSort(std::vector<int> &FirstVector, std::vector<int> &otherVector) {
	int counter = 0;
	int jacobsIndexLow = -1;
	int jacobsIndexUp = jacobsNumberGen(0);
	int jacobsNumber = 0;
	while (jacobsNumber < otherVector.size()) {
		while (jacobsNumber > jacobsIndexLow) {
			insertVector(FirstVector, otherVector[jacobsNumber - 1], jacobsIndexUp);
			std::cout << jacobsNumber << " " << otherVector[jacobsNumber - 1] << std::endl;
			jacobsNumber--;
		}
		counter++;
		jacobsIndexLow = jacobsIndexUp;
		jacobsIndexUp = jacobsNumberGen(counter);
		jacobsNumber = jacobsIndexUp;
	}
	jacobsNumber = otherVector.size();
	while (jacobsNumber > jacobsIndexLow) {
		insertVector(FirstVector, otherVector[jacobsNumber - 1], FirstVector.size());
		std::cout << jacobsNumber << " " << otherVector[jacobsNumber - 1] << std::endl;
		jacobsNumber--;
	}
}

std::vector<int> PmergeMe::createVectorOtherElements(std::vector<Pair> &cont) {
	std::vector<int> smollVector;
	std::vector<Pair>::iterator it = cont.begin() + 1;
	for (; it != cont.end(); it++) {
		smollVector.push_back(it->second);
	}
	return smollVector;
}

std::vector<int> PmergeMe::createVectorFirstElements(std::vector<Pair> &cont) {
	std::vector<int> smollVector;
	std::vector<Pair>::iterator it = cont.begin();
	smollVector.push_back(it->second);
	for (; it != cont.end(); it++) {
		smollVector.push_back(it->first);
	}
	return smollVector;
}

std::vector<Pair> PmergeMe::PairVectors(std::vector<int> &cont) {
	std::vector<Pair> pairedVectors;
	std::vector<int>::const_iterator it = cont.begin();
	std::vector<int>::const_iterator it1 = cont.begin();
	it1++;
	while (it != cont.end() && it1 != cont.end()) {
		if (*it > *it1)
			pairedVectors.push_back(std::make_pair(*it, *it1));
		else
			pairedVectors.push_back(std::make_pair(*it1, *it));
		it += 2;
		it1 += 2;
	}

	if (it != cont.end()) {
		pairedVectors.push_back(std::make_pair(*it, -1));
	}
	return (pairedVectors);
}

std::vector<Pair> mergeVector(std::vector<Pair> &left, std::vector<Pair> &right) {
	std::vector<Pair> result;
	std::vector<Pair>::const_iterator it = left.begin();
	std::vector<Pair>::const_iterator it1 = right.begin();

	while (it != left.end() && it1 != right.end()) {
		if (it->first < it1->first) {
			result.push_back(*it);
			it++;
		} else {
			result.push_back(*it1);
			it1++;
		}
	}
	while (it != left.end()) {
		result.push_back(*it);
		it++;
	}
	while (it1 != right.end()) {
		result.push_back(*it1);
		it1++;
	}
	return result;
}

std::vector<Pair> PmergeMe::mergeSortVector(std::vector<Pair> &cont) {
	if (cont.size() <= 1) {
		return cont;
	}
	size_t middle = cont.size() / 2;
	std::vector<Pair> left(cont.begin(), cont.begin() + middle);
	std::vector<Pair> right(cont.begin() + middle, cont.end());
	left = mergeSortVector(left);
	right = mergeSortVector(right);
	return mergeVector(left, right);
}

std::vector<int> PmergeMe::FordVector(std::vector<int> &cont) {
	std::vector<Pair> pairedVectors = PairVectors(cont);
	// printPairVector(pairedVectors);	 // DEBUG
	pairedVectors = mergeSortVector(pairedVectors);
	// printPairVector(pairedVectors);
	std::vector<int> FirstVector = createVectorFirstElements(pairedVectors);
	std::vector<int> OtherVector = createVectorOtherElements(pairedVectors);
	// printContainer(FirstVector, FirstVector.begin(), FirstVector.end(), "First Vector : ");
	// printContainer(OtherVector, OtherVector.begin(), OtherVector.end(), "Other Vector : ");
	vectorInsertionSort(FirstVector, OtherVector);
	return FirstVector;
}