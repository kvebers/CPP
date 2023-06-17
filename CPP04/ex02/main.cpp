/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:17:28 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/17 17:26:18 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	{
		// Animal animal; // Uncomment when testing Cannot implement since there is unitialized pure
		//// virual value compiler error
		Cat cat;
		Dog dog;
		Animal *animal1 = new Cat();
		Animal *animal2 = new Dog();
		dog.makeSound();
		cat.makeSound();
		std::cout << "Umm this segfaults" << std::endl;
		delete animal1;
		delete animal2;
	}
}