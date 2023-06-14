/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:48:25 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/14 08:45:56 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	int cnt;
	int cnt1;

	cnt = 5;
	cnt1 = 0;
	Zombie *horde = zombieHorde(cnt, "CPP syntax");
	while (cnt1 < cnt) {
		std::cout << cnt1 << " ";
		horde[cnt1].announce();
		cnt1++;
	}
	delete[] horde;	 // for some reason it is not in front but behind sure C++, sure
	system("leaks horde");
}