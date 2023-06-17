/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:14:21 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/17 10:55:22 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// ORTODOX STUFF AND WHAT NOT don't know the correct spelling sorry

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Character " << _name << " Has Been created" << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Character " << _name << " Has Been created" << std::endl;
}

ClapTrap::~ClapTrap() { std::cout << "Character " << _name << " Has Been Terminated" << std::endl; }

ClapTrap &ClapTrap::operator=(const ClapTrap &trap) {
	if (this == &trap) return *this;
	std::cout << "Calling the copy assigment opperator" << std::endl;
	_name = trap._name;
	_hitPoints = trap._hitPoints;
	_energyPoints = trap._energyPoints;
	_attackDamage = trap._attackDamage;
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &trap)
	: _name(trap._name),
	  _hitPoints(trap._hitPoints),
	  _energyPoints(trap._energyPoints),
	  _attackDamage(trap._attackDamage) {
	std::cout << "Copy Constructor has been Called" << std::endl;
}

// SETTERS AND GETTERS

void ClapTrap::setName(std::string name) { _name = name; }

void ClapTrap::setHealth(int health) { _hitPoints = health; }

void ClapTrap::setEnergy(int energy) { _energyPoints = energy; }

void ClapTrap::setDamage(int damage) { _attackDamage = damage; }

std::string ClapTrap::getName(void) { return (_name); }

int ClapTrap::getHealth(void) { return (_hitPoints); }

int ClapTrap::getDamage(void) { return (_attackDamage); }

int ClapTrap::getEnergy(void) { return (_energyPoints); }

// THE ACTUAL FUNCTIONS

void ClapTrap::attack(const std::string &target) {
	if (_energyPoints > 0) {
		std::cout << "ClapTrap: \"" << _name << "\" Attacks " << target << " dealing "
				  << _attackDamage << " DMG" << std::endl;
		_energyPoints--;
	} else if (_hitPoints <= 0)
		std::cout << "ClapTrap: \"" << _name << "\" is dead, he can not perform any actions"
				  << std::endl;
	else
		std::cout << "ClapTrap: \"" << _name << "\" is out of energy points, he is kinda lame"
				  << std::endl;
	return;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints > 0) {
		std::cout << "ClapTrap: \"" << _name << "\" Takes Damage " << amount << " HP " << std::endl;
		_hitPoints = _hitPoints - amount;
		if (_hitPoints <= 0) {
			_hitPoints = 0;
			std::cout << "ClapTrap: \"" << _name << "\" died" << std::endl;
		}
	} else
		std::cout << "ClapTrap: \"" << _name << "\" is already dead have some respect" << std::endl;
	return;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints > 0) {
		if (_hitPoints == 0)
			std::cout << "ClapTrap: \"" << _name << "\" is revived from the dead and restors "
					  << amount << "HP" << std::endl;
		else
			std::cout << "ClapTrap: \"" << _name << "\" fixes himself and restors  " << amount
					  << "HP" << std::endl;
		_hitPoints = _hitPoints + amount;
		_energyPoints--;
	} else
		std::cout << "ClapTrap: \"" << _name << "\" is out of energy points, he is kinda lame"
				  << std::endl;
}

// OS stream override

std::ostream &operator<<(std::ostream &os, ClapTrap &trap) {
	os << "Name: " << trap.getName() << ", Health: " << trap.getHealth()
	   << ", Energy: " << trap.getEnergy() << ", Damage: " << trap.getDamage();
	return os;
}