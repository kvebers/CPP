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
	static int months[12];

   private:
	std::map<int, double> _bitcoinMap;
	void fillTheMap();
	std::string _database;
	bool checkFiles(std::string &fileName);
	int converToDays(int years, int months, int days);
	int add_months(int month, int years);
	void checkInput(int years, int month, int days, int cnt);
	int getDate(std::string &line, int cnt);
	void test();
};

#endif