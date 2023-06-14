/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:25:17 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/14 08:47:54 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fix(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed(const int input) : _fix(input << _numb) {
	std::cout << "Int Constructor called" << std::endl;
}

Fixed::Fixed(const float input) : _fix(static_cast<int>(roundf(input * (1 << _numb)))) {
	std::cout << "Float Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &iamfixed) : _fix(iamfixed._fix) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &iamfixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &iamfixed) _fix = iamfixed._fix;
	return *this;
}

int Fixed::getRawBits() { return _fix; }

void Fixed::setRawBits(int const input) { _fix = input; }

int Fixed::toInt(void) const { return (_fix >> _numb); }

float Fixed::toFloat(void) const { return (static_cast<float>(_fix) / (1 << _numb)); }

Fixed &Fixed::min(Fixed &val1, Fixed &val2) { return (val1 < val2) ? val1 : val2; }

const Fixed &Fixed::min(const Fixed &val1, const Fixed &val2) {
	return (val1 < val2) ? val1 : val2;
}

Fixed &Fixed::max(Fixed &val1, Fixed &val2) { return (val1 > val2) ? val1 : val2; }

const Fixed &Fixed::max(const Fixed &val1, const Fixed &val2) {
	return (val1 > val2) ? val1 : val2;
}

bool Fixed::operator>(const Fixed &iamfixed) const { return (_fix > iamfixed._fix); }

bool Fixed::operator<(const Fixed &iamfixed) const { return (_fix < iamfixed._fix); }

bool Fixed::operator>=(const Fixed &iamfixed) const { return (_fix >= iamfixed._fix); }

bool Fixed::operator<=(const Fixed &iamfixed) const { return (_fix <= iamfixed._fix); }

bool Fixed::operator==(const Fixed &iamfixed) const { return (_fix == iamfixed._fix); }

bool Fixed::operator!=(const Fixed &iamfixed) const { return (_fix != iamfixed._fix); }

Fixed Fixed::operator+(const Fixed &iamfixed) const {
	Fixed res;
	res._fix = _fix + iamfixed._fix;
	return res;
}

Fixed Fixed::operator-(const Fixed &iamfixed) const {
	Fixed res;
	res._fix = _fix - iamfixed._fix;
	return res;
}

Fixed Fixed::operator*(const Fixed &iamfixed) const {
	Fixed res;
	res._fix = (_fix * iamfixed._fix) >> _numb;
	return res;
}

Fixed Fixed::operator/(const Fixed &iamfixed) const {
	Fixed res;
	res._fix = (_fix * (1 << _numb)) / iamfixed._fix;
	return res;
}

Fixed &Fixed::operator++() {
	++_fix;
	return *this;
}

Fixed &Fixed::operator--() {
	--_fix;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed res(*this);
	++(*this);
	return res;
}

Fixed Fixed::operator--(int) {
	Fixed res(*this);
	--(*this);
	return res;
}
// super important
std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
}
