/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:01:20 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/30 12:42:53 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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

// OTHER STUFF

void ScalarConverter::convertChar(const std::string &input) {
	if (input.length() == 1) {
		if (std::isprint(input[0]))
			std::cout << "char: " << input[0] << std::endl;
		else
			std::cout << "char: impossible " << std::endl;
	} else {
		std::cout << "char: impossible" << std::endl;
	}
}

void ScalarConverter::convertDouble(const std::string &input) {
	try {
		std::cout << "double: " << std::fixed << std::setprecision(1)
				  << static_cast<double>(std::stod(input)) << std::endl;
	} catch (const std::exception &e) {
		std::cout << "double: impossible " << std::endl;
	}
}

void ScalarConverter::convertFloat(const std::string &input) {
	try {
		std::cout << "float: " << std::fixed << std::setprecision(1)
				  << static_cast<float>(std::stof(input)) << "f" << std::endl;
	} catch (const std::exception &e) {
		std::cout << "float: impossible " << std::endl;
	}
}

void ScalarConverter::convertInt(const std::string &input) {
	try {
		std::cout << "int: " << static_cast<int>(std::stoi(input)) << std::endl;
	} catch (const std::exception &e) {
		std::cout << "int: impossible " << std::endl;
	}
}

void ScalarConverter::convert(const std::string &input) {
	convertChar(input);
	convertInt(input);
	convertFloat(input);
	convertDouble(input);
}
