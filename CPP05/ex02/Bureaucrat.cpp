/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:32:42 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/28 12:05:56 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(100) { std::cout << "Problem" << std::endl; }

Bureaucrat::~Bureaucrat() { std::cout << "No Problem" << std::endl; }

Bureaucrat::Bureaucrat(const Bureaucrat &word_i_can_spell)
	: _name(word_i_can_spell._name), _grade(word_i_can_spell._grade) {
	std::cout << "Copy Problem" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &word_i_can_spell) {
	if (this == &word_i_can_spell) return *this;
	std::cout << "Assigment Problem" << std::endl;
	_grade = word_i_can_spell._grade;
	return *this;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
	std::cout << "Problem" << std::endl;
}

const std::string &Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

const char *Bureaucrat::GradeTooHighException::what() const throw() { return "Grade is too high!"; }

const char *Bureaucrat::GradeTooLowException::what() const throw() { return "Grade is too low!"; }

void Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1) throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150) throw GradeTooLowException();
	_grade++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &word_i_can_spell) {
	os << "Name: " << word_i_can_spell.getName() << ", Grade: " << word_i_can_spell.getGrade();
	return os;
}

void Bureaucrat::signForm(AForm &aform) {
	try {
		aform.beSigned(*this);
		std::cout << getName() << " signed " << aform.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cout << getName() << " Coulden't sign " << aform.getName() << " because " << e.what()
				  << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &aform) const {
	try {
		aform.execute(*this);
		std::cout << "Bureaucrat " << _name << "executed problem " << aform.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Bureaucrat " << _name << "could not execute the problem" << aform.getName()
				  << std::endl;
	}
}
