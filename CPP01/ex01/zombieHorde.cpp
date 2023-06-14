/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:17:43 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/14 08:46:02 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
	Zombie *horde = new Zombie[N];	// Need a default constructor, because the new command forces
									// for explicit define, needed to delete
	int cnt;

	cnt = 0;
	while (cnt < N) {
		horde[cnt].update_name(name);
		cnt++;
	}
	return horde;
}
