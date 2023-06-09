/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:17:28 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/13 12:28:58 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

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
		delete animal1;
		delete animal2;
		std::cout << "Test for the incorrect animal sound should display default" << std::endl
				  << std::endl;
		WrongAnimal *animal3 = new WrongCat();
		animal3->makeSound();
		delete animal3;
	}
	{
		std::cout << std::endl << "===============TEST=1=============" << std::endl << std::endl;
		Animal animal;
		std::cout << std::endl
				  << "Test for the correct animals and correct sounds" << std::endl
				  << std::endl;
		Animal *animal1 = new Dog();
		Animal *animal2 = new Cat();
		animal1->makeSound();
		animal2->makeSound();
		delete animal1;
		delete animal2;
		std::cout << "Test for the incorrect animal sound should display default" << std::endl
				  << std::endl;
		WrongAnimal *animal3 = new WrongCat();
		animal3->makeSound();
		delete animal3;
	}
}