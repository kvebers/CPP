/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:10:41 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/10 07:13:47 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Harl.hpp"

Harl::Harl()
{
    probs[0] = &Harl::debug;
    probs[1] = &Harl::info;
    probs[2] = &Harl::warning;
    probs[3] = &Harl::error;
    return ;
}

Harl::~Harl()
{   
    std::cout << "HARL \"PROBLEM!!!\"" << std::endl;
    std::cout << "HARL HAS BEEN DELETED" << std::endl;
    std::cout << "no problem" << std::endl;
    return ;
}

void Harl::debug()
{
    std::cout<< "LIKE A PREDATOR HARL STARTS THE SEARCH FOR THE PROBLEMS" << std::endl;
}

void Harl::info()
{
    std::cout<< "HARL HAS FOUND HIS VICTIM A LONELY BUG, NOW IT IS TIME TO STRIKE AND COMPLAIN ABOUT THE PROGRAM" << std::endl;
}

void Harl::warning()
{
    std::cout<<"THE COMPLAINS HAS BEEN IGNORED, SO THE HARL ACTIVATES HIS SECRET WEAPON THE THREATS OF FAILING THE PROJECT" <<std::endl;
}

void Harl::error()
{
    std::cout<<"\"THAT IS IT THE HAMMER IS STRUK\" HARL FAILS YOU ON THE PROJECT"<<std::endl;
}

void Harl::complain(std::string level)
{
    int problem;
    const char *problems[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    problem = 0;
    while (problem < 4 && level.compare(problems[problem])!= 0)
        problem++;
    switch (problem)
    {
        case 0:
            (this->*probs[problem])();
            break ;
        case 1:
            (this->*probs[problem])();
            break ;
        case 2:
            (this->*probs[problem])();
            break ;
        case 3:
            (this->*probs[problem])();
            break ;
        default :
            std::cerr << "THE LEVEL OF COMPLAINT IS NOT COMPRAHENDABLE FOR A MEAR MORTAL" <<std::endl;
            break ;
        
    }
}