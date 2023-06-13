/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:49:31 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/13 14:52:33 by kvebers          ###   ########.fr       */
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
	void setIdea(unsigned int idea_numb, std::string idea);
	virtual void makeSound() const;
	void printIdea(unsigned int idea_numb);
	private:
		Brain *_brain;
};

#endif