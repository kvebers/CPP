/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:14:08 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/17 10:55:28 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	{
		std::cout << std::endl
				  << "====================TEST=1=====================" << std::endl
				  << std::endl;
		std::cout << "INITS" << std::endl;
		ScavTrap lol;
		ScavTrap trap("TESTER");
		std::cout << "INFO" << std::endl;
		std::cout << trap << std::endl;
		std::cout << std::endl << lol << std::endl;
		lol.attack("TESTER");
		lol.guardGate();
		trap.takeDamage(lol.getDamage());
		std::cout << trap << std::endl;
		std::cout << std::endl << lol << std::endl;
		std::cout << std::endl << "DESTROYS" << std::endl;
	}
	{
		std::cout << std::endl
				  << "====================TEST=2=====================" << std::endl
				  << std::endl;
		std::cout << "INITS" << std::endl;
		ScavTrap lol;
		ScavTrap trap("TESTER");
		std::cout << "INFO" << std::endl;
		std::cout << trap << std::endl;
		std::cout << std::endl << lol << std::endl;
		int i;

		i = 0;
		while (i < 5) {
			lol.attack("TESTER");
			trap.takeDamage(lol.getDamage());
			trap.guardGate();
			lol.guardGate();
			lol.beRepaired(1);
			std::cout << trap << std::endl;
			std::cout << std::endl << lol << std::endl;
			i++;
		}
		std::cout << std::endl << "DESTROYS" << std::endl;
	}
}
