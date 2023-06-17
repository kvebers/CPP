/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:14:08 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/17 10:35:13 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
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
		std::cout << "INITS" << std::endl;
		std::cout << trap << std::endl;
		std::cout << std::endl << lol << std::endl;
		int i;

		i = 0;
		while (i < 5) {
			lol.attack("trap");
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
	{
		std::cout << std::endl
				  << "====================TEST=3=====================" << std::endl
				  << std::endl;
		std::cout << "INITS" << std::endl<<std::endl;
		FragTrap lol("test");
		ScavTrap lol1("test1");
		std::cout << std::endl << "INFO" << std::endl << std::endl;
		std::cout<<lol<<std::endl;
		std::cout<<lol1<<std::endl;
		lol.attack("lol1");
		lol1.attack("lol");
		lol.takeDamage(lol1.getDamage());
		lol1.takeDamage(lol.getDamage());
		std::cout<<lol<<std::endl;
		std::cout<<lol1<<std::endl;
		
		std::cout << std::endl << "DESTROYS" << std::endl << std::endl;
	}
}
