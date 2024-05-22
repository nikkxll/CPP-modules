/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:16:28 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/22 17:05:19 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : weapon(nullptr), name(name) {}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	if (this->weapon)
	{
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	}
	else
	{
		std::cout << name << " can't attack without their weapon..." << std::endl;
	}
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}