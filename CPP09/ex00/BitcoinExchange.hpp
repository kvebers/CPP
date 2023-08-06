#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

class BitcoinExchange {
   public:
	std::string _input;
	void start();
	BitcoinExchange();
	BitcoinExchange(std::string &database);
	BitcoinExchange &operator=(const BitcoinExchange &idk);
	BitcoinExchange(const BitcoinExchange &idk);
	~BitcoinExchange();

   private:
	std::map<int, double> _bitcoinMap;
	void fillTheMap();
	std::string _database;
	bool checkFiles(std::string &fileName);
	int converToDays(std::string year, std::string month, std::string day);
};

#endif