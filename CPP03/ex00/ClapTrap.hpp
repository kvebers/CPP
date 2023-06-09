/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:14:17 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/09 11:25:02 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
    private:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
    public:
        //orthodox form
        ClapTrap(const std::string name);
        ~ClapTrap();
        ClapTrap(const ClapTrap &trap);
        ClapTrap &operator=(const ClapTrap &trap);
        //functions needed to implement by subject
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        //setters and getters
        void setName(std::string name);
        void setHealth(int health);
        void setEnergy(int energy);
        void setDamage(int damage);
        std::string getName(void);
        int getHealth(void);
        int getDamage(void);
        int getEnergy(void);
};

std::ostream& operator<<(std::ostream& os, ClapTrap& trap);

#endif