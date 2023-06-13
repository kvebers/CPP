/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:49:33 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/13 11:35:31 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") { std::cout << "Dog found" << std::endl; }

Dog::~Dog() { std::cout << "Dog lost" << std::endl; }

Dog &Dog::operator=(const Dog &dog) {
	if (this == &dog) return *this;
	std::cout << "Dog coppied" << std::endl;
	Animal::operator=(dog);
	return *this;
}

Dog::Dog(const Animal &Dog) : Animal(Dog) { std::cout << "Dog copy Found" << std::endl; }

void Dog::makeSound() const { std::cout << "Vau Vau" << std::endl; }