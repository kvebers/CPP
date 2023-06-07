/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:25:17 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/06 14:47:57 by kvebers          ###   ########.fr       */
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

int Fixed::getRawBits()
{
    std::cout << "getRawBits member function called" <<std::endl;
    return _fix;
}

void Fixed::setRawBits(void)
{
    std::cout <<"setRawBits member function is called" <<std::endl;
    _fix = _numb;
    return ;
}

float Fixed::ToInt(void) const
{
    
}

int Fixed::ToFloat(void) const
{
    
}
