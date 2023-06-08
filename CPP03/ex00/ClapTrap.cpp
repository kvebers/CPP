/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:14:21 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/08 15:41:40 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//ORTODOX STUFF AND WHAT NOT don't know the correct spelling sorry 

ClapTrap::ClapTrap(const std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout<<"Character "<< _name <<" Has Been created"<<std::endl;
    return ;
}

ClapTrap::~ClapTrap()
{
    std::cout<<"Character "<< _name <<" Has Been Terminated"<<std::endl;
    return ;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &trap)
{
    if (this == &this)
        return *this;
    std::cout << "Calling the copy assigment opperator" << std::endl;
    _name = trap._name;
    _hitPoints = trap._hitPoints;
    _energyPoints = trap._energyPoints;
    _attackDamage = trap._attackDamage;
    return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &trap): _name(trap._name), _hitPoints(trap._hitPoints), _energyPoints(trap._energyPoints), _attackDamage(trap._attackDamage)
{
    std::cout << "Copy Constructor has been Called" << std::endl;
}

//SETTERS AND GETTERS

void ClapTrap::setName(std::string name)
{
    _name = name;
    return ;
}

void ClapTrap::setHealth(int health)
{
    _hitPoints = health;
    return ;
}

void ClapTrap::setEnergy(int energy)
{
    _energyPoints = energy;
    return ;
}


void ClapTrap::setDamage(int damage)
{
    _attackDamage = damage;
    return ;
}

std::string ClapTrap::getName(void)
{
    return (_name);
}

int ClapTrap::getHealth(void)
{
    return (_hitPoints);
}

int ClapTrap::getDamage(void)
{
    return (_attackDamage);
}

int ClapTrap::setEnergy(void)
{
    return (_energyPoints);
}

// THE ACTUAL FUNCTIONS

void    ClapTrap::attack(const std::string &target)
{
    if (_energyPoints > 0)
    {
        std::cout<< "ClapTrap: " << _name
        << "Attacks" << target << "dealing" << _attackDamage
        <<" DMG" <<using std::endl;
        _energyPoints--;
    }
    else
    {
        std::cout<< "ClapTrap: "<< _name << "is out of energy points, he is kinda lame"<<std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints > 0)
    {
        std::cout << "ClapTrap: "
    }
}