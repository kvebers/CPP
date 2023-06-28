/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:55:57 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/28 10:19:59 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	{
		std::cout << std::endl << "TEST1" << std::endl << std::endl;
		Bureaucrat bureaucrat("PROBLEM", 137);
		ShrubberyCreationForm form("tree");
		try {
			form.execute(bureaucrat);
		} catch (const std::exception& e) {
			std::cout << "Exception occurred: " << e.what() << std::endl;
		}
		try {
			bureaucrat.signForm(form);
		} catch (const std::exception& e) {
			std::cout << "Exception occurred: " << e.what() << std::endl;
		}
		try {
			form.execute(bureaucrat);
		} catch (const std::exception& e) {
			std::cout << "Exception occurred: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "TEST2" << std::endl << std::endl;
		Bureaucrat bureaucrat("PROBLEM", 137);
		AForm *form = new ShrubberyCreationForm();
		try
		{
			form->execute(bureaucrat);
		}
		catch (const std::exception &e)
		{
			std::cout << "Exception occurred: " << e.what() << std::endl;
		}
		delete form;
	}
}
