/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:06:27 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/21 15:22:38 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
	int		N = 10;
	Zombie* horde = zombieHorde(N, "Johnny");

	if (horde)
	{
		for (int i = 0; i < N; ++i)
		{
			horde[i].announce();
		}
		delete[] horde;
	}
	
	return 0;
}
