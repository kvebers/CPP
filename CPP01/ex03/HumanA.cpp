/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 07:42:39 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/14 08:46:08 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : _name(name), _weapon(weapon) { return; }

HumanA::~HumanA() {
	std::cout << "The Human A has been destoryed" << std::endl;
	return;
}

void HumanA::attack() const {
	std::cout << _name << " attacks with ";
	std::cout << _weapon.getType() << std::endl;
}