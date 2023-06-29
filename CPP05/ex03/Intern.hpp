/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:34:42 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/29 20:58:59 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
   public:
	// ORTHIOOX
	Intern();
	Intern(const Intern &idk);
	~Intern();
	Intern &operator=(const Intern &idk);
	// function
	AForm *makeForm(const std::string &name, const std::string &target) const;

    class FormNotFound : public std::exception {
	   public:
		const char *what() const throw();
	};

   private:
	AForm *createShrubberyCreationForm(const std::string &taget) const;
	AForm *createRobotomyRequestForm(const std::string &taget) const;
	AForm *createPresidentialPardonForm(const std::string &taget) const;
};

#endif