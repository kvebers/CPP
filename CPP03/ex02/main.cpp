/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:14:08 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/11 07:45:36 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
	{
		std::cout << std::endl
				  << "====================TEST=0=====================" << std::endl
				  << std::endl;
		std::cout << "INITS" << std::endl;
		FragTrap lol("test");
		FragTrap lol1;
		lol1 = lol;
		std::cout << "INFO" << std::endl;
		lol1.highFivesGuys();
		std::cout << lol1 << std::endl;
		std::cout << lol << std::endl;
		lol1 = lol;
		std::cout << lol1 << std::endl;
		std::cout << lol << std::endl;
		std::cout << std::endl << "DESTROYS" << std::endl;
	}
	{
		std::cout << std::endl
				  << "====================TEST=1=====================" << std::endl
				  << std::endl;
		std::cout << "INITS" << std::endl;
		FragTrap lol;
		FragTrap trap("TESTER");
		std::cout << "INFO" << std::endl;
		std::cout << trap << std::endl;
		std::cout << std::endl << lol << std::endl;
		trap.takeDamage(lol.getDamage());
		trap.highFivesGuys();
		std::cout << trap << std::endl;
		std::cout << std::endl << lol << std::endl;
		std::cout << std::endl << "DESTROYS" << std::endl;
	}
	{
		std::cout << std::endl
				  << "====================TEST=2=====================" << std::endl
				  << std::endl;
		std::cout << "INITS" << std::endl;
		FragTrap lol;
		FragTrap trap("TESTER");
		std::cout << "INFO" << std::endl;
		std::cout << trap << std::endl;
		std::cout << std::endl << lol << std::endl;
		int i;

		i = 0;
		while (i < 5) {
			trap.takeDamage(lol.getDamage());
			trap.beRepaired(15);
			trap.highFivesGuys();
			lol.highFivesGuys();
			std::cout << std::endl << trap << std::endl;
			std::cout << std::endl << lol << std::endl << std::endl;
			i++;
		}
		std::cout << std::endl << "DESTROYS" << std::endl;
	}
}
