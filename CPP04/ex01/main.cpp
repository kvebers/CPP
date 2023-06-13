/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:17:28 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/13 12:34:04 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	{
		std::cout << std::endl << "===============TEST=0=============" << std::endl << std::endl;
		Animal animal;
		std::cout << std::endl
				  << "Test for the correct animals and correct sounds" << std::endl
				  << std::endl;
		Animal *animal1 = new Cat();
		Animal *animal2 = new Dog();
		animal1->makeSound();
		animal2->makeSound();
	}
}