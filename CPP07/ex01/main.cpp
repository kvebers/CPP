#include "Templates.hpp"

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	char charArray[] = {'l', 'a', 'm', 'e'};

	std::cout << "THE FIRST TEST OF JUST ITERATORS" << std::endl;
	::iter(intArray, 5, printS<int>);
	std::cout << std::endl;
	::iter(doubleArray, 5, printS<double>);
	std::cout << std::endl;
	::iter(charArray, 4, printS<char>);
	std::cout << std::endl;
	::iter(intArray, 5, inc1<int>);
	::iter(doubleArray, 5, inc1<double>);
	::iter(charArray, 4, inc1<char>);
	std::cout << "THE FIRST TEST + 1" << std::endl;
	::iter(intArray, 5, printS<int>);
	std::cout << std::endl;
	::iter(doubleArray, 5, printS<double>);
	std::cout << std::endl;
	::iter(charArray, 4, printS<char>);
	std::cout << std::endl;
	std::cout << "RANDOM TEST B OR S" << std::endl;
	std::cout << std::endl;
	::iter(intArray, 5, check_bigger<int>);
	std::cout << std::endl;
	::iter(doubleArray, 5, check_bigger<double>);
	std::cout << std::endl;
	::iter(charArray, 4, check_bigger<char>);
	std::cout << std::endl;
}