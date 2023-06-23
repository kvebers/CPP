/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:55:57 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/22 12:11:49 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

#include "Bureaucrat.hpp"

int main() {
	{
		// Check for the copy assigment opperators
		std::cout << std::endl << "TEST1" << std::endl << std::endl;
		try {
			Bureaucrat test("test", 1);
			Bureaucrat test1(test);
			Bureaucrat test2("test2", 2);
			std::cout << test << std::endl;
			std::cout << test1 << std::endl;
			std::cout << test2 << std::endl;
			test2 = test1;
			std::cout << test2 << std::endl;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "TEST2" << std::endl << std::endl;
		try {
			Bureaucrat test("test", 1);
			Bureaucrat test1("test", 0);
			Bureaucrat test2("test", 151);
			Bureaucrat test3("test", 150);
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		try {
			Bureaucrat test2("test", 151);
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "TEST3" << std::endl << std::endl;
		Bureaucrat test("test", 1);
		std::cout << test << std::endl;
		try {
			test.incrementGrade();
			std::cout << test << std::endl;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "TEST4" << std::endl << std::endl;
		Bureaucrat test("test", 150);
		std::cout << test << std::endl;
		try {
			test.decrementGrade();
			std::cout << test << std::endl;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}