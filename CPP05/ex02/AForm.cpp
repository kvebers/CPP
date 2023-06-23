/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:12:45 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/23 13:50:46 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _gradeToExecute(100), _gradeToSign(100), _signed(false) {
	std::cout << "Problem Document" << std::endl;
}

AForm::~AForm() { std::cout << "No Document Problem" << std::endl; }

AForm::AForm(const AForm &word_i_can_spell)
	: _name(word_i_can_spell._name),
	  _gradeToExecute(word_i_can_spell._gradeToExecute),
	  _gradeToSign(word_i_can_spell._gradeToSign),
	  _signed(word_i_can_spell._signed) {}

AForm &AForm::operator=(const AForm &word_i_can_spell) {
	if (this == &word_i_can_spell) return *this;
	std::cout << "Assigment Document Problem" << std::endl;
	_signed = word_i_can_spell._signed;
	return *this;
}

AForm::AForm(const std::string name, const int execute, const int sign)
	: _name(name), _signed(false), _gradeToExecute(execute), _gradeToSign(sign) {
	if (execute < 1 || sign < 1)
		throw GradeTooHighException();
	else if (execute > 150 || sign > 150)
		throw GradeTooLowException();
	std::cout << "Problem Document" << std::endl;
}

// getters and setters
const std::string &AForm::getName() const { return _name; }

const int AForm::getGradeToExecute() const { return _gradeToExecute; }

const int AForm::getGradeToSign() const { return _gradeToExecute; }

const bool AForm::getSigned() const { return _signed; }

// functions

void AForm::beSigned(const Bureaucrat &word_i_can_spell) {
	if (_gradeToSign < word_i_can_spell.getGrade())
		throw GradeTooLowException();
	else
		_signed = true;
}

// exceptions

const char *AForm::GradeTooHighException::what() const throw() { return "Grade is too high!"; }

const char *AForm::GradeTooLowException::what() const throw() { return "Grade is too low!"; }

// ostream overide
std::ostream &operator<<(std::ostream &os, const AForm &AForm) {
	os << "Name: " << AForm.getName() << ", Grade To Execute: " << AForm.getGradeToExecute()
	   << "Grade to Sign: " << AForm.getGradeToSign() << "Is signed: " << AForm.getSigned();
	return os;
}