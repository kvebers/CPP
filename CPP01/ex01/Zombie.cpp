/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:54:40 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/01 12:12:59 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

void    Zombie::update_name(std::string name)
{
    _name = name;
    return;
}

Zombie::~Zombie()
{
    std::cout << "Wow, I destroyed something, but what did I destroy?" <<std::endl;
    return;
}

void Zombie::announce()
{
    std::cout << _name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}