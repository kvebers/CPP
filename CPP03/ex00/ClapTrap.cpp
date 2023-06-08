/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:14:21 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/08 13:08:49 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout<<"Game Has Been created"<<std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout<<"This Game Has Been Terminated, thank the GODS"<<std::endl;
}