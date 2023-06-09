/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:44:52 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/09 17:58:48 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default")
{
    std::cout << "The ScavTrap: "<< this->_name << " has been created, long live the ScavTrap" << std::endl;
    this->_name = "Default";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    return ;
}

ScavTrap::~ScavTrap()
{
    std::cout << "The ScavTrap "<< this->_name << " has been destoryed for ever" << std::endl;
    return ;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "ScavTrap: "<< this->_name << " Parameterized Constructor has been called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    return ;
}

ScavTrap &ScavTrap::operator=(ScavTrap &trap)
{
    std::cout << "ScavTrap:  "<< this->_name << " COpy assigment opperator has been called"<< std::endl;
     if (this == &trap)
        return *this;
    ClapTrap::operator=(trap);
    return *this;
}
// printing helper function essecianly

std::ostream& operator<<(std::ostream& os, FragTrap& trap)
{
    os<<"Name: " << trap.getName() << ", Health: " << trap.getHealth() << ", Energy: " << trap.getEnergy() << ", Damage: " << trap.getDamage();
    return os;
}

// FUNCTIONS to update and change
