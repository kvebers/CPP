/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:49:36 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/13 14:19:54 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
   public:
	Dog();
	~Dog();
	Dog &operator=(const Dog &dog);
	Dog(const Animal &dog);
	virtual void makeSound() const;

   private:
	Brain *_brain;
};

#endif