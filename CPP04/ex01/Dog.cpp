/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:49:33 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/13 14:20:21 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	_brain = new Brain();
	std::cout << "Dog found" << std::endl;
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog lost" << std::endl;
}

Dog &Dog::operator=(const Dog &dog) {
	if (this == &dog) return *this;
	std::cout << "Dog coppied" << std::endl;
	Animal::operator=(dog);
	return *this;
}

Dog::Dog(const Animal &Dog) : Animal(Dog) { std::cout << "Dog copy Found" << std::endl; }

void Dog::makeSound() const { std::cout << "Vau Vau" << std::endl; }