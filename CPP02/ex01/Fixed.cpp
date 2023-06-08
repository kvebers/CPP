/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:25:17 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/08 10:30:51 by kvebers          ###   ########.fr       */
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

Fixed::Fixed(const int input) : _fix(input << _numb)
{
    std::cout << "Int Constructor called" <<std::endl;
    return ;
}

Fixed::Fixed(const float input) : _fix(static_cast<int>(roundf(input * (1 << _numb))))
{
    std::cout << "Float Constructor called" <<std::endl;
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
    return _fix;
}

void Fixed::setRawBits(int const input)
{
    _fix = input;
    return ;
}

int Fixed::toInt(void) const
{
    return (_fix >> _numb);
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(_fix) / (1 << _numb));
}
/*
So what I understood from the subject about the overloads, we do so, to to simplfy the output and make it more intuitive,
exaple:
Fixed f(3.14);
Without overload
std::cout << f; Displays adress:0x7ffd8e3f4abc
so to actually use it you would need to 
std::cout << f.toFloat;
with overload
std::cout << f; Result 3.14
*/


/*
Declears the os stream and the Class and the opperation class
opperates with the functuin and returns its value.
*/
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) 
{
    os << fixed.toFloat();
    return os;
}