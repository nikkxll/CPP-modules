/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:27:19 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/22 11:35:43 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << "Zombie " << name << " is created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " is destroyed.." << std::endl;
}

Zombie::Zombie()
{
	std::cout << "Zombie is created" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setZombieName(std::string name)
{
	this->name = name;
}
