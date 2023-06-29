/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:34:29 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/29 21:11:24 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm *Intern::createShrubberyCreationForm(const std::string &target) const{
	std::cout << "The Problem Maker Intern Makes the bloody ShrubberyCreationForm" << std::endl;
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string &target) const{
	std::cout << "The Problem Maker Intern Makes the bloody ShrubberyCreationForm" << std::endl;
	return new PresidentialPardonForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target) const{
	std::cout << "The Problem Maker Intern Makes the bloody ShrubberyCreationForm" << std::endl;
	return new RobotomyRequestForm(target);
}

Intern::Intern() {
	std::cout << "Problem Intern has been created" << std::endl;
}

const char *Intern::FormNotFound::what() const throw() { return "Problem Document Not Found Problem!"; }

Intern::~Intern() { std::cout << "Intern Problem Destroyed " << std::endl; }

Intern::Intern(const Intern &idk) {
	std::cout << "Intern Porblem copy has been made" << std::endl;
	(void)idk;	// compilation trash i **** life please help me
}

Intern &Intern::operator=(const Intern &idk) {
	if (this == &idk) return *this;
	std::cout << "Intern Problem has been coppied" << std::endl;
	return *this;
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) const {
	int problem;
	const char *problems[] = {"ShrubberyCreationForm", "RobotomyRequestForm",
							  "PresidentialPardonForm"};

	problem = 0;
	while (problem < 3 && name.compare(problems[problem]) != 0) problem++;
	switch (problem) {
		case 0:
			return(createShrubberyCreationForm(target));
			break;
		case 1:
			return(createRobotomyRequestForm(target));
			break;
		case 2:
			return(createPresidentialPardonForm(target));
			break;
		default:
			throw FormNotFound();
			break;
	}
	return (nullptr);
}