#include "PmergeMe.hpp"

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
	clock_t startTime = clock();
	mergeSort(_theVector, _theVector.begin(), _theVector.end(), _treshold);
	clock_t endTime = clock();
	std::cout << std::endl;
	printContainer(_theVector, _theVector.begin(), _theVector.end(),
				   "This is the vector after sorting: ");
	std::cout << std::endl
			  << std::endl
			  << "Vector Sort |  Start Time : " << startTime << " End : " << endTime
			  << " Time Dif: "
			  << static_cast<double>(endTime - startTime) / (CLOCKS_PER_SEC / 1000.0) << "ms";
}

void PmergeMe::sortDeque() {
	clock_t startTime = clock();
	mergeSort(_theDeque, _theDeque.begin(), _theDeque.end(), _treshold);
	clock_t endTime = clock();
	std::cout << std::endl
			  << std::endl
			  << "Deque Sort |  Start Time : " << startTime << " End : " << endTime << " Time Dif: "
			  << static_cast<double>(endTime - startTime) / (CLOCKS_PER_SEC / 1000.0) << "ms"
			  << std::endl;
}

void PmergeMe::estimateThreshold() { _treshold = sqrt(sqrt(_theVector.size() - 1)); }

void PmergeMe::start() {
	for (int cnt = 1; cnt < _argc; cnt++) {
		int input = std::stoi(_input[cnt]);
		if (input > std::numeric_limits<int>::max() || input < 0)
			throw std::logic_error("Error with the number input");
		if (input == 0 && _input[cnt][0] != 0) throw std::logic_error("Error incorrect Input");
		_theVector.push_back(input);
		_theDeque.push_back(input);
	}
	estimateThreshold();
	printContainer(_theVector, _theVector.begin(), _theVector.end(),
				   "This is the vector before sorting: ");
	sortVector();
	sortDeque();
}