/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:34:58 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/28 12:31:52 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("Robotomy Request Form", 5, 25), _target(target) {
	std::cout << "Problem  robot has been created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Robotomy Request Form", 5, 25), _target("Problem") {
	std::cout << "Problem robot has been created" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Robot Problem Destroyed " << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &idk)
	: _target(idk._target), AForm(idk) {
	std::cout << "Robot copy has been made" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &idk) {
	if (this == &idk) return *this;
	_target = idk._target;
	AForm::operator=(idk);
	std::cout << "Robot assigment opperator has been lunched" << std::endl;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &execute) const {
	if (getSigned() == false) throw AForm::NotSignedException();
	if (execute.getGrade() > getGradeToExecute()) throw AForm::GradeTooLowException();
	std::cout << "Informs that " << _target << " has been pardoned by Zaphod Beeblebrox. "
			  << std::endl;
}