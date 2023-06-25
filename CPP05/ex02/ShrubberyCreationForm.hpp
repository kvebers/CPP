/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:35:56 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/25 12:45:54 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : AForm {
   public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &idk);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &idk);

	void execute(Bureaucrat const &execute) const;

   private:
	std::string _target;
};

#endif
