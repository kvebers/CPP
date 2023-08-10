#include "PmergeMe.hpp"

#include "ExtraSort.tpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **argv, int argc) : _argc(argc), _input(argv) {}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &idk) {
	if (this == &idk) return *this;
	_argc = idk._argc;
	_input = idk._input;
	return *this;
}

PmergeMe::PmergeMe(const PmergeMe &idk) : _argc(idk._argc), _input(idk._input) {}

void PmergeMe::sortVector() {
	std::vector<int> newVector;
	clock_t startTime = clock();
	newVector = FordVector(_theVector);
	clock_t endTime = clock();
	printContainer(newVector, "This is the vector after sorting: ");
	std::cout << "Ford Sort | Vector Sort | Start Time: " << startTime << " End: " << endTime
			  << " Time Difference: " << std::setprecision(2) << std::fixed
			  << static_cast<double>(endTime - startTime) / (CLOCKS_PER_SEC / 1000000.0) << " us";
	// checkContainer(newVector, newVector.begin(), newVector.end());
}

void PmergeMe::sortDeque() {
	// clock_t startTime = clock();
	// mergeSort(_theDeque, _theDeque.begin(), _theDeque.end(), _treshold);
	// clock_t endTime = clock();
	// std::cout << std::endl
	// 		  << std::endl
	// 		  << "Ford Sort | Deque Sort |  Start Time : " << startTime << " End : " << endTime << "
	//   << " Time Difference: " << std::setprecision(2) << std::fixed
	//   << static_cast<double>(endTime - startTime) / (CLOCKS_PER_SEC / 1000000.0) << " us";
}

void PmergeMe::sortVector1() {
	clock_t startTime = clock();
	mergeSort(_theVector1, _theVector1.begin(), _theVector1.end(), _treshold);
	clock_t endTime = clock();
	std::cout << std::endl;
	std::cout << std::endl
			  << std::endl
			  << "Merge Sort | Vector Sort |  Start Time : " << startTime << " End : " << endTime
			  << " Time Difference: " << std::setprecision(2) << std::fixed
			  << static_cast<double>(endTime - startTime) / (CLOCKS_PER_SEC / 1000000.0) << " us";
	// checkContainer(_theVector1, _theVector1.begin(), _theVector1.end());
}

void PmergeMe::sortDeque1() {
	clock_t startTime = clock();
	mergeSort(_theDeque1, _theDeque1.begin(), _theDeque1.end(), _treshold);
	clock_t endTime = clock();
	std::cout << std::endl
			  << std::endl
			  << "Merge Sort | Deque Sort |  Start Time : " << startTime << " End : " << endTime
			  << " Time Difference: " << std::setprecision(2) << std::fixed
			  << static_cast<double>(endTime - startTime) / (CLOCKS_PER_SEC / 1000000.0) << " us";
	// checkContainer(_theDeque1, _theDeque1.begin(), _theDeque1.end());
}

void PmergeMe::estimateThreshold() { _treshold = sqrt(sqrt(_theVector.size() - 1)); }

void PmergeMe::start() {
	for (int cnt = 1; cnt < _argc; cnt++) {
		int input = std::stoi(_input[cnt]);
		if (input > std::numeric_limits<int>::max() || input < 0)
			throw std::logic_error("Error with the number input");
		_theVector.push_back(input);
		_theDeque.push_back(input);
		_theVector1.push_back(input);
		_theDeque1.push_back(input);
	}
	printContainer(_theVector, "This is the vector before sorting: ");
	// MERGESORT AND FORDS ALGORITHM COMPARISON
	sortVector();
	// sortDeque();
	estimateThreshold();
	sortVector1();
	sortDeque1();
}