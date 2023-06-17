/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:44:52 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/17 10:47:48 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FRAGTRAP") {
	std::cout << "The FragTrap: " << _name
			  << " has been created, long live the FragTrap, that is special to FRAGTRAP"
			  << std::endl;
	_name = "Default";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	return;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "FragTrap: " << _name
			  << " Parameterized Constructor has been called, that is special to FRAGTRAP"
			  << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	return;
}

FragTrap::FragTrap(const FragTrap &trap) : ClapTrap("FRAGTRAP") {
	_hitPoints = trap._hitPoints;
	_energyPoints = trap._energyPoints;
	_attackDamage = trap._attackDamage;
	_name = trap._name;
	std::cout << "FragTrap: " << _name
			  << " Copy Constructor has been called, that is special to FRAGTRAP"
			  << std::endl;
	return;
}

FragTrap::~FragTrap() {
	std::cout << "The FragTrap " << _name
			  << " has been destoryed for ever, that is special to FRAGTRAP" << std::endl;
	return;
}

FragTrap &FragTrap::operator=(FragTrap &trap) {
	std::cout << "FragTrap:  " << _name
			  << " COpy assigment opperator has been called, that is special to FRAGTRAP"
			  << std::endl;
	if (this == &trap) return *this;
	ClapTrap::operator=(trap);
	return *this;
}
// printing helper function essecianly

std::ostream &operator<<(std::ostream &os, FragTrap &trap) {
	os << "Name: " << trap.getName() << ", Health: " << trap.getHealth()
	   << ", Energy: " << trap.getEnergy() << ", Damage: " << trap.getDamage();
	return os;
}

// FUNCTIONS to update and change

void FragTrap::attack(const std::string &target) {
	if (_energyPoints > 0) {
		std::cout << "FragTrap: \"" << _name << "\" Attacks " << target << " dealing "
				  << _attackDamage << " DMG, and prints diffrent MSG, that is special to FRAGTRAP"
				  << std::endl;
		_energyPoints--;
	} else if (_hitPoints <= 0)
		std::cout << "FragTrap: \"" << _name
				  << "\" is dead, he can not perform any actions, however he can print diffrent "
					 "MSG, that is special to FRAGTRAP"
				  << std::endl;
	else
		std::cout << "FragTrap: \"" << _name
				  << "\" is out of energy points, he is kinda lame, hovever he is still a printing "
					 "diffrent MSG, that is special to FRAGTRAP"
				  << std::endl;
	return;
}

void FragTrap::highFivesGuys() {
	if (_energyPoints <= 0)
		std::cout << "FragTrap: \"" << _name << "\" Can not give a highFive, bcz he is kind of lame"
				  << std::endl;
	else if (_hitPoints <= 0)
		std::cout << "FragTrap: \"" << _name << "\" Can not give a highFive, bcz he is dead"
				  << std::endl;
	else {
		_energyPoints--;
		std::cout << "FragTrap: \"" << _name << "\" gives highFive" << std::endl;
	}
	return;
}