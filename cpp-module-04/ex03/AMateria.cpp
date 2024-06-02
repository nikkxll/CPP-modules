/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:44:37 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/02 23:42:03 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("unknown")
{
	// std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const& type) : _type(type)
{
	// std::cout << "AMateria overload constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type)
{	
	// std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other) {}
	// std::cout << "AMateria copy assignment operator called" << std::endl;
	return *this;
}

AMateria::~AMateria()
{
	// std::cout << "AMateria default destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria " << getType() << " used on " << target.getName() << std::endl;
}