/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:22:07 by kvebers           #+#    #+#             */
/*   Updated: 2023/08/01 15:31:08 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <stdexcept>

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Wrong argument number" << std::endl;
		return (0);
	}
	try {
		ScalarConverter::convert(argv[1]);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}