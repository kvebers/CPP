/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:14:21 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/08 13:21:52 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout<<"Character "<< _name <<" Has Been created"<<std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout<<"Character "<< _name <<" Has Been Terminated"<<std::endl;
}