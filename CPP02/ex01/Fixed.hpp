/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:23:13 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/14 08:47:11 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
   private:
	static const int _numb = 8;
	int _fix;

   public:
	Fixed();
	Fixed(const Fixed& iamfixed);
	Fixed& operator=(const Fixed& iamfixed);
	~Fixed();
	Fixed(const int input);
	Fixed(const float input);
	int getRawBits(void);
	void setRawBits(const int input);
	int toInt(void) const;
	float toFloat(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif