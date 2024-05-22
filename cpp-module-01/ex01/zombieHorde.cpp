/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:35:52 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/21 15:15:19 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N < 0)
	{
		return nullptr;
	}

	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; ++i) {
		horde[i].setZombieName(name);
	}
	return (horde);
}
