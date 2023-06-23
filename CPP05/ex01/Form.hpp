/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:12:48 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/23 14:03:54 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form {
   public:
	// ORTHODOX STUFF
	Form();
	~Form();
	Form &operator=(const Form &word_i_can_spell);
	Form(const Form &word_i_can_spell);
	Form(const std::string name, const int execute, const int sign);
	//getters and setters
	const std::string &getName() const;
	const int getGradeToSign() const;
	const int getGradeToExecute() const;
	const bool getSigned() const;
	//functions
	void beSigned(const Bureaucrat &word_i_can_spell);

	class GradeTooLowException : public std::exception {
	   public:
		const char *what() const throw();
	};
	class GradeTooHighException : public std::exception {
	   public:
		const char *what() const throw();
	};

   private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;
};

std::ostream &operator<<(std::ostream &os, const Form &word_i_can_spell);

#endif