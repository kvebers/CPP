/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:44:49 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/09 18:01:21 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    private:
    public:
        FragTrap();
        ~FragTrap();
        FragTrap(const std::string &name);
        FragTrap &operator=(FragTrap &trap);
        // Functions to update and implement 
        void guardGate();
        void attack(const std::string &target);
};

std::ostream& operator<<(std::ostream& os, FragTrap& trap);

#endif