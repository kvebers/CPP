/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:14:21 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/08 14:55:57 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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
