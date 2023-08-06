#include <exception>

#include "BitcoinExchange.hpp"

// void processMap(const std::map<std::string, int>& myMap) {
int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "PLEASE STOP, LEAVE ME ALONE" << std::endl;
		return 1;
	}
	try {
		std::string input = argv[1];
		BitcoinExchange IStoleYourLogTime(input);
		IStoleYourLogTime.start();
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
