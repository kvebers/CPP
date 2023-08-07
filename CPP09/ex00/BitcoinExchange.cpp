#include "BitcoinExchange.hpp"

#include <iterator>
#include <stdexcept>
#include <string>
#include <utility>

int BitcoinExchange::months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

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

int BitcoinExchange::add_months(int month, int years) {
	int sum = 0;
	for (int cnt = 0; cnt < month - 1; cnt++) {
		sum += months[cnt];
	}
	if (month - 1 > 1 && years % 4 == 0) sum++;
	return (sum);
}

void BitcoinExchange::checkInput(int years, int month, int days, std::string &line) {
	std::string errorString = "Errror: Bad Input => " + line.substr(0, 10);
	if (years < 2009 || years > 2023) throw std::logic_error(errorString);
	if (month < 1 || month > 12) throw std::logic_error(errorString);
	if (years % 4 == 0 && month == 2 && days > 0 && days < 30) return;
	if (days < 1 || days > months[month - 1]) throw std::logic_error(errorString);
}

int BitcoinExchange::converToDays(int years, int months, int days) {
	int date = years * 365 + years / 4 + add_months(months, years) + days;
	return date;
}

int BitcoinExchange::getDate(std::string &line) {
	if (line.size() < 12) throw std::logic_error("Error: bad input => " + line);
	std::string year = line.substr(0, 4);
	std::string month = line.substr(5, 2);
	std::string day = line.substr(8, 2);
	int years = std::stoi(year);
	int months = std::stoi(month);
	int days = std::stoi(day);
	std::string errorString = "Errror: Bad Input => " + line.substr(0, 10);
	if (month[1] > '9' || month[1] < '0') throw std::logic_error(errorString);
	if (day[1] > '9' || day[1] < '0') throw std::logic_error(errorString);
	std::string value1 = line.substr(4, 1);
	std::string value2 = line.substr(7, 1);
	if (value1.compare("-") != 0 || value2.compare("-") != 0)
		throw std::logic_error("Error: Not Valid seperator -");
	checkInput(years, months, days, line);
	return (converToDays(years, months, days));
}

void BitcoinExchange::fillTheMap() {
	std::string line;
	std::ifstream inputFile(_database);
	getline(inputFile, line);
	while (getline(inputFile, line)) {
		std::string errorString = "Error: Database inpit incorrect: " + line;
		double value = std::stod(line.substr(11, line.size()));
		if (value == 0 && line[11] != '0') throw std::logic_error(errorString);
		_bitcoinMap.insert(std::make_pair(getDate(line), value));
	}
}

bool BitcoinExchange::checkFiles(std::string &fileName) {
	std::ifstream inputFile(fileName);
	return inputFile.good();
}

int BitcoinExchange::getAmount(std::string &line) {
	if (line.size() < 13) throw std::logic_error("Error: No integer input");
	if (line.size() > 23) throw std::logic_error("Error: Line too long");
	if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		throw std::logic_error("Error: bad spacing");
	return 1;
}

void BitcoinExchange::analyzeTheData() {
	std::string line;
	std::ifstream inputFile(_input);
	getline(inputFile, line);
	if (line.compare("date | value") != 0) throw std::logic_error("Error: wrong data input");
	while (getline(inputFile, line)) {
		std::map<int, double>::iterator it;
		try {
			int date = getDate(line);
			int multiplay = getAmount(line);
			for (it = _bitcoinMap.end(); it != _bitcoinMap.begin(); it--) {
				if (date >= it->first) {
					std::cout << line.substr(0, 10) << std::endl;
					break;
				}
			}
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}

void BitcoinExchange::start() {
	if (!checkFiles(_database)) throw std::runtime_error("Error: can not opern database");
	if (!checkFiles(_input)) throw std::runtime_error("Error: can not opern input");
	fillTheMap();
	analyzeTheData();
}