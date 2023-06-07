/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:23:13 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/06 12:38:42 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        static const int _numb = 8;
        int _fix;
    public:
        Fixed();
        Fixed(const Fixed &iamfixed);
        Fixed &operator=(const Fixed &iamfixed);
        ~Fixed();
        int getRawBits(void);
        void setRawBits(void);
};

#endif