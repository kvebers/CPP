/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:22:07 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/30 12:40:44 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Wrong argument number" << std::endl;
		return (0);
	}
	ScalarConverter::convert(argv[1]);
}