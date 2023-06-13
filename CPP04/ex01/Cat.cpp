/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:49:22 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/13 15:36:39 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	_brain = new Brain();
	std::cout << "Cat found" << std::endl;
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat lost" << std::endl;
}

Cat &Cat::operator=(const Cat &cat) {
	if (this == &cat) return *this;
	std::cout << "Cat coppied" << std::endl;
	Animal::operator=(cat);
	_brain->setIdea(, const std::string &idea)
	return *this;
}

Cat::Cat(const Animal &cat) : Animal(cat) { std::cout << "Cat Copy Found" << std::endl; }

void Cat::makeSound() const { std::cout << "Ņauuu Ņauuu Ņauuu" << std::endl; }

void Cat::setIdea(unsigned int idea_numb, std::string idea) { _brain->setIdea(idea_numb, idea); }

void Cat::printIdea(unsigned int idea_numb) { _brain->printIdea(idea_numb); }