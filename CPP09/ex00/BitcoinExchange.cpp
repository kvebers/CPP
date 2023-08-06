#include "BitcoinExchange.hpp"

#include <stdexcept>
#include <string>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string &database) : _input(database), _database("data.csv") {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &idk) {
	if (this == &idk) return *this;
	_bitcoinMap = idk._bitcoinMap;
	_database = idk._database;
	_input = idk._input;
	return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &idk)
	: _database(idk._database), _input(idk._input), _bitcoinMap(idk._bitcoinMap) {}

int BitcoinExchange::converToDays(std::string year, std::string month, std::string day) {
	int years = std::stoi(year);
	int months = std::stoi(month);
	int days = std::stoi(day);

    
	return (years);
}

void BitcoinExchange::fillTheMap() {
	int cnt = 2;
	std::string line;
	std::ifstream inputFile(_database);
	getline(inputFile, line);
	while (getline(inputFile, line)) {
		std::string year = line.substr(0, 4);
		std::string month = line.substr(5, 2);
		std::string day = line.substr(8, 2);
		std::string value1 = line.substr(4, 1);
		std::string value2 = line.substr(7, 1);
		std::cout << value1 << value2 << std::endl;
		if (value1.compare("-") != 0 || value2.compare("-") != 0) {
			std::string errorString = "Input at line is incorrect " + std::to_string(cnt);
			throw std::logic_error(errorString);
		}
		std::cout << year << " " << month << " " << day << std::endl;
		cnt++;
	}
}

bool BitcoinExchange::checkFiles(std::string &fileName) {
	std::ifstream inputFile(fileName);
	return inputFile.good();
}

void BitcoinExchange::start() {
	if (!checkFiles(_database)) throw std::runtime_error("can not opern database");
	if (!checkFiles(_input)) throw std::runtime_error("can not opern input");
	fillTheMap();
}