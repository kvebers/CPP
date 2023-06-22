/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:56:17 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/21 15:06:02 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
   public:
   //ORTHODOX STUFF
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &word_i_can_spell);
	Bureaucrat(const Bureaucrat &word_i_can_spell);
    Bureaucrat(std::string name, int grade);

   private:
	std::string _name;
	int _grade;
};

#endif