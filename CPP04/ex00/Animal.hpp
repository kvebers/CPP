/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:28:31 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/12 11:16:41 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
   public:
   //ORTHODOX STUFF
	Animal();
	virtual ~Animal();
	Animal(const Animal &animal);
	Animal &operator=(const Animal &animal);
    //The Functions
	std::string getType() const;
	virtual void makeSound() const;
    //INPUT
   protected:
	std::string _type;
};

#endif