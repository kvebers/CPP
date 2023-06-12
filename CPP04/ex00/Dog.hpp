/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:49:36 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/12 14:01:42 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal{
    public:
        Dog();
        ~Dog();
        Dog &operator=(const Dog &dog);
        Dog(const Animal &dog);
    private:
    
};

#endif