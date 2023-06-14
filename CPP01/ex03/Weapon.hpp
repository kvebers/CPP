/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 08:01:41 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/14 08:46:26 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
   private:
	std::string _type;

   public:
	Weapon();
	~Weapon();
	Weapon(const std::string &type);
	const std::string &getType(void) const;
	void setType(const std::string &type);
};

#endif