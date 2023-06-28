/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:35:53 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/28 12:44:22 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shruberry Creation Peoblem", 137, 145), _target("Default") {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("Shruberry Creation Problem", 137, 145), _target(target) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &idk)
	: _target(idk._target), AForm(idk) {
	std::cout << "Berry has been copied" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &idk) {
	if (this == &idk) return *this;
	_target = idk._target;
	AForm::operator=(idk);
	std::cout << "Berry assigment opperator" << std::endl;
	return *this;
}

const char *ShrubberyCreationForm::CanNotOpenFile::what() const throw() {
	return "Failed to open the blody file file";
}

void ShrubberyCreationForm::execute(Bureaucrat const &execute) const {
	if (getSigned() == false) throw AForm::NotSignedException();
	if (execute.getGrade() > getGradeToExecute()) throw AForm::GradeTooLowException();
	std::ofstream file(_target + "_shrubbery");
	if (file.is_open()) {
		file << " " << std::endl
			 << "  ,d                                       " << std::endl
			 << "  88                                       " << std::endl
			 << "PROBLEM 8b,dPPYba,  ,adPPYba,  ,adPPYba,   " << std::endl
			 << "  88    88P     Y8 a8P_____88 a8P_____88   " << std::endl
			 << "  88    88         8PP======= 8PP=======   " << std::endl
			 << "  88,   88          8b,   ,aa  8b,   ,aa   " << std::endl
			 << "   Y888 88            Ybbd8     Ybbd8a     " << std::endl;
		file.close();
		std::cout << "The Document Has been executed by " << execute.getName() << std::endl;
	} else {
		throw CanNotOpenFile();
	}
}
