/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:08:48 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/02 23:49:03 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	// std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	// std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
	if (this != &other) {}
	// std::cout << "Cure copy assignment operator called" << std::endl;
	return *this;
}

Cure::~Cure()
{
	// std::cout << "Cure default destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}