/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:23:13 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/07 15:56:55 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        static const int _numb = 8;
        int _fix;
    public:
        Fixed();
        Fixed(const Fixed &iamfixed);
        Fixed &operator=(const Fixed &iamfixed);
        Fixed(const int input);
        Fixed(const float input);
        ~Fixed();
        int getRawBits(void);
        void setRawBits(const int input);
        int toInt(void) const;
        float toFloat(void) const;

        bool operator>(const Fixed &iamfixed) const;
        bool operator<(const Fixed &iamfixed) const;
        bool operator>=(const Fixed &iamfixed) const;
        bool operator<=(const Fixed &iamfixed) const;
        bool operator==(const Fixed &iamfixed) const;
        bool operator!=(const Fixed &iamfixed) const;

        Fixed operator+(const Fixed &iamfixed) const;
        Fixed operator-(const Fixed &iamfixed) const;
        Fixed operator*(const Fixed &iamfixed) const;
        Fixed operator/(const Fixed &iamfixed) const;

        Fixed &operator++();
        Fixed &operator++(int);
        Fixed &operator--();
        Fixed &operator--(int);

        static Fixed& min(const Fixed &val1, const Fixed &val2);
        static const Fixed& min(const Fixed &val1, const Fixed &val2);
        static Fixed& max(const Fixed &val1, const Fixed &val2);
        static const Fixed& max(const Fixed &val1, const Fixed &val2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif