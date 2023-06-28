/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:12:48 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/23 14:03:54 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>

#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm {
   public:
	// ORTHODOX STUFF
	AForm();
	virtual ~AForm();
	AForm &operator=(const AForm &word_i_can_spell);
	AForm(const AForm &word_i_can_spell);
	AForm(const std::string name, const int execute, const int sign);
	//getters and setters
	const std::string &getName() const;
	const int getGradeToSign() const;
	const int getGradeToExecute() const;
	const bool getSigned() const;
	//functions
	void beSigned(const Bureaucrat &word_i_can_spell);
	virtual void execute(Bureaucrat const &word_i_can_spell) const = 0;

	class GradeTooLowException : public std::exception {
	   public:
		const char *what() const throw();
	};
	class GradeTooHighException : public std::exception {
	   public:
		const char *what() const throw();
	};

	class NotSignedException : public std::exception {
	   public:
		const char *what() const throw();
	};

   private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;
};

std::ostream &operator<<(std::ostream &os, const AForm &word_i_can_spell);

#endif