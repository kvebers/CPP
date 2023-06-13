/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:23:39 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/13 11:39:12 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal {
   public:
	// ORTHODOX STUFF
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal &animal);
	WrongAnimal &operator=(const WrongAnimal &wronganimal);
	WrongAnimal(std::string type);
	// The Functions
	std::string getType() const;
	void makeSound() const;
	// INPUT
   protected:
	std::string _type;
};

#endif