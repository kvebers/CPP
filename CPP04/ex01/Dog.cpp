/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:49:33 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/17 15:32:55 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain() { std::cout << "Dog found" << std::endl; }

Dog::~Dog() { std::cout << "Dog lost" << std::endl; }

Dog &Dog::operator=(const Dog &dog) {
	if (this == &dog) return *this;
	std::cout << "Dog coppied" << std::endl;
	Animal::operator=(dog);
	_brain = dog._brain;
	return *this;
}

Dog::Dog(const Animal &Dog) : Animal(Dog), _brain() { std::cout << "Dog copy Found" << std::endl; }

void Dog::makeSound() const { std::cout << "Vau Vau" << std::endl; }

void Dog::setIdea(int location, const std::string &idea) { _brain.setIdea(location, idea); }

void Dog::printIdea(int location) {
	std::cout << "Idea: ";
	_brain.printIdea(location);
}
