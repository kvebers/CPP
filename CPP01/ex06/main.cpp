/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:10:43 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/14 08:46:52 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void leak_checker() { system("leaks Harl_Mode"); }

int main(int argc, char **argv) {
	Harl harl;
	if (argc != 2) {
		std::cerr << "Error" << std::endl;
		return (0);
	}
	harl.complain(argv[1]);
	// atexit(leak_checker);
}
