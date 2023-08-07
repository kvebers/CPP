#include "BitcoinExchange.hpp"

#include <cctype>
#include <exception>
#include <stdexcept>

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
		double value = std::stod(line.substr(11, line.size() - 11));
		int date = getDate(line);
		if (value == 0 && line[11] != '0') throw std::logic_error(errorString);
		_bitcoinMap.insert(std::make_pair(date, value));
	}
}

bool BitcoinExchange::checkFiles(std::string &fileName) {
	std::ifstream inputFile(fileName);
	if (fileName.size() < 5) throw std::logic_error("incorrect file format");
	if (fileName[fileName.size() - 1] != 'v' || fileName[fileName.size() - 2] != 's' ||
		fileName[fileName.size() - 3] != 'c' || fileName[fileName.size() - 4] != '.')
		throw(std::logic_error("incorrect file format"));
	return inputFile.good();
}

float BitcoinExchange::getAmount(std::string &line) {
	if (line.size() < 13) throw std::logic_error("Error: No multiplayer input");
	if (line.size() > 24) throw std::logic_error("Error: Line too long");
	if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		throw std::logic_error("Error: bad spacing");
	std::string substring = line.substr(13, line.size() - 13);
	if (substring[0] == '-') throw std::logic_error("Can not have negative numbers");
	if (!std::isdigit(substring[0])) throw std::logic_error("Error: Bad input =>" + line);
	float floatMultiplayer = std::stof(substring);
	if (floatMultiplayer == 0 && line.size() > 13 && line[13] != 0)
		throw std::logic_error("Error: Bad input =>" + line);
	if (floatMultiplayer < 0) throw std::logic_error("Value it too low");
	if (floatMultiplayer > 1000) throw std::logic_error("value is too high");
	return (floatMultiplayer);
}

void BitcoinExchange::analyzeTheData() {
	std::string line;
	std::ifstream inputFile(_input);
	getline(inputFile, line);
	if (line.compare("date | value") != 0) throw std::logic_error("Error: wrong data input");
	while (getline(inputFile, line)) {
		try {
			std::map<int, double>::reverse_iterator it;
			int date = getDate(line);
			float multiplay = getAmount(line);
			for (it = _bitcoinMap.rbegin(); it != _bitcoinMap.rend(); it++) {
				if (date >= it->first) {
					std::cout << line.substr(0, 10) << " => " << multiplay * it->second
							  << std::endl;
					break;
				}
			}
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}

void BitcoinExchange::start() {
	if (!checkFiles(_database)) throw std::runtime_error("Error: can not open database");
	if (!checkFiles(_input)) throw std::runtime_error("Error: can not open input");
	fillTheMap();
	analyzeTheData();
}