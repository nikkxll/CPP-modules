/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:25:01 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/13 00:03:04 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	// std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	// std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	if (this != &other) {}
	// std::cout << "Intern copy assignment operator called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	// std::cout << "PresidentialPardonForm default destructor called" << std::endl;
}

Form* Intern::makeForm(const std::string name, const std::string target)
{
    
}