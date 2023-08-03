#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <sys/_types/_size_t.h>
#include <sys/syslimits.h>

#include <iostream>

template <typename PRINTER>
void printS(PRINTER a) {
	std::cout << a << " ";	// PRINT STUFF
}

template <typename INC1>
void inc1(INC1 &a) {
	a++;  // ADD 1
}

template <typename BIGGER>
void check_bigger(BIGGER a) {
	if (a > 5)
		std::cout << "B ";	// BIGGER
	else
		std::cout << "S ";	// SMOLLER
}

template <typename ITER, typename FUNCTION>
void iter(ITER *data, size_t len, FUNCTION fun) {
	for (size_t cnt = 0; cnt < len; cnt++) {
		fun(data[cnt]);
	}
}

#endif