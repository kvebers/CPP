/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:55:57 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/29 21:14:59 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

#include "AForm.hpp"
#include "Intern.hpp"

int main() {
	{
		std::cout << std::endl << "TEST 1" << std::endl << std::endl;
		Intern intern;
		Bureaucrat bureaucrat;

		try {
			AForm *shrubberyProblem = intern.makeForm("ShrubberyCreationForm", "problem");
			bureaucrat.signForm(*shrubberyProblem);
			delete shrubberyProblem;
		} catch (const std::exception &e) {
			std::cout << "Problem happened: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "TEST 2" << std::endl << std::endl;
		Intern intern;
		Bureaucrat bureaucrat;

		try {
			AForm *shrubberyProblem = intern.makeForm("RobotomyRequestForm", "problem");
			bureaucrat.signForm(*shrubberyProblem);
			delete shrubberyProblem;
		} catch (const std::exception &e) {
			std::cout << "Problem happened: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "TEST 3" << std::endl << std::endl;
		Intern intern;
		Bureaucrat bureaucrat;

		try {
			AForm *shrubberyProblem = intern.makeForm("PresidentialPardonForm", "problem");
			bureaucrat.signForm(*shrubberyProblem);
			delete shrubberyProblem;
		} catch (const std::exception &e) {
			std::cout << "Problem happened: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "TEST 4" << std::endl << std::endl;
		Intern intern;
		Bureaucrat bureaucrat;

		try {
			AForm *shrubberyProblem = intern.makeForm("PROBLEM", "problem");
			bureaucrat.signForm(*shrubberyProblem);
			delete shrubberyProblem;
		} catch (const std::exception &e) {
			std::cout << "Problem happened: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "TEST 5" << std::endl << std::endl;
		Intern intern;
		Bureaucrat bureaucrat;

		try {
			AForm *shrubberyProblem = intern.makeForm("", "");
			bureaucrat.signForm(*shrubberyProblem);
			delete shrubberyProblem;
		} catch (const std::exception &e) {
			std::cout << "Problem happened: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "NO PROBLEMS, Life is gut" << std::endl << std::endl;
}
