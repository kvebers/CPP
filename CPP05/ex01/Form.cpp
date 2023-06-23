/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:12:45 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/23 13:50:46 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _gradeToExecute(100), _gradeToSign(100), _signed(false) {
	std::cout << "Problem Document" << std::endl;
}

Form::~Form() { std::cout << "No Document Problem" << std::endl; }

Form::Form(const Form &word_i_can_spell)
	: _name(word_i_can_spell._name),
	  _gradeToExecute(word_i_can_spell._gradeToExecute),
	  _gradeToSign(word_i_can_spell._gradeToSign),
	  _signed(word_i_can_spell._signed) {}

Form &Form::operator=(const Form &word_i_can_spell) {
	if (this == &word_i_can_spell) return *this;
	std::cout << "Assigment Document Problem" << std::endl;
	_signed = word_i_can_spell._signed;
	return *this;
}

Form::Form(const std::string name, const int execute, const int sign)
	: _name(name), _signed(false), _gradeToExecute(execute), _gradeToSign(sign) {
	if (execute < 1 || sign < 1)
		throw GradeTooHighException();
	else if (execute > 150 || sign > 150)
		throw GradeTooLowException();
	std::cout << "Problem Document" << std::endl;
}

const std::string &Form::getName() const { return _name; }

const int Form::getGradeToExecute() const { return _gradeToExecute; }

const int Form::getGradeToSign() const { return _gradeToExecute; }

const bool Form::getSigned() const { return _signed; }

void Form::beSigned(const Bureaucrat &word_i_can_spell) {
	if (_gradeToSign < word_i_can_spell.getGrade())
		throw GradeTooLowException();
	else
		_signed = true;
}

const char *Form::GradeTooHighException::what() const throw() { return "Grade is too high!"; }

const char *Form::GradeTooLowException::what() const throw() { return "Grade is too low!"; }

std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "Name: " << form.getName() << ", Grade To Execute: " << form.getGradeToExecute()
	   << "Grade to Sign: " << form.getGradeToSign() << "Is signed: " << form.getSigned();
	return os;
}