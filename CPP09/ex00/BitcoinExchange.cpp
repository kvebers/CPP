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

void BitcoinExchange::checkInput(int years, int month, int days, int cnt) {
	std::string error = "wrong date at line " + std::to_string(cnt);
	if (years < 2009 || years > 2023) throw std::logic_error(error);
	if (month < 1 || month > 12) throw std::logic_error(error);
	if (years % 4 == 0 && month == 2 && days > 0 && days < 30) return;
	if (days < 1 || days > months[month - 1]) throw std::logic_error(error);
}

int BitcoinExchange::converToDays(int years, int months, int days) {
	int date = years * 365 + years / 4 + add_months(months, years) + days;
	return date;
}

int BitcoinExchange::getDate(std::string &line, int cnt) {
	std::string errorString = "Input at line is incorrect " + std::to_string(cnt);
	if (line.size() < 12) throw std::logic_error("wrong size input");
	std::string year = line.substr(0, 4);
	std::string month = line.substr(5, 2);
	std::string day = line.substr(8, 2);
	int years = std::stoi(year);
	int months = std::stoi(month);
	int days = std::stoi(day);
	if (month[1] > '9' || month[1] < '0') throw std::logic_error(errorString);
	if (day[1] > '9' || day[1] < '0') throw std::logic_error(errorString);
	std::string value1 = line.substr(4, 1);
	std::string value2 = line.substr(7, 1);
	if (value1.compare("-") != 0 || value2.compare("-") != 0) throw std::logic_error(errorString);
	checkInput(years, months, days, cnt);
	return (converToDays(years, months, days));
}

void BitcoinExchange::fillTheMap() {
	int cnt = 2;
	std::string line;
	std::ifstream inputFile(_database);
	getline(inputFile, line);
	while (getline(inputFile, line)) {
		std::string errorString = "Input at line is incorrect " + std::to_string(cnt);
		double value = std::stod(line.substr(11, line.size()));
		if (value == 0 && line[11] != '0') throw std::logic_error(errorString);
		_bitcoinMap.insert(std::make_pair(getDate(line, cnt), value));
		cnt++;
	}
}

bool BitcoinExchange::checkFiles(std::string &fileName) {
	std::ifstream inputFile(fileName);
	return inputFile.good();
}

void BitcoinExchange::test() {
	std::map<int, double>::iterator it;
	for (it = _bitcoinMap.end(); it != _bitcoinMap.begin(); it--) {
		std::cout << it->first << " -> " << it->second << std::endl;
	}
}

void BitcoinExchange::start() {
	if (!checkFiles(_database)) throw std::runtime_error("can not opern database");
	if (!checkFiles(_input)) throw std::runtime_error("can not opern input");
	fillTheMap();
	test();
}