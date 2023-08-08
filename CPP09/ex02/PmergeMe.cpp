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

void PmergeMe::start() {
	for (int cnt = 1; cnt < _argc; cnt++) {
		int input = std::stoi(_input[cnt]);
		if (input > std::numeric_limits<int>::max() || input < 0)
			throw std::logic_error("Error with the number input");
		if (input == 0 && _input[cnt][0] != 0) throw std::logic_error("Error incorrect Input");
		_theVector.push_back(input);
		_theDeque.push_back(input);
	}
	printContainer(_theVector, _theVector.begin(), _theVector.end(),
				   "This is the vector before sorting: ");
	clock_t startTime = clock();
	fordJohnsonSort(_theVector, _theVector.begin(), _theVector.end());
	clock_t endTime = clock();
	printContainer(_theVector, _theVector.begin(), _theVector.end(),
				   "This is the vector after sorting: ");
	std::cout << std::endl
			  << "Vector Sort Time Start : " << startTime << " End : " << endTime << " Time Dif: "
			  << static_cast<double>(endTime - startTime) / (CLOCKS_PER_SEC / 1000.0) << "ms";
}