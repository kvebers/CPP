/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:35:56 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/28 09:35:21 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
   public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &idk);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &idk);

	class CanNotOpenFile : public std::exception {
	   public:
		const char *what() const throw();
	};
	void execute(Bureaucrat const &execute) const;

   private:
	std::string _target;
};

#endif
