/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:55:57 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/23 14:06:48 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

#include "Bureaucrat.hpp"

int main() {
	{
		AForm form;
		Bureaucrat b;
		AForm form1;
		b.signForm(form);
		b.decrementGrade();
		std::cout << b << std::endl;
		b.signForm(form1);
		AForm form2("form", 101, 101);
		b.signForm(form2);
	}
}