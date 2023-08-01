/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:01:20 by kvebers           #+#    #+#             */
/*   Updated: 2023/08/01 19:08:13 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cstdlib>
#include <iomanip>
#include <ios>
#include <limits>
#include <locale>

// ORTHODOX STUFF
ScalarConverter::ScalarConverter() {
	std::cout << "IDK wHY WE NEED THIS IN THIS EXECERSISE" << std::endl;
}
ScalarConverter::~ScalarConverter() {
	std::cout << "IDK wHY WE NEED THIS IN THIS EXECERSISE" << std::endl;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &idk) {
	if (this != &idk) return *this;
	std::cout << "IDK wHY WE NEED THIS IN THIS EXECERSISE" << std::endl;
	return *this;
}

ScalarConverter::ScalarConverter(const ScalarConverter &idk) {
	std::cout << "IDK wHY WE NEED THIS IN THIS EXECERSISE" << std::endl;
}

// MY AMAZING CUSTOM EXCEPTION FUNCTION
const char *ScalarConverter::CustomException::what() const throw() { return message.c_str(); }
ScalarConverter::CustomException::CustomException(const std::string &word) : message(word) {}
ScalarConverter::CustomException::~CustomException() throw() {}

// OTHER STUFF

void ScalarConverter::convertChar(const std::string &input) {
	if (input.length() == 1 && std::isdigit(input[0]) == false) {
		if (std::isprint(input[0])) {
			std::cout << "char : "
					  << "'" << input[0] << "'" << std::endl;
		} else if (input[0] < 0 || input[0] > 127) {
			std::cout << "char : impossible " << std::endl;
		} else
			std::cout << "char : Non Displayable " << std::endl;
		std::cout << "int : " << static_cast<int>(input[0]) << std::endl
				  << std::fixed << std::setprecision(1)
				  << "float : " << static_cast<float>(input[0]) << "f" << std::endl
				  << "double : " << static_cast<double>(input[0]) << std::endl;
	} else
		throw CustomException("impossible");
}

void ScalarConverter::convertDouble(const std::string &input) {
	double number = std::strtod(input.c_str(), 0);
	if (number == 0 && input[0] != '0') throw CustomException("impossible");
	if (number < std::numeric_limits<double>::min() || number > std::numeric_limits<double>::max())
		throw CustomException("impossible");

	if (std::isprint(number)) {
		std::cout << "char : "
				  << "'" << static_cast<char>(number) << "'" << std::endl;
	} else if (number < 0 || number > 127) {
		std::cout << "char : impossible " << std::endl;
	} else
		std::cout << "char : Non Displayable " << std::endl;
	if (number > std::numeric_limits<int>::max() || number < std::numeric_limits<int>::min() ||
		input.compare("nan") == 0)
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(number) << std::endl;
	if (number > std::numeric_limits<float>::max() || number < std::numeric_limits<float>::min())
		std::cout << "float : impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "float : " << static_cast<float>(number)
				  << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double : " << number << std::endl;
}

void ScalarConverter::convertFloat(const std::string &input) {
	double dnumber = std::strtod(input.c_str(), 0);
	if (dnumber < std::numeric_limits<float>::min() || dnumber > std::numeric_limits<float>::max())
		throw CustomException("impossible");
	if (input[input.length() - 1] != 'f' && input[input.length() - 1] != 'F')
		throw CustomException("impossible");
	float number = std::strtof(input.c_str(), 0);
	if (number == 0 && input[0] != '0') throw CustomException("impossible");
	if (std::isprint(number)) {
		std::cout << "char : "
				  << "'" << static_cast<char>(number) << "'" << std::endl;
	} else if (number < 0 || number > 127) {
		std::cout << "char : impossible " << std::endl;
	} else
		std::cout << "char : Non Displayable " << std::endl;
	if (dnumber > std::numeric_limits<int>::max() || dnumber < std::numeric_limits<int>::min() ||
		input.compare("nanf") == 0)
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(number) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float : " << number << "f" << std::endl
			  << "double : " << static_cast<double>(number) << std::endl;
}

void ScalarConverter::convertInt(const std::string &input) {
	double dnumber = std::strtod(input.c_str(), 0);
	if (dnumber < std::numeric_limits<int>::min() || dnumber > std::numeric_limits<int>::max())
		throw CustomException("impossible");
	if (input[input.length() - 1] == 'f' || input[input.length() - 1] == 'F')
		throw CustomException("impossible");
	int number = std::atoi(input.c_str());
	if (number == 0 && input[0] != '0') throw CustomException("impossible");
	if (std::isprint(number)) {
		std::cout << "char : "
				  << "'" << static_cast<char>(number) << "'" << std::endl;
	} else if (number < 0 || number > 127) {
		std::cout << "char : impossible " << std::endl;
	} else
		std::cout << "char : Non Displayable " << std::endl;
	std::cout << "int : " << number << std::endl
			  << std::fixed << std::setprecision(1) << "float : " << static_cast<float>(number)
			  << "f" << std::endl
			  << "double : " << static_cast<double>(number) << std::endl;
}

void ScalarConverter::convert(const std::string &input) {
	std::string charException;
	std::string doubleException;
	std::string floatException;
	std::string intException;

	if (input.length() == 0) CustomException("Input is empty");
	if (input.compare("+inf") == 0 || input.compare("+inff") == 0) {
		std::cout << "char : impossible" << std::endl
				  << "int : impossible" << std::endl
				  << "float : inff" << std::endl
				  << "doble : inf " << std::endl;
		return;
	}
	if (input.compare("-inf") == 0 || input.compare("-inff") == 0) {
		std::cout << "char : impossible" << std::endl
				  << "int : impossible" << std::endl
				  << "float : -inff" << std::endl
				  << "doble : -inf " << std::endl;
		return;
	}
	try {
		convertChar(input);
	} catch (const std::exception &e) {
		charException = e.what();
		try {
			convertInt(input);
		} catch (const std::exception &e) {
			intException = e.what();
			try {
				convertFloat(input);
			} catch (const std::exception &e) {
				floatException = e.what();
				try {
					convertDouble(input);
				} catch (const std::exception &e) {
					doubleException = e.what();
					if (doubleException.empty() == false)
						std::cout << "char : " << charException << std::endl
								  << "int : " << intException << std::endl
								  << "float : " << floatException << std::endl
								  << "double : " << doubleException << std::endl;
				}
			}
		}
	}
}
