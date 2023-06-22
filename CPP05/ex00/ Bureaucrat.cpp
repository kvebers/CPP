/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Bureaucrat.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:56:32 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/21 15:12:36 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(100) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &word_i_can_spell) {
	_name = word_i_can_spell._name;
	_grade = word_i_can_spell._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &word_i_can_spell) {
    if (this == &word_i_can_spell)
        return  *this;
    _name = word_i_can_spell._name;
    _grade = word_i_can_spell._grade;
    return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
    
} 