/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:01:20 by kvebers           #+#    #+#             */
/*   Updated: 2023/08/01 14:36:07 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cstring>
#include <exception>
#include <iomanip>
#include <string>

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
	try {
		if (input.length() == 1) {
			if (std::isprint(input[0]))
				std::cout << "char: " << input[0] << std::endl;
			else
				std::cout << "char: impossible " << std::endl;
		} else {
			throw CustomException("Char ain't possible");
		}
	} catch (const std::exception &e) {
	}
}

void ScalarConverter::convertDouble(const std::string &input) {
	std::cout << "double: " << std::fixed << std::setprecision(1)
			  << static_cast<double>(std::stod(input)) << std::endl;
}

void ScalarConverter::convertFloat(const std::string &input) {
	std::cout << "float: " << std::fixed << std::setprecision(1)
			  << static_cast<float>(std::stof(input)) << "f" << std::endl;
}

void ScalarConverter::convertInt(const std::string &input) {
	std::cout << "int: " << static_cast<int>(std::stoi(input)) << std::endl;
}

void ScalarConverter::convert(const std::string &input) {
	try {convertChar(input);} catch (const std::exception &e) {
		try { convertDouble(input); } catch (const std::exception &e) {
			try { convertFloat(input); } catch (const std::exception &e) {
				try { convertInt(input); } catch (const std::exception &e) {
		

				}
			}
		}
	}
}
