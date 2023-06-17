/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:20:05 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/17 10:55:30 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// ORTHODOX FORM wop wop

ScavTrap::ScavTrap(const ScavTrap &trap) : ClapTrap("SCAVTRAP") {
	_hitPoints = trap._hitPoints;
	_energyPoints = trap._energyPoints;
	_attackDamage = trap._attackDamage;
	_name = trap._name;
	std::cout << "ScavTrap: " << _name
		  << " Copy Constructor has been called, that is special to SCAVTRAP"
		  << std::endl;
	return;
}

ScavTrap::ScavTrap() : ClapTrap("SCAVTRAP") {
	std::cout << "The ScavTrap: " << _name << " has been created, long live the ScavTrap"
			  << std::endl;
	_name = "Default";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	return;
}

ScavTrap::~ScavTrap() {
	std::cout << "The ScavTrap " << _name << " has been destoryed for ever" << std::endl;
	return;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "ScavTrap: " << _name << " Parameterized Constructor has been called"
			  << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	return;
}

ScavTrap &ScavTrap::operator=(ScavTrap &trap) {
	std::cout << "ScavTrap:  " << _name << " COpy assigment opperator has been called"
			  << std::endl;
	if (this == &trap) return *this;
	ClapTrap::operator=(trap);
	return *this;
}
// printing helper function essecianly

std::ostream &operator<<(std::ostream &os, ScavTrap &trap) {
	os << "Name: " << trap.getName() << ", Health: " << trap.getHealth()
	   << ", Energy: " << trap.getEnergy() << ", Damage: " << trap.getDamage();
	return os;
}

// FUNCTIONS to update and change

void ScavTrap::attack(const std::string &target) {
	if (_energyPoints > 0) {
		std::cout << "ScavTrap: \"" << _name << "\" Attacks " << target << " dealing "
				  << _attackDamage << " DMG, and prints diffrent MSG" << std::endl;
		_energyPoints--;
	} else if (_hitPoints <= 0)
		std::cout << "ScavTrap: \"" << _name
				  << "\" is dead, he can not perform any actions, however he can print diffrent MSG"
				  << std::endl;
	else
		std::cout << "ScavTrap: \"" << _name
				  << "\" is out of energy points, he is kinda lame, hovever he is still a printing "
					 "diffrent MSG"
				  << std::endl;
	return;
}

void ScavTrap::guardGate() {
	if (_energyPoints <= 0)
		std::cout << "ScavTrap: \"" << _name << "\" Can not guard gate, bcz no energy is left"
				  << std::endl;
	else if (_hitPoints <= 0)
		std::cout << "ScavTrap: \"" << _name << "\" Can not guard gate, bcz he is dead"
				  << std::endl;
	else {
		_energyPoints--;
		std::cout << "ScavTrap: \"" << _name
				  << "\" attempts to guard the gate, but then he realizes that there aint any gate"
				  << std::endl;
	}
	return;
}