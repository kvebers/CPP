/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:28:31 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/11 09:47:39 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal{
    protected:
        std::string type;
    public:
        Animal();
        ~Animal();
        Animal(const std::string &type);
	    Animal &operator=(Animal &trap);
    
};


#endif