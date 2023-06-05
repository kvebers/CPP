/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:36:11 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/05 11:39:38 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <Weapon.hpp>

class HumanA
{
    public:
        std::string _name;
        Weapon _weapon;
    private:
        void HumanB::attack()
        ~HumanB();
        HumanB(const std::string name);
        setWeapon(Weapon weapon);
};

#endif