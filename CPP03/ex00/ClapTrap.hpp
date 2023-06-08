/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:14:17 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/08 12:50:53 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
private:
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;
public:
    ClapTrap();
    ~ClapTrap();
    ClapTrap(const ClapTrap &trap);
    ClapTrap &operator=(const ClapTrap &trap);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif