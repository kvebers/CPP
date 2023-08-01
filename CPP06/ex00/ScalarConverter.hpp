/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 21:23:49 by kvebers           #+#    #+#             */
/*   Updated: 2023/08/01 14:23:47 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
   public:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &idk);
	ScalarConverter(const ScalarConverter &idk);
	static void convert(const std::string &input);

   private:
	static void convertChar(const std::string &input);
	static void convertDouble(const std::string &input);
	static void convertInt(const std::string &inpit);
	static void convertFloat(const std::string &input);

	class CustomException : public std::exception {
	   private:
		std::string message;

	   public:
		CustomException(const std::string &word);
		const char *what() const throw();
		virtual ~CustomException() throw();
	};
};

#endif