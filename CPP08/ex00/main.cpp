#include <cstdlib>
#include <exception>
#include <iterator>
#include <ostream>
#include <vector>

#include "Templates.hpp"

#define TEST_CASE 10

int main() {
	try {
		std::cout << "This is the TEST 1" << std::endl;
		int startValue = -5;
		srand(time(0));
		std::vector<int> intVector;
		for (int cnt = 0; cnt < TEST_CASE; cnt++) {
			intVector.push_back(startValue + cnt);
		}
		int valueToFind = rand() % TEST_CASE + startValue;
		std::cout << "The Value to Find is " << valueToFind << std::endl;
		std::vector<int>::iterator iterator = easyfind(intVector, valueToFind);
		std::cout << "The Value is Found " << *iterator << " at "
				  << std::distance(intVector.begin(), iterator) << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		{
			std::vector<int> intVector;
			std::cout << "This is the TEST 2" << std::endl;
			int valueToFind = 3;
			for (int cnt = 0; cnt < TEST_CASE; cnt++) {
				intVector.push_back(cnt);
			}
			std::cout << "The Value to Find is " << valueToFind << std::endl;
			std::vector<int>::iterator iterator = easyfind(intVector, valueToFind);
			std::cout << "The Value is Found " << *iterator << " at "
					  << std::distance(intVector.begin(), iterator) << std::endl;
		}
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		{
			std::vector<int> intVector;
			std::cout << "This is the TEST 3" << std::endl;
			int valueToFind = 12;
			for (int cnt = 0; cnt < TEST_CASE; cnt++) {
				intVector.push_back(cnt);
			}
			std::cout << "The Value to Find is " << valueToFind << std::endl;
			std::vector<int>::iterator iterator = easyfind(intVector, valueToFind);
			std::cout << "The Value is Found " << *iterator << " at "
					  << std::distance(intVector.begin(), iterator) << std::endl;
		}
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
