/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:49:31 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/17 15:23:56 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
   public:
	Cat();
	~Cat();
	Cat &operator=(const Cat &cat);
	Cat(const Animal &cat);
	virtual void makeSound() const;

	void setIdea(int location, const std::string &idea);
	void printIdea(int location);

   private:
	Brain _brain;
};

#endif