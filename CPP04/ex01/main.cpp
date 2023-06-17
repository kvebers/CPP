/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:17:28 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/17 15:44:08 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	{
		std::cout << "====================TEST 0=========================" << std::endl
				  << std::endl;
		int cnt = 0;
		int modify_to_change_test = 50;
		Animal **animal = new Animal *[modify_to_change_test];
		while (cnt < modify_to_change_test) {
			std::cout << cnt << " ";
			if (cnt < modify_to_change_test / 2)
				animal[cnt] = new Cat();
			else
				animal[cnt] = new Dog();
			cnt++;
		}
		cnt = 0;
		while (cnt < modify_to_change_test) {
			std::cout << cnt << " ";
			delete animal[cnt];
			cnt++;
		}
		delete[] animal;
	}
	std::cout << "Leaks" << std::endl;
	system("leaks inception");
	{
		std::cout << "====================TEST 1=========================" << std::endl
				  << std::endl;
		Cat cat;
		Cat cat1 = cat;
		Cat cat2(cat);
		cat.printIdea(0);
		cat1.printIdea(0);
		cat2.printIdea(0);
		cat.setIdea(0, "Test");
		std::cout << std::endl<<"I am modifying ideas here to check for the deep copy" << std::endl << std::endl;
		cat.printIdea(0);
		cat1.printIdea(0);
		cat2.printIdea(0);
		cat.setIdea(0, "new idea");
		Cat cat3(cat);
		cat3.printIdea(0);
		Cat cat4 = cat;
		cat4.printIdea(0);
	}
	std::cout << "Leaks" << std::endl;
	system("leaks inception");
}