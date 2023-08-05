#ifndef SPAM_HPP
#define SPAM_HPP

#include <unistd.h>

#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <vector>

class Span {
   public:
	// ORTHODOX STUFF
	Span();
	~Span();
	Span &operator=(const Span &spam);
	Span(const Span &idk);
	Span(unsigned int);

	// Functions

	// UTILS
	int getSize();
	int getSpamMaxLen();
	void checkValid();

	// MANDATORY
	void addNumber(int numb);
	int longestSpan();
	int shortestSpan();
	void addSpan(unsigned int numb);

   private:
	unsigned int _maxLen;
	std::vector<int> _span;
};

#endif