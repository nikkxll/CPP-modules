/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:23:16 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/27 22:17:49 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitPoints(10), energyPoints(10), attackDamage(0),
	name("unknown")
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name): hitPoints(10), energyPoints(10),
	attackDamage(0), name(name)
{
	std::cout << "ClapTrap constructor overload called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	name = other.name;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
		name = other.name;
	}
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " has no hit points left and cannot attack!" << std::endl;
		return;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " has no energy points left and cannot attack!" << std::endl;
		return;
	}
	energyPoints--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
		<< attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is already down!" << std::endl;
		return;
	}
	hitPoints = (amount >= hitPoints) ? 0 : (hitPoints - amount);
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage and now has "
		<< hitPoints << " hit points left." << std::endl;;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " has no hit points left and cannot be repaired!" << std::endl;
		return;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " has no energy points left and cannot be repaired!" << std::endl;
		return;
	}

	energyPoints--;
	hitPoints += amount;
	std::cout << "ClapTrap " << name << " repaired itself a bit by " << amount << " hitPoints. ";
	std::cout << "Now ClapTrap " << name << " has " << hitPoints << " hitPoints" << std::endl;
}

void ClapTrap::display(std::ostream& stream) const
{
	stream << "ClapTrap " << name << " has " << hitPoints << " hit points, " << energyPoints
		<< " energy points and " << attackDamage << " attack damage";
}

std::ostream&	operator<<(std::ostream& stream, ClapTrap const& clap)
{
	clap.display(stream);
	return (stream);
}
