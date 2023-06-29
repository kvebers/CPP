/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:34:29 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/28 15:29:01 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Problem Intern has been created" << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern Problem Destroyed " << std::endl;
}

Intern::Intern(const Intern &idk){
	std::cout << "Intern Porblem copy has been made" << std::endl;
	(void) idk; //compilation trash i **** life please help me
}

Intern &Intern::operator=(const Intern &idk) {
	if (this == &idk) return *this;
	std::cout << "Intern Problem has been coppied" << std::endl;
	return *this;
}