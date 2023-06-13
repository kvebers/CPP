/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:02:34 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/13 14:52:51 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
   public:
	// ORTHODOX
	Brain();
	~Brain();
	Brain(const Brain &brain);
	Brain &operator=(const Brain &brain);
	void setIdea(unsigned int index, const std::string& idea);
	void printIdea(unsigned int idea_numb);
   private:
	std::string _ideas[100];

};

#endif