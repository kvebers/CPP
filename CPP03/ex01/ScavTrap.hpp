/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:20:01 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/17 10:55:31 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
   private:
   public:
	ScavTrap();
	ScavTrap(ScavTrap const &trap);
	~ScavTrap();
	ScavTrap(const std::string &name);
	ScavTrap &operator=(ScavTrap &trap);
	// Functions to update and implement
	void guardGate();
	void attack(const std::string &target);
};

std::ostream &operator<<(std::ostream &os, ScavTrap &trap);

#endif