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
	std::cout << "\033[4;32m"
			  << "Ford Sort | Vector Sort | Start Time: " << startTime << " End: " << endTime
			  << " Time Difference: " << std::setprecision(2) << std::fixed
			  << static_cast<double>(endTime - startTime) / (CLOCKS_PER_SEC / 1000000.0) << " us"
			  << "\033[0m" << std::endl;
}

void PmergeMe::sortDeque() {
	std::deque<int> newVector;
	clock_t startTime = clock();
	newVector = FordDeque(_theDeque);
	clock_t endTime = clock();
	std::cout << "\033[4;32m"
			  << "Ford Sort | Deque Sort | Start Time: " << startTime << " End: " << endTime
			  << " Time Difference: " << std::setprecision(2) << std::fixed
			  << static_cast<double>(endTime - startTime) / (CLOCKS_PER_SEC / 1000000.0) << " us"
			  << "\033[0m" << std::endl;
}

void PmergeMe::sortVector1() {
	clock_t startTime = clock();
	mergeSort(_theVector1, _theVector1.begin(), _theVector1.end(), _treshold);
	clock_t endTime = clock();
	std::cout << "\033[4;32m"
			  << "Merge Sort | Vector Sort |  Start Time : " << startTime << " End : " << endTime
			  << " Time Difference: " << std::setprecision(2) << std::fixed
			  << static_cast<double>(endTime - startTime) / (CLOCKS_PER_SEC / 1000000.0) << " us"
			  << "\033[0m" << std::endl;
	// checkContainer(_theVector1, _theVector1.begin(), _theVector1.end());
}

void PmergeMe::sortDeque1() {
	clock_t startTime = clock();
	mergeSort(_theDeque1, _theDeque1.begin(), _theDeque1.end(), _treshold);
	clock_t endTime = clock();
	std::cout << "\033[4;32m"
			  << "Merge Sort | Deque Sort |  Start Time : " << startTime << " End : " << endTime
			  << " Time Difference: " << std::setprecision(2) << std::fixed
			  << static_cast<double>(endTime - startTime) / (CLOCKS_PER_SEC / 1000000.0) << " us"
			  << "\033[0m" << std::endl;
	// checkContainer(_theDeque1, _theDeque1.begin(), _theDeque1.end());
}

void PmergeMe::checkBuiltin() {
	clock_t startTime = clock();
	std::sort(_theBuiltinVector.begin(), _theBuiltinVector.end());
	clock_t endTime = clock();
	std::cout << "\033[4;32m"
			  << "Builtin Sort | Vector Sort |  Start Time : " << startTime << " End : " << endTime
			  << " Time Difference: " << std::setprecision(2) << std::fixed
			  << static_cast<double>(endTime - startTime) / (CLOCKS_PER_SEC / 1000000.0) << " us"
			  << "\033[0m" << std::endl;

	startTime = clock();
	std::sort(_theBuiltinDeque.begin(), _theBuiltinDeque.end());
	endTime = clock();
	std::cout << "\033[4;32m"
			  << "Builtin Sort | Deque Sort |  Start Time : " << startTime << " End : " << endTime
			  << " Time Difference: " << std::setprecision(2) << std::fixed
			  << static_cast<double>(endTime - startTime) / (CLOCKS_PER_SEC / 1000000.0) << " us"
			  << "\033[0m" << std::endl;
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
		_theBuiltinDeque.push_back(input);
		_theBuiltinVector.push_back(input);
	}
	printContainer(_theVector, "This is the vector before sorting: ");
	// MERGESORT AND FORDS ALGORITHM COMPARISON
	sortVector();
	sortDeque();
	estimateThreshold();
	std::cout << "\033[1;33;4mBONUS SORT WITH TEMPLATES\033[0m" << std::endl;
	sortVector1();
	sortDeque1();
	std::cout << "\033[1;33;4mCHEKING THE BUILTIN TIMES OF THE STD::SORT\033[0m" << std::endl;
	checkBuiltin();
}