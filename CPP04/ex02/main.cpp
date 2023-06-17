/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:17:28 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/17 17:29:13 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	{
		// Animal animal; // Uncomment when testing Cannot implement since there is unitialized pure
		// // virual value compiler error
		// Animal *animal = new Animal();
		Cat cat;
		Dog dog;
		Animal *animal1 = new Cat();
		Animal *animal2 = new Dog();
		dog.makeSound();
		cat.makeSound();
		animal1->makeSound();
		animal2->makeSound();
		delete animal1;
		delete animal2;
	}
}