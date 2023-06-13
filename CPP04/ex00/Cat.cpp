/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:49:22 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/13 15:36:00 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") { std::cout << "Cat found" << std::endl; }

Cat::~Cat() { std::cout << "Cat lost" << std::endl; }

Cat &Cat::operator=(const Cat &cat) {
	if (this == &cat) return *this;
	std::cout << "Cat coppied" << std::endl;
	Animal::operator=(cat);
	
	return *this;
}

Cat::Cat(const Animal &cat) : Animal(cat) { std::cout << "Cat Copy Found" << std::endl; }

void Cat::makeSound() const { std::cout << "Ņauuu Ņauuu Ņauuu" << std::endl; }