/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:06:27 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/21 13:41:40 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
	Zombie* heapZombie = newZombie("Heappy");
	Zombie* heapZombie2 = newZombie("Creepy");
	heapZombie->announce();
	heapZombie2->announce();
	delete heapZombie;
	delete heapZombie2;
	
	randomChump("Stacky");
	randomChump("Luucky");
	
	return 0;
}
