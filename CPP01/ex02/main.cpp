/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:27:28 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/01 12:47:48 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str; // in short reference allows to make an alterntive name for certain variable

    std::cout<<std::endl<<"The memory address of the string variable: " << &str << std::endl;
    std::cout<<"The memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout<<"The memory address held by stringREF: " << &stringREF << std::endl << std::endl;

    std::cout<<"The value of the string variable: "<< str <<std::endl;
    std::cout<<"The value of the string variable: "<< *stringPTR <<std::endl;
    std::cout<<"The value of the string variable: "<< stringREF <<std::endl <<std::endl;
}