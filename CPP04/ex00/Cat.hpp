/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:49:31 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/13 09:49:37 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal{
    public:
        Cat();
        ~Cat();
        Cat &operator=(const Cat &cat);
        Cat(const Animal &cat);
        virtual void makeSound() const;
    
};

#endif