#include <unistd.h>

#include <exception>
#include <iostream>

#include "Span.hpp"

int main() {
	try {
		std::cout << std::endl << "TEST 1 " << std::endl << std::endl;
		int test_cases = 10000;	 // SWITCH THIS TO INCREASE OR DECREASE THE TEST SIZE DEFAULT 10000;
		Span spam(test_cases + 1);
		srand(time(0));
		for (int cnt = 0; cnt < test_cases; cnt++) {
			int number =
				rand() % (test_cases * test_cases *
						  10);	// just ...........................................................
			spam.addNumber(number);
			std::cout << number << " ";
		}

		std::cout << std::endl << "STARTING THE SEND ALGORITHM..." << std::endl << std::endl;
		std::cout << "Longest SPAM : " << spam.longestSpan() << std::endl;
		std::cout << "Shortest SPAM : " << spam.shortestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << std::endl << "TEST 2 " << std::endl << std::endl;
		Span spam(1);
		std::cout << "Get Spam Size : " << spam.getSize()
				  << " Get Spam Max Val: " << spam.getSpamMaxLen() << std::endl;
		spam.addNumber(4);
		std::cout << "Get Spam Size : " << spam.getSize()
				  << " Get Spam Max Val: " << spam.getSpamMaxLen() << std::endl;
		spam.addNumber(4);
		std::cout << "Get Spam Size : " << spam.getSize()
				  << " Get Spam Max Val: " << spam.getSpamMaxLen() << std::endl;

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << std::endl << "TEST 3 " << std::endl << std::endl;
		Span spam(1);
		spam.addNumber(4);
		spam.shortestSpan();
		spam.longestSpan();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << std::endl << "TEST 4 " << std::endl << std::endl;
		Span spam(5);
		spam.addNumber(1);
		spam.addNumber(2);
		spam.addNumber(4);
		spam.addNumber(6);
		spam.addNumber(8);
		std::cout << std::endl << "STARTING THE SEND ALGORITHM..." << std::endl << std::endl;
		std::cout << "Longest SPAM : " << spam.longestSpan() << std::endl;	  // 8 - 1 == 7
		std::cout << "Shortest SPAM : " << spam.shortestSpan() << std::endl;  // 2 - 1 == 1
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << std::endl << "TEST 5 " << std::endl << std::endl;
		Span spam(1);
		spam.longestSpan();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << std::endl << "TEST 6 " << std::endl << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		return 0;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
