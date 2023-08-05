#include "Span.hpp"

Span::Span() : _maxLen(10) {}

Span::~Span() {}

Span &Span::operator=(const Span &idk) {
	if (this == &idk) return *this;
	_maxLen = idk._maxLen;
	_span = idk._span;
	return *this;
}

Span::Span(const Span &idk) {
	_maxLen = idk._maxLen;
	_span = idk._span;
}

Span::Span(unsigned int len) : _maxLen(len) {}

// UTILITIES
int Span::getSize() { return _span.size(); }
int Span::getSpamMaxLen() { return _maxLen; }

// ACTUAL FUNCTIONS FROM THE EXCERSISE
void Span::addNumber(int numb) {
	if (_maxLen <= getSize())
		throw std::logic_error("Error: Your Email is full with span, please clear it");
	_span.push_back(numb);
}

void Span::checkValid() {
	if (getSize() < 2) throw std::logic_error("Error: You do not have enought mail");
}

int Span::longestSpan() {
	checkValid();
	std::vector<int>::iterator maxElement = std::max_element(_span.begin(), _span.end());
	std::vector<int>::iterator minElement = std::min_element(_span.begin(), _span.end());
	// std::cout << "This is the debug values of the longest SPAM!" << std::endl
	// 		  << " Value 1: " << *maxElement << " Value 2: " << *minElement << std::endl;
	return (*maxElement - *minElement);
}

int Span::shortestSpan() {
	checkValid();
	int temp = longestSpan();
	int value;
	int previousValue;
	std::vector<int> copyVector = _span;
	std::sort(copyVector.begin(), copyVector.end());
	std::vector<int>::iterator iterator = copyVector.begin();
	previousValue = *iterator;
	iterator++;
	for (; iterator + 1 != copyVector.end(); iterator++) {
		value = *iterator - previousValue;
		if (temp > value) {
			temp = value;
			if (temp == 0) return temp;
			// std::cout << previousValue << " " << *iterator << std::endl;uncomment for testing
			// purposed I had brain dmg after this
		}
		previousValue = *iterator;
	}
	return temp;
}

void Span::addSpan(unsigned int numb) {
	srand(time(0));
	for (int cnt = 0; cnt < numb; cnt++) {
		int number = rand() % (numb * numb * 10);
		addNumber(number);
		// std::cout << number << " "; // TESTING 
	}
}