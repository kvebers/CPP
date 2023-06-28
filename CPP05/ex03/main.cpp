/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:55:57 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/28 13:35:24 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	{
		std::cout << std::endl << "TEST1" << std::endl << std::endl;
		Bureaucrat bureaucrat("PROBLEM", 137);
		ShrubberyCreationForm form("tree");
		try {
			form.execute(bureaucrat);
		} catch (const std::exception &e) {
			std::cout << "Problem occurred: " << e.what() << std::endl;
		}
		try {
			bureaucrat.signForm(form);
		} catch (const std::exception &e) {
			std::cout << "Problem occurred: " << e.what() << std::endl;
		}
		try {
			form.execute(bureaucrat);
		} catch (const std::exception &e) {
			std::cout << "Problem occurred: " << e.what() << std::endl;
		}
		system("cat tree_shrubbery");
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << "TEST2" << std::endl << std::endl;
		Bureaucrat bureaucrat("PROBLEM", 137);
		AForm *form = new ShrubberyCreationForm();
		try {
			bureaucrat.signForm(*form);
		} catch (const std::exception &e) {
			std::cout << "Problem occurred: " << e.what() << std::endl;
		}
		try {
			form->execute(bureaucrat);
		} catch (const std::exception &e) {
			std::cout << "Problem occurred: " << e.what() << std::endl;
		}
		system("cat Default_shrubbery");
		std::cout << std::endl;
		delete form;
	}
	{
		std::cout << std::endl << "TEST3" << std::endl << std::endl;
		Bureaucrat bureaucrat("PROBLEM", 4);
		AForm *form = new PresidentialPardonForm();
		try {
			bureaucrat.signForm(*form);
		} catch (const std::exception &e) {
			std::cout << "Problem occurred: " << e.what() << std::endl;
		}
		try {
			form->execute(bureaucrat);
		} catch (const std::exception &e) {
			std::cout << "Problem occurred: " << e.what() << std::endl;
		}
		delete form;
	}
	{
		std::cout << std::endl << "TEST4" << std::endl << std::endl;
		Bureaucrat bureaucrat("PROBLEM", 4);
		AForm *form = new RobotomyRequestForm();
		try {
			bureaucrat.signForm(*form);
		} catch (const std::exception &e) {
			std::cout << "Problem occurred: " << e.what() << std::endl;
		}
		try {
			form->execute(bureaucrat);
		} catch (const std::exception &e) {
			std::cout << "Problem occurred: " << e.what() << std::endl;
		}
		delete form;
	}
}
