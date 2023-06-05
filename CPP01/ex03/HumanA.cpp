/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 07:42:39 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/05 11:06:35 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, const Weapon &weapon):_name(name), _weapon(weapon)
{
    return ;
}

HumanA::~HumanA()
{
    std::cout << "The Human has been destoryed" << std::endl;
    return ;
}

void    HumanA::attack()
{
    std::cout << _name << " attacks with their ";
    std::cout << _weapon.getType() << std::endl;
}