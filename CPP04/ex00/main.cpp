/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:17:28 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/13 09:50:56 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

int main()
{
    {
        Animal animal;
        Animal *animal1 = new Cat();
        animal1->makeSound();
        delete animal1;
    }
}