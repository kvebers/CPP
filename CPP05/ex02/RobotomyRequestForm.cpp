/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:35:48 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/28 12:18:39 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("Robotomy Request Form", 45, 72), _target(target) {
	std::cout << "Problem  robot has been created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request Form", 45, 72), _target("Problem") {
	std::cout << "Problem robot has been created" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Robot Problem Destroyed " << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &idk)
	: _target(idk._target), AForm(idk) {
	std::cout << "Robot copy has been made" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &idk) {
	if (this == &idk) return *this;
	_target = idk._target;
	AForm::operator=(idk);
	std::cout << "Robot assigment opperator has been lunched" << std::endl;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &execute) const {
	if (getSigned() == false) throw AForm::NotSignedException();
	if (execute.getGrade() > getGradeToExecute()) throw AForm::GradeTooLowException();
	std::cout << "What did the drill say" << std::endl;
	std::cout << "DR DR DRRR DRRRR DRRRR DRRR DRRRR" << std::endl;
	if (rand() % 2 == 0)
		std::cout << _target << "has been robotomized sucesfully" << std::endl;
	else
		std::cout << _target << "has been robotomized unsucesfully" << std::endl;
}
