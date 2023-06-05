/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 07:42:42 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/05 12:49:23 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string name):_name(name), _weapon(nullptr)
{
    return ;
}

HumanB::~HumanB()
{
    std::cout<< "HumanB has been destroyed" << std::endl;
    return ;
}

void    HumanB::attack() const
{
    if (_weapon == nullptr)
    {
        std::cout << _name;
        std::cout << " attacks with their fists " <<std::endl;
    }
    else
    {
        std::cout << _name << " attacks with ";
        std::cout << _weapon->getType() << std::endl;
        
    }
    return ;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}