/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:35:53 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/25 12:53:01 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shruberry Creation Form", 145, 137), _target("Default") {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("Shruberry Creation Form", 145, 137), _target(target) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &idk) {
	if (this == &idk) return *this;
	_target = idk._target;
	AForm::operator=(idk);
	return *this;
}

void execute(Bureaucrat const &execute) {}
