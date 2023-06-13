/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:33:24 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/13 15:29:22 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	int cnt = 0;
	while (cnt < 100) {
		_ideas[cnt] = "Default idea";
		cnt++;
	}
	std::cout << "Brain created" << std::endl;
}

Brain::~Brain() { std::cout << "Brain Destroyed" << std::endl; }

Brain::Brain(const Brain &brain) {
	int cnt = 0;
	while (cnt < 100) {
		_ideas[cnt] =  brain._ideas[cnt];
		cnt++;
	} 
}

Brain &Brain::operator=(const Brain &brain) {
	int cnt = 0;
	if (this == &brain) return *this;
	while (cnt < 100) {
		this->_ideas[cnt] = brain._ideas[cnt];
		cnt++;
	}
	return *this;
}

void Brain::setIdea(unsigned int idea_numb, const std::string &idea) { _ideas[idea_numb] = idea; }

void Brain::printIdea(unsigned int idea_numb) { std::cout << _ideas[idea_numb] << std::endl; }