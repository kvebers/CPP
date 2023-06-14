/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 07:42:48 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/14 08:46:24 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : _type(NULL) { return; }

Weapon::~Weapon() {
	std::cout << "Sir, Ze weapon has been Destroyed" << std::endl;
	return;
}

Weapon::Weapon(const std::string &type) : _type(type) { return; }

const std::string &Weapon::getType() const { return _type; }

void Weapon::setType(const std::string &type) {
	_type = type;
	return;
}