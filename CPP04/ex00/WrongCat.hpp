/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:39:35 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/13 11:40:42 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
   public:
	WrongCat();
	~WrongCat();
	WrongCat &operator=(const WrongCat &wrongcat);
	WrongCat(const WrongAnimal &wrongcat);
	void makeSound() const;
};

#endif