/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 07:42:42 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/05 11:18:04 by kvebers          ###   ########.fr       */
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
    if (_weapon != nullptr)
        delete _weapon;
    return ;
}

void    HumanB::attack()
{
    if (_weapon != nullptr)
    {
        std::cout << _name << " attacks with their ";
        std::cout << _weapon.getType() << std::endl;
    }
    else
    {
        std::cout << " attacks with their bravery and bear fists,
        he summons the spirits of the anncestorts and
        overcomes any weapon put againt him" <<std::endl;
    }
    return ;
}

void    HumanB::setWeapon(Weapon weapon)
{
    if (weapon _weapon == nullptr)
        _weapon = weapon;
    else
    {
        delete _weapon;
        _weapon = weapon;
    }  
}