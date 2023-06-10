/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:10:43 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/10 07:13:04 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;
    
    std::cout<<std::endl;
    harl.complain("DEBUG");
    std::cout<<std::endl;
    harl.complain("INFO");
    std::cout<<std::endl;
    harl.complain("WARNING");
    std::cout<<std::endl;
    harl.complain("ERROR");
    std::cout<<std::endl;
    harl.complain("IDasdasdK");
    std::cout<<std::endl;
}
