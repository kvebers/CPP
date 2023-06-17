/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:49:25 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/17 17:24:24 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Default") {
	std::cout << "Animal: \"" << _type << "\" Created" << std::endl;
}

Animal::Animal(std::string name) : _type(name) {
	std::cout << "Animal: \"" << _type << "\" Created" << std::endl;
}

Animal::~Animal() { std::cout << "Animal disapeared" << std::endl; }

Animal::Animal(const Animal &animal) : _type(animal._type) {
	std::cout << "Animal copy made" << std::endl;
}

Animal &Animal::operator=(const Animal &animal) {
	if (this == &animal) return *this;
	std::cout << "Animal Copy Assigned" << std::endl;
	_type = animal._type;
	return *this;
}

// The functions that need to be implemented
// Also virtual can be implemented only in class specification that neet...

std::string Animal::getType() const { return _type; }