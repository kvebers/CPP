/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:14:08 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/11 07:46:10 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	{
		ClapTrap problem("Problem");
		ClapTrap no("No Problem");

		std::cout << std::endl
				  << "====================TEST=1=====================" << std::endl
				  << std::endl;
		std::cout << problem << std::endl << std::endl;
		std::cout << no << std::endl << std::endl;

		while (problem.getEnergy() > 0) {
			problem.attack("no");
			no.takeDamage(problem.getDamage());
		}
		std::cout << std::endl;
		while (no.getEnergy() > 0) no.beRepaired(1);
		std::cout << std::endl;
		std::cout << problem << std::endl << std::endl;
		std::cout << no << std::endl << std::endl;
	}
	{
		ClapTrap problem("Problem");
		ClapTrap no("No Problem");

		std::cout << std::endl
				  << "====================TEST=2=====================" << std::endl
				  << std::endl;
		problem.setDamage(2);
		std::cout << problem << std::endl << std::endl;
		std::cout << no << std::endl << std::endl;
		while (problem.getEnergy() > 0) {
			problem.attack("no");
			no.takeDamage(problem.getDamage());
		}
		std::cout << std::endl;
		while (no.getEnergy() > 0) no.beRepaired(1);
		std::cout << std::endl;
		std::cout << problem << std::endl << std::endl;
		std::cout << no << std::endl << std::endl;
	}
	{
		ClapTrap problem("Problem");
		ClapTrap no("No Problem");

		std::cout << std::endl
				  << "====================TEST=3=====================" << std::endl
				  << std::endl;
		problem.setDamage(1);
		no.setDamage(2);
		std::cout << problem << std::endl << std::endl;
		std::cout << no << std::endl << std::endl;
		while (problem.getEnergy() > 0) {
			no.attack("problem");
			problem.takeDamage(no.getDamage());
			if (problem.getHealth() <= 0)
				problem.beRepaired(1);
			else {
				problem.attack("no");
				no.takeDamage(problem.getDamage());
			}
		}
		std::cout << std::endl;
		while (no.getEnergy() > 0) no.beRepaired(1);
		std::cout << std::endl;
		std::cout << problem << std::endl << std::endl;
		std::cout << no << std::endl << std::endl;
	}
}
