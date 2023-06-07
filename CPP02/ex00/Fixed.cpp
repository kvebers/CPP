/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:25:17 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/07 11:56:36 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fix(0)
{
    std::cout << "Default constructor called" <<std::endl;
    return ;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" <<std::endl;
    return ;
}

Fixed::Fixed(const Fixed &iamfixed): _fix(iamfixed._fix)
{
    std::cout << "Copy constructor called" <<std::endl;
    return ;   
}

Fixed &Fixed::operator=(const Fixed &iamfixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
     if (this != &iamfixed)
        _fix = iamfixed._fix;
    return *this;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" <<std::endl;
    return _fix;
}

void Fixed::setRawBits(int const input)
{
    std::cout <<"setRawBits member function is called" <<std::endl;
    _fix = input;
    return ;
}