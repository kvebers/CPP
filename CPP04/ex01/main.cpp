/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:17:28 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/13 15:34:04 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	{
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
	{
	
		Cat cat = Cat();
		cat.setIdea(0, "Test");
		cat.printIdea(0);
		Cat cat1(cat);
		cat.printIdea(0);
	}
}