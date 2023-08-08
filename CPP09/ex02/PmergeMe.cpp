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

void PmergeMe::printVector() {
	std::cout << "Unsoted integer vector: ";
	std::cout << _theVector.size();
	for (std::vector<unsigned int>::iterator it = _theVector.begin(); it != _theVector.end();
		 it++) {
		std::cout << *it << " ";
	}
}

void PmergeMe::start() {
	for (int cnt = 1; cnt < _argc; cnt++) {
		int input = std::stoi(_input[cnt]);
		if (input > std::numeric_limits<int>::max() || input < 0)
			throw std::logic_error("Error with the number input");
		if (input == 0 && _input[cnt][0] != 0) throw std::logic_error("Error incorrect Input");
		_theVector.push_back(input);
		_theDeque.push_back(input);
	}
	printVector();
	fordJohnsonSort(_theVector, _theVector.begin(), _theVector.end());
	printVector();
}