/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:14:08 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/09 11:29:46 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap problem("Problem");
    ClapTrap no("No Problem");
    
    std::cout<<std::endl<<"====================TEST=1====================="<<std::endl<<std::endl;
    std::cout << problem << std::endl<<std::endl;
    std::cout << no << std::endl<<std::endl;
}
