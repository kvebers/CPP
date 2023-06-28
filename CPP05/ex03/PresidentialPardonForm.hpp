/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:35:01 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/28 12:10:20 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
   public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &idk);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &idk);

	void execute(Bureaucrat const &execute) const;

   private:
	std::string _target;
};

#endif