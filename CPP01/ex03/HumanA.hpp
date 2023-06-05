/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:21:03 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/05 11:38:12 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <Weapon.hpp>

class HumanA
{
    public:
        std::string _name;
        Weapon _weapon;
    private:
        void HumanA::attack()
        ~HumanA();
        HumanA(const std::string &name, const Weapon &weapon);
};

#endif