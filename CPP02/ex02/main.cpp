/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:16:15 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/14 08:47:58 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
	{
		Fixed a(3.14f);
		Fixed b(2.71f);
		Fixed c(3.14f);

		std::cout << "My test cases" << std::endl << std::endl;
		std::cout << "Comparision opperations" << std::endl << std::endl;
		std::cout << "Result: " << (a > b) << " Expected: 1" << std::endl;
		std::cout << "Result: " << (a < b) << " Expected: 0" << std::endl;
		std::cout << "Result: " << (a >= b) << " Expected: 1" << std::endl;
		std::cout << "Result: " << (a <= b) << " Expected: 0" << std::endl;
		std::cout << "Result: " << (a == b) << " Expected: 1" << std::endl;
		std::cout << "Result: " << (a != b) << " Expected: 1" << std::endl;

		std::cout << "Arithmetical Opperations" << std::endl << std::endl;

		std::cout << "Result: " << a + b << " Expected: 5.85156" << std::endl;
		std::cout << "Result: " << a - b << " Expected: 0.429688" << std::endl;
		std::cout << "Result: " << a * b << " Expected: 8.51172" << std::endl;
		std::cout << "Result: " << a / b << " Expected: 1.15625" << std::endl;

		std::cout << " Max opperations " << std::endl << std::endl;
		std::cout << "Result: " << Fixed::min(a, b) << " Expected: 2.71094" << std::endl;
		std::cout << "Result: " << Fixed::max(a, b) << " Expected: 3.14062" << std::endl;
	}
	{
		std::cout << "Test case given in an example:" << std::endl << std::endl;
		Fixed a;
		Fixed const b(Fixed(5.05f) * Fixed(2));
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
	}
}