/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:59:08 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/05 10:22:44 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//Summary of the excersise: Heap vs Stack Memory, Heap is bigger and more dynamic, hovever it needs to be manulaly delocated,
//meamwhile compiler takes care of the stack memory, also heap is at risk of fragmentation

int main()
{
    Zombie *heat_zombie = newZombie("Zombie On Fire"); //heap zombie
    heat_zombie->announce();

    delete heat_zombie;

    randomChump("Brick Zombie"); //stack zombie
    system("leaks BraiiiiiiinnnzzzZ");
    return (0);
}