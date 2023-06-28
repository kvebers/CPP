/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:35:51 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/28 12:04:28 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
   public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &idk);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &idk);

	void execute(Bureaucrat const &execute) const;

   private:
	std::string _target;
};

#endif