/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:56:52 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/30 14:23:56 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("unknown_clap_name"), name("unknown")
{
	this->energyPoints = 50;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"),
	ScavTrap(), FragTrap(), name(name)
{
	this->energyPoints = 50;
	std::cout << "DiamondTrap constructor overload called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other),
	FragTrap(other)
{
	name = other.name;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		name = other.name;
		ClapTrap::operator=(other);
	}
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My DiamondTrap name is: " << this->name << std::endl;
	std::cout << "My ClapTrap name is: " << ClapTrap::name << std::endl;
}

void DiamondTrap::display(std::ostream& stream) const
{
	stream << "DiamondTrap " << name << " has " << hitPoints << " hit points, " << energyPoints
		<< " energy points and " << attackDamage << " attack damage";
}

std::ostream& operator<<(std::ostream& stream, DiamondTrap const& clap)
{
	clap.display(stream);
	return (stream);
}