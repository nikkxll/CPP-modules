/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:54:08 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/29 13:00:11 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("unknown")
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	_gateKeeperMode = false;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	_gateKeeperMode = false;
	std::cout << "ScavTrap constructor overload called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	name = other.name;
	_gateKeeperMode = other._gateKeeperMode;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
		name = other.name;
		 _gateKeeperMode = other._gateKeeperMode;
	}
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (hitPoints <= 0)
	{
		std::cout << "ScavTrap " << name << " has no hit points left and cannot attack!" << std::endl;
		return;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ScavTrap " << name << " has no energy points left and cannot attack!" << std::endl;
		return;
	}
	energyPoints--;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
		<< attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	if (_gateKeeperMode == false)
	{
		_gateKeeperMode = true;
		std::cout << "ScavTrap " << name << " now in Gate keeper mode!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << name << " already in Gate keeper mode" << std::endl;
}
