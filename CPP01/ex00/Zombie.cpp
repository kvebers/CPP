/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:54:40 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/23 19:05:58 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    return;
}

Zombie::~Zombie()
{
    std::cout << "Destructor is called" <<std::endl;
    return;
}

void Zombie::announce()
{
    std::cout << name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}