/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:23:13 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/08 10:51:03 by kvebers          ###   ########.fr       */
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
        Fixed(); // 4 functions of orthodoxcanonical form constructor destructor copy constructor, copy assigment opperator
        Fixed(const Fixed &iamfixed); // when creating
        Fixed &operator=(const Fixed &iamfixed); // when updating 
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const input);
};

#endif