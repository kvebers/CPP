/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:49:22 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/17 16:53:53 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain() { std::cout << "Cat found" << std::endl; }

Cat::~Cat() { std::cout << "Cat lost" << std::endl; }

Cat &Cat::operator=(const Cat &cat) {
	if (this == &cat) return *this;
	std::cout << "Cat coppied" << std::endl;
	Animal::operator=(cat);
	_brain = cat._brain;
	return *this;
}

Cat::Cat(const Animal &cat) : Animal(cat), _brain() { std::cout << "Cat Copy Found" << std::endl; }

void Cat::makeSound() const { std::cout << "Ņauuu Ņauuu Ņauuu" << std::endl; }

void Cat::setIdea(int location, const std::string &idea) { _brain.setIdea(location, idea); }

void Cat::printIdea(int location) {
	std::cout << "Idea: ";
	_brain.printIdea(location);
}
