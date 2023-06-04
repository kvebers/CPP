/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 08:01:41 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/04 17:20:59 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Weapon
{
    private:
        std::string _type;
    public:
        Weapon();
        ~Weapon();
        Weapon (std::string type);
        const std::string &getType(void) const;
        void setType(std::string type);
}
