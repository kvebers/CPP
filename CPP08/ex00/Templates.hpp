#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <vector>

template <typename EASY>
typename EASY::iterator easyfind(EASY& container, int valueToFind) {
	typename EASY::iterator iterator = std::find(container.begin(), container.end(), valueToFind);
	if (iterator != container.end())
		return iterator;
	else
		throw std::logic_error("There ain't such value inside the vector");
}

#endif
