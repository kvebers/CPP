/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:25:17 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/07 18:40:51 by kvebers          ###   ########.fr       */
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

Fixed::Fixed(const int raw) : _fix(raw << _numb)
{
    return ;
}

Fixed::Fixed(const float raw) : _fix(static_cast<int>(roundf(raw * (1 << _numb))))
{
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

std::ostream &operator<<(std::ostream& os, const Fixed& fixed) 
{
    os << fixed.toFloat();
    return os;
}

Fixed &Fixed::min(Fixed &val1, Fixed &val2)
{
    return (val1 < val2) ? val1 : val2;
}

const Fixed &Fixed::min(const Fixed &val1, Fixed &val2)
{
    return (val1 < val2) ? val1 : val2;
}

Fixed &Fixed::max(Fixed &val1, Fixed &val2)
{
    return (val1 > val2) ? val1 : val2;
}

const Fixed &Fixed::max(Fixed &val1, Fixed &val2)
{
    return (val1 > val2) ? val1 : val2;
}

bool operator>(const Fixed &iamfixed) const;
{
    return (_fix > iamfixed._fix);
}

bool operator<(const Fixed &iamfixed) const
{
    return (_fix < iamfixed._fix);
}

bool operator>=(const Fixed &iamfixed) const
{
    return (_fix >= iamfixed._fix);
}

bool operator<=(const Fixed &iamfixed) const
{
    return (_fix <= iamfixed._fix);
}

bool operator==(const Fixed &iamfixed) const
{
    return (_fix == iamfixed._fix);
}

bool operator!=(const Fixed &iamfixed) const
{
    return (_fix != iamfixed._fix);
}

Fixed operator+(const Fixed &iamfixed) const
{
      Fixed res;
      res._fix = _fix + iamfixed._fix;
      return (res);
}

Fixed operator-(const Fixed &iamfixed) const
{
    Fixed res;
    res._fix = _fix - iamfixed._fix;
    return (res);
}

Fixed operator*(const Fixed &iamfixed) const
{
    Fixed res;
    res._fix = _fix * iamfixed._fix;
    return (res);
}

Fixed operator/(const Fixed &iamfixed) const
{
    Fixed res;
    res._fix = _fix / iamfixed._fix;
    return (res);
}

Fixed &operator++()
{
    _fix++;
    return (*this);
}

Fixed &operator++(int)
{
    Fixed sum(*this);
    ++(*this);
    return (sum);
}

Fixed &operator--()
{
     _fix--;
    return (*this);
}

Fixed &operator--(int)
{
    Fixed sub(*this);
    --(*this);
    return (sub);
}