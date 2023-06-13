/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:41:28 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/13 11:51:16 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") { std::cout << "WrongCat found" << std::endl; }

WrongCat::~WrongCat() { std::cout << "WrongCat lost" << std::endl; }

WrongCat &WrongCat::operator=(const WrongCat &wrongcat) {
	if (this == &wrongcat) return *this;
	std::cout << "WrongCat coppied" << std::endl;
	WrongAnimal::operator=(wrongcat);
	return *this;
}

WrongCat::WrongCat(const WrongAnimal &wrongcat) : WrongAnimal(wrongcat) {
	std::cout << "WrongCat Copy Found" << std::endl;
}

void WrongCat::makeSound() const { std::cout << "Ņauuu Ņauuu Ņauuu" << std::endl; }